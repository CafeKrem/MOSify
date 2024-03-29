/*
 * Note: this file originally auto-generated by mib2c
 * using mfd-top.m2c
 */
#ifndef AUDIOCONFIGTABLE_H
#define AUDIOCONFIGTABLE_H

#ifdef __cplusplus
extern "C" {
#endif


/** @addtogroup misc misc: Miscellaneous routines
 *
 * @{
 */
#include <net-snmp/library/asn1.h>

/* other required module components */
    /* *INDENT-OFF*  */
config_add_mib(MOSIFY-AUDIO-MIB)
config_require(MOSIFY-AUDIO-MIB/audioConfigTable/audioConfigTable_interface)
config_require(MOSIFY-AUDIO-MIB/audioConfigTable/audioConfigTable_data_access)
config_require(MOSIFY-AUDIO-MIB/audioConfigTable/audioConfigTable_data_get)
config_require(MOSIFY-AUDIO-MIB/audioConfigTable/audioConfigTable_data_set)
    /* *INDENT-ON*  */

/* OID and column number definitions for audioConfigTable */
#include "audioConfigTable_oids.h"

/* enum definions */
#include "audioConfigTable_enums.h"

/* *********************************************************************
 * function declarations
 */
void init_audioConfigTable(void);
void shutdown_audioConfigTable(void);

/* *********************************************************************
 * Table declarations
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table audioConfigTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * MOSIFY-AUDIO-MIB::audioConfigTable is subid 1 of audioConfigInfo.
 * Its status is Current.
 * OID: .1.3.6.1.3.79.1.1.1, length: 9
*/
/* *********************************************************************
 * When you register your mib, you get to provide a generic
 * pointer that will be passed back to you for most of the
 * functions calls.
 *
 * TODO:100:r: Review all context structures
 */
    /*
     * TODO:101:o: |-> Review audioConfigTable registration context.
     */
typedef netsnmp_data_list audioConfigTable_registration;

/**********************************************************************/
/*
 * TODO:110:r: |-> Review audioConfigTable data context structure.
 * This structure is used to represent the data for audioConfigTable.
 */
/*
 * This structure contains storage for all the columns defined in the
 * audioConfigTable.
 */
typedef struct audioConfigTable_data_s {
    
        /*
         * audioParamConfigValue(2)/DisplayString/ASN_OCTET_STR/char(char)//L/A/w/e/R/d/H
         */
   char   audioParamConfigValue[255];
size_t      audioParamConfigValue_len; /* # of char elements, not bytes */
    
} audioConfigTable_data;


/*
 * TODO:120:r: |-> Review audioConfigTable mib index.
 * This structure is used to represent the index for audioConfigTable.
 */
typedef struct audioConfigTable_mib_index_s {

        /*
         * audioParamConfigName(1)/DisplayString/ASN_OCTET_STR/char(char)//L/A/w/e/R/d/H
         */
        /** 128 - 0(other indexes) - oid length(11) = 116 */
   char   audioParamConfigName[116];
   size_t      audioParamConfigName_len;


} audioConfigTable_mib_index;

    /*
     * TODO:121:r: |   |-> Review audioConfigTable max index length.
     * If you KNOW that your indexes will never exceed a certain
     * length, update this macro to that length.
     *
     * BE VERY CAREFUL TO TAKE INTO ACCOUNT THE MAXIMUM
     * POSSIBLE LENGHT FOR EVERY VARIABLE LENGTH INDEX!
     * Guessing 128 - col/entry(2)  - oid len(9)
*/
#define MAX_audioConfigTable_IDX_LEN     117


/* *********************************************************************
 * TODO:130:o: |-> Review audioConfigTable Row request (rowreq) context.
 * When your functions are called, you will be passed a
 * audioConfigTable_rowreq_ctx pointer.
 */
typedef struct audioConfigTable_rowreq_ctx_s {

    /** this must be first for container compare to work */
    netsnmp_index        oid_idx;
    oid                  oid_tmp[MAX_audioConfigTable_IDX_LEN];
    
    audioConfigTable_mib_index        tbl_idx;
    
    audioConfigTable_data              data;

    /*
     * flags per row. Currently, the first (lower) 8 bits are reserved
     * for the user. See mfd.h for other flags.
     */
    u_int                       rowreq_flags;

    /*
     * TODO:131:o: |   |-> Add useful data to audioConfigTable rowreq context.
     */
    
    /*
     * storage for future expansion
     */
    netsnmp_data_list             *audioConfigTable_data_list;

} audioConfigTable_rowreq_ctx;

typedef struct audioConfigTable_ref_rowreq_ctx_s {
    audioConfigTable_rowreq_ctx *rowreq_ctx;
} audioConfigTable_ref_rowreq_ctx;

/* *********************************************************************
 * function prototypes
 */
    int audioConfigTable_pre_request(audioConfigTable_registration * user_context);
    int audioConfigTable_post_request(audioConfigTable_registration * user_context,
        int rc);

    int audioConfigTable_rowreq_ctx_init(audioConfigTable_rowreq_ctx *rowreq_ctx,
                                   void *user_init_ctx);
    void audioConfigTable_rowreq_ctx_cleanup(audioConfigTable_rowreq_ctx *rowreq_ctx);


    audioConfigTable_rowreq_ctx *
                  audioConfigTable_row_find_by_mib_index(audioConfigTable_mib_index *mib_idx);

extern const oid audioConfigTable_oid[];
extern const int audioConfigTable_oid_size;


#include "audioConfigTable_interface.h"
#include "audioConfigTable_data_access.h"
#include "audioConfigTable_data_get.h"
#include "audioConfigTable_data_set.h"

/*
 * DUMMY markers, ignore
 *
 * TODO:099:x: *************************************************************
 * TODO:199:x: *************************************************************
 * TODO:299:x: *************************************************************
 * TODO:399:x: *************************************************************
 * TODO:499:x: *************************************************************
 */

#ifdef __cplusplus
}
#endif

#endif /* AUDIOCONFIGTABLE_H */
/** @} */
