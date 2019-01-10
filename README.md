# MOSify

L’objectif de ce TP consiste à proposer un sous-agent SNMP permettant de superviser un flux audiovisuel transmis sur un réseau IP. Pour simplifier cette tâche, nous allons utiliser des fichiers pcap qui incluent des traces d’un flux des paquets UDP/RTP des sessions multimédia.
1.	Mesure de la QdE  
Il existe une large gamme d’outils de mesure de la qualité d’expérience. Dans le cadre de ce TP, nous allons utiliser les modèles proposés dans la recommandation ITU-T P.1201. Une implémentation open-source en Python est mise à votre disposition sur le share. 
-	Expliquer la valeur de MOS (Mean Opinion Score)
-	Identifier les contextes où les modèles de la recommandation ITU-T P.1201 sont utilisables
-	Ecrire un code en python permettant de calculer le MOS de chaque trace pcap incluent dans répertoire d’une façon périodique, une nouvelle trace est lue toutes les 20 msec.
Nous allons maintenant exposer les valeurs renvoyées par notre sonde de collecte à une station de supervision SNMP. Pour cela, il faut suivre les étapes suivantes :
-	La conception/intégration de la MIB
-	L’implémentation de la nouvelle MIB dans un sous-agent 
-	(Optionnel) L’implémentation d’une application de monitoring de MOS à base du SNMP
2.	La conception de la MIB de MOSIFY
La MIB à concevoir est structurée en deux branches, une pour la partie audio et une deuxième pour la partie vidéo. Les deux branches sont attachées au nœud « mosify » qui est un descendant du nœud « experimental » sous la branche numéro 2110.  
-	Commencer par créer une MIB nommée MOSIFY-MIB qui contient une déclare du module « mosify » sous la branche 2110 du nœud « experimental ».  
-	Vérifier la syntaxe de la MIB via le compilateur smilint. Utiliser un niveau de warning approprié pour limiter les avertissements inutiles. 
-	Placer la MIB dans un répertoire reconnu par SNMP puis vérifie que le client SNMP arrive à la reconnaître proprement via la commande snmptranslate  
Maintenant, nous allons créer une MIB nommée MOSIFY-AUDIO-MIB qui sera placée sous la branche 1 du nœud « mosify » qui contient des informations relatives aux flux audio. Pour cela, il faut bien ajouter le module « mosify » parmi les MIB importées. A partir de nœud « audioMOSify », nous allons créer un sous-arbre formé de 3 branches : audioNotifications (0), audioConfigInfo (1), audioMOSInfo (2).
-	Les notifications définies les types des alarmes qui sont transmises ainsi que les données à transmettre. Nous allons définir le nœud : « audioNotificationsObjects » sous la branche 0 de « audioNotifications ».  Ensuite, vous devez définir les deux objets suivants sous le nœud « audioNotificationsObjects » : (1) « audioTrapTime » et (2) « audioTrapData ». Enfin, définissez l’objet de type notification « audioMOSHit » sous le nœud « audioNotifications », branche 1.
-	Un tableau est utilisé pour sauver les informations sur la configuration d’un flux audio superviser. Expliquer ce choix ? Il est attaché au nœud « audioConfigInfo ». Une entrée sera composée de deux colonnes : (1) le nom de l’attribut qui sera l’index et (2) la valeur de l’attribut.
-	Les scores de MOS dus à la compression/total sont définis comme des objets scalaires de type Float64TC. Ils sont attachés au nœud « audioMOSInfo ».
De la même façon, créer une MIB nommée MOSIFY-VIDEO-MIB qui sera placée sous la branche 2 du nœud « mosify » pour la supervision d’un flux vidéo.
-	Vérifier que la syntaxe de la MIB est correcte via le compilateur smilint puis assurer que le client SNMP a bien intégré cette MIB dans sa base.

snmptranslate -Tp -IR agentxMOSify

3.	L’implémentation de la MIB avec mib2c (audio)
Nous allons développer le code permettant de faire la liaison entre les valeurs calculées par la sonde de mesure de QdE et l’agent SNMP. Pour cela, nous allons développer un sous-agent qui prendre en charge cette tâche. Le sous-agent va interagir avec l’agent maitre chaque fois l’OID maintenu par le sous-agent est sollicité. 
Pour nous assister à la création de ce programme, nous allons utiliser l’utilisateur mib2c qui va à partir de la spécification de la MIB fournie le squelette d’un programme. Vous pouvez s’inspirer de ce tutorial pour la création de notre sous-agent : https://github.com/jainvishal/agentx-tutorial.
a)	La création des objets de type tableau
Nous allons développer le code permettant de spécifier les métriques de configuration de la session multimédia. Créer un répertoire config dans lequel vous tapez la commande suivante :   
mib2c –c mib2c.mfd.conf audioConfigInfo 
Cela permettre d’auto-générer le squelette de l’objet audioConfigInfo. De la même façon, générer le Makefile puis le squelette du sous-agent SNMP via les deux commandes suivantes :
mib2c –c mfd-makefile.m2m audioConfigInfo
mib2c –c subagent.m2c audioConfigInfo 

Il est impératif de modifier le code avant qu’il soit opérationnel. 
1.	Nous allons définir un datastore où les données de configuration sont sauvegardées. Dans notre cas, nous allons utiliser le fichier /var/tmp/dummy.pre qui inclut des données sous forme de deux colonnes. La première colonne correspond au nom de la métrique, la deuxième colonne correspond à sa valeur
2.	Nous allons ajouter du code au fichier audioConfigTable_data_access.c
a.	Il faut mettre à jour audioConfigTable_init_data pour définir les colonnes qu’on va implémenter 
b.	Il faut modifier audioConfigTable_container_load pour qu’il lit les données externes /var/tmp/dummy.pre puis charge ses valeurs dans un conteneur interne. On doit créer au début l’indexe suivi par une copie de deuxième colonne. Cette fonction est appelé chaque fois le temporisateur expire qui est affecté à 60 sec      

Compiler le code du sous-agent puis
b)	La création des objets 
Nous allons créer les objets scalaires dans le répertoire mos. Les deux commandes à saisir sont les suivantes :
 
(1)	mib2c –c mib2c.scaral.conf agentxAudioMos

La première commande permet de générer les deux fichiers suivants : 
-	agentxAudioMos.c 
-	agentxAudioMos.h 
La deuxième commande permet de générer le fichier du programme principal du sous-agent nommé : 
-	agentxAudioMos_subagent.c 
Attention : Les fichiers générés doivent être édités pour que la compilation 
Maintenant, il faut instancier dans le fichier agentxAudioMos_subagent.c les deux variables scalaires MOSc et MOSa. Le sous-agent récupère les valeurs de ces métriques à partir d’un fichier nommée « audio.mos » placé dans /var/tmp. Il est mis à jour périodiquement par le point de collecte.
-	Dans le fichier agentxAudioMos_subagent.c écrire une fonction appelée AlrmHandler qui lit le fichier /var/tmp/audio.mos puis affecte les valeurs observées au variables MOSc et MOSa.
-	Dans le fichier agentxAudioMos.c, il faut déclarer les deux variables MOSc et MOSa avec la directive extern. Dans la fonction, handle_audioMOSC()  faire cela : snmp_set_var_typed_value(requets->requestvb,ASN_OCTET_STR, mosc, strlen(mosc)). Refaire la même chose avec handle_audioMOSA() 
Faire les modification necessaire dans le Makefile puis recompiler le sous-agent. Ajouter init_audioMOSify() pour l’initialisation
 
Lancer le sous agent puis vérifier son bon fonctionnement avec un snmpwalk

c)	La création des alarmes
Dans le dossier trap, taper la commande suivante :
mib2c –c mib2c.notify.conf agentxAudioMos

1.	Il faut éditer le fichier audioMOSify_traps.c
