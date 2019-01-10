/*
 * Note: this file originally auto-generated by mib2c
 * using mfd-top.m2c
 */
/** \page MFD helper for audioConfigTable
 *
 * \section intro Introduction
 * Introductory text.
 *
 */
/* standard Net-SNMP includes */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-features.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

/* include our parent header */
#include "audioConfigTable.h"

#include <net-snmp/agent/mib_modules.h>

#include "audioConfigTable_interface.h"

const oid audioConfigTable_oid[] = { AUDIOCONFIGTABLE_OID };
const int audioConfigTable_oid_size = OID_LENGTH(audioConfigTable_oid);

    audioConfigTable_registration  audioConfigTable_user_context;

void initialize_table_audioConfigTable(void);
void shutdown_table_audioConfigTable(void);


/**
 * Initializes the audioConfigTable module
 */
void
init_audioConfigTable(void)
{
    DEBUGMSGTL(("verbose:audioConfigTable:init_audioConfigTable","called\n"));

    /*
     * TODO:300:o: Perform audioConfigTable one-time module initialization.
     */
     
    /*
     * here we initialize all the tables we're planning on supporting
     */
    if (should_init("audioConfigTable"))
        initialize_table_audioConfigTable();

} /* init_audioConfigTable */

/**
 * Shut-down the audioConfigTable module (agent is exiting)
 */
void
shutdown_audioConfigTable(void)
{
    if (should_init("audioConfigTable"))
        shutdown_table_audioConfigTable();

}

/**
 * Initialize the table audioConfigTable 
 *    (Define its contents and how it's structured)
 */
void
initialize_table_audioConfigTable(void)
{
    audioConfigTable_registration * user_context;
    u_long flags;

    DEBUGMSGTL(("verbose:audioConfigTable:initialize_table_audioConfigTable","called\n"));

    /*
     * TODO:301:o: Perform audioConfigTable one-time table initialization.
     */

    /*
     * TODO:302:o: |->Initialize audioConfigTable user context
     * if you'd like to pass in a pointer to some data for this
     * table, allocate or set it up here.
     */
    /*
     * a netsnmp_data_list is a simple way to store void pointers. A simple
     * string token is used to add, find or remove pointers.
     */
    user_context = netsnmp_create_data_list("audioConfigTable", NULL, NULL);
    
    /*
     * No support for any flags yet, but in the future you would
     * set any flags here.
     */
    flags = 0;
    
    /*
     * call interface initialization code
     */
    _audioConfigTable_initialize_interface(user_context, flags);
} /* initialize_table_audioConfigTable */

/**
 * Shutdown the table audioConfigTable 
 */
void
shutdown_table_audioConfigTable(void)
{
    /*
     * call interface shutdown code
     */
    _audioConfigTable_shutdown_interface(&audioConfigTable_user_context);
}

/**
 * extra context initialization (eg default values)
 *
 * @param rowreq_ctx    : row request context
 * @param user_init_ctx : void pointer for user (parameter to rowreq_ctx_allocate)
 *
 * @retval MFD_SUCCESS  : no errors
 * @retval MFD_ERROR    : error (context allocate will fail)
 */
int
audioConfigTable_rowreq_ctx_init(audioConfigTable_rowreq_ctx *rowreq_ctx,
                           void *user_init_ctx)
{
    DEBUGMSGTL(("verbose:audioConfigTable:audioConfigTable_rowreq_ctx_init","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);
    
    /*
     * TODO:210:o: |-> Perform extra audioConfigTable rowreq initialization. (eg DEFVALS)
     */

    return MFD_SUCCESS;
} /* audioConfigTable_rowreq_ctx_init */

/**
 * extra context cleanup
 *
 */
void audioConfigTable_rowreq_ctx_cleanup(audioConfigTable_rowreq_ctx *rowreq_ctx)
{
    DEBUGMSGTL(("verbose:audioConfigTable:audioConfigTable_rowreq_ctx_cleanup","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);
    
    /*
     * TODO:211:o: |-> Perform extra audioConfigTable rowreq cleanup.
     */
} /* audioConfigTable_rowreq_ctx_cleanup */

/**
 * pre-request callback
 *
 *
 * @retval MFD_SUCCESS              : success.
 * @retval MFD_ERROR                : other error
 */
int
audioConfigTable_pre_request(audioConfigTable_registration * user_context)
{
    DEBUGMSGTL(("verbose:audioConfigTable:audioConfigTable_pre_request","called\n"));

    /*
     * TODO:510:o: Perform audioConfigTable pre-request actions.
     */

    return MFD_SUCCESS;
} /* audioConfigTable_pre_request */

/**
 * post-request callback
 *
 * Note:
 *   New rows have been inserted into the container, and
 *   deleted rows have been removed from the container and
 *   released.
 *
 * @param user_context
 * @param rc : MFD_SUCCESS if all requests succeeded
 *
 * @retval MFD_SUCCESS : success.
 * @retval MFD_ERROR   : other error (ignored)
 */
int
audioConfigTable_post_request(audioConfigTable_registration * user_context, int rc)
{
    DEBUGMSGTL(("verbose:audioConfigTable:audioConfigTable_post_request","called\n"));

    /*
     * TODO:511:o: Perform audioConfigTable post-request actions.
     */

    return MFD_SUCCESS;
} /* audioConfigTable_post_request */


/** @{ */