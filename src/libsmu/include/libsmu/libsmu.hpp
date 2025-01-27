/**
 * Ryzen SMU Userspace Library
 * Copyright (C) 2020 Leonardo Gates <leogatesx9r@protonmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

#ifndef __LIB_SMU_H__
#define __LIB_SMU_H__

#include <stdio.h>
#include <string.h>
#include <pthread.h>

/* Version the loaded driver must use to be compatible. */
#define KERNEL_DRIVER_SUPP_VERS_COUNT 4
static char kernel_driver_supported_versions[KERNEL_DRIVER_SUPP_VERS_COUNT][10] = {
    "0.1.0",
    "0.1.1",
    "0.1.2",
    "0.1.5"
};

/**
 * SMU Mailbox Target
 */
enum smu_mailbox
{
    TYPE_RSMU,
    TYPE_MP1,
};

/**
 * Return values that can be sent from the SMU in response to a command.
 */
enum smu_return_val
{
    SMU_Return_OK                = 0x01,
    SMU_Return_Failed            = 0xFF,
    SMU_Return_UnknownCmd        = 0xFE,
    SMU_Return_CmdRejectedPrereq = 0xFD,
    SMU_Return_CmdRejectedBusy   = 0xFC,

    // Custom Error Code -- Does not exist in SMU.

    // SMU Management failed to respond within the SMU_TIMEOUT_MS range.
    SMU_Return_CommandTimeout    = 0xFB,
    // An invalid argument was sent to the function.
    SMU_Return_InvalidArgument   = 0xFA,
    // Function is unsupported on the current processor.
    SMU_Return_Unsupported       = 0xF9,
    // Insufficient buffer size specified.
    SMU_Return_InsufficientSize  = 0xF8,
    // Failed to map physical address.
    SMU_Return_MappedError       = 0xF7,

    // Userspace Library Codes

    // Driver is not currently loaded or inaccessible.
    SMU_Return_DriverNotPresent  = 0xF6,
    // Read or write error has occurred. Check errno for last error.
    SMU_Return_RWError           = 0xF5,
    // Driver version is incompatible.
    SMU_Return_DriverVersion     = 0xF4,
};

/**
 * Supported processor codenames with SMU capabilities.
 */
enum smu_processor_codename{
    CODENAME_UNDEFINED,
    CODENAME_COLFAX,
    CODENAME_RENOIR,
    CODENAME_PICASSO,
    CODENAME_MATISSE,
    CODENAME_THREADRIPPER,
    CODENAME_CASTLEPEAK,
    CODENAME_RAVENRIDGE,
    CODENAME_RAVENRIDGE2,
    CODENAME_SUMMITRIDGE,
    CODENAME_PINNACLERIDGE,

    // Not yet supported but still added for now.
    CODENAME_REMBRANT,
    CODENAME_VERMEER,
    CODENAME_VANGOGH,
    CODENAME_CEZANNE,
    CODENAME_MILAN,
    CODENAME_DALI,

    CODENAME_COUNT
};

/**
 * SMU MP1 Interface Version [v9-v13]
 */
enum smu_if_version_t
{
    IF_VERSION_9,
    IF_VERSION_10,
    IF_VERSION_11,
    IF_VERSION_12,
    IF_VERSION_13,
    IF_VERSION_COUNT
} ;

/**
 * Mutex lock enumeration for specific components.
 */
enum SMU_MUTEX_LOCK
{
    SMU_MUTEX_SMN,
    SMU_MUTEX_CMD,
    SMU_MUTEX_PM,
    SMU_MUTEX_COUNT
};

struct smu_obj_t
{
    /* Accessible To Users */
    int                         init;
    int                         driver_version;

    smu_processor_codename      codename;
    smu_if_version_t             smu_if_version;
    int                         smu_version;
    int                         pm_table_size;
    int                         pm_table_version;

    /* Internal Library Use Only */
    int                         fd_smn;
    int                         fd_rsmu_cmd;
    int                         fd_mp1_smu_cmd;
    int                         fd_smu_args;
    int                         fd_pm_table;

    pthread_mutex_t             lock[SMU_MUTEX_COUNT];
};

union smu_arg_t
{
    struct {
        float                   args0_f;
        float                   args1_f;
        float                   args2_f;
        float                   args3_f;
        float                   args4_f;
        float                   args5_f;
    } f;
    struct {
        unsigned int            args0;
        unsigned int            args1;
        unsigned int            args2;
        unsigned int            args3;
        unsigned int            args4;
        unsigned int            args5;
    } i;

    unsigned int                args[6];
    float                       args_f[6];
};

/**
 * Initializes or frees the userspace library for use.
 * Upon successful initialization, users are allowed to access
 *  codename, smu_version, pm_table_size and pm_table_version from
 *  the initialized structure.
 *
 * Returns SMU_Return_OK on success.
 */
smu_return_val smu_init(smu_obj_t* obj);
void smu_free(smu_obj_t* obj);

/**
 * Returns the string representation of the SMU FW version.
 */
const char* smu_get_fw_version(smu_obj_t* obj);

/**
 * Reads or writes a 32 bit word from the SMN address space.
 */
unsigned int smu_read_smn_addr(smu_obj_t* obj, unsigned int address, unsigned int* result);
smu_return_val smu_write_smn_addr(smu_obj_t* obj, unsigned int address, unsigned int value);

/**
 * Sends a command to the SMU.
 * Arguments are sent in the args buffer and are also returned in it.
 * 
 * Returns SMU_Return_OK on success.
 */
smu_return_val smu_send_command(smu_obj_t* obj, unsigned int op, smu_arg_t args,
    enum smu_mailbox mailbox);

/**
 * Reads the PM table into the destination buffer.
 * 
 * Returns an SMU_Return_OK on success.
 */
smu_return_val smu_read_pm_table(smu_obj_t* obj, unsigned char* dst, size_t dst_len);

/** HELPER METHODS **/

/**
 * Converts SMU values to the string representation.
 */
const char* smu_return_to_str(smu_return_val val);
const char* smu_codename_to_str(smu_obj_t* obj);

/**
 * Determines whether PM tables are supported.
 * Returns 1 if they are.
 */
unsigned int smu_pm_tables_supported(smu_obj_t* obj);

#endif /* __LIB_SMU_H__ */
