/*
 *  Created on: Apr 20, 2013
 *
 * Copyright 2013-2014 Jonas Zaddach <zaddach@eurecom.fr>, EURECOM
 *
 * You can redistribute and/or modify this program under the terms of the
 * GNU General Public License version 2 or later.
 */

#ifndef _AVATAR_HOST_INTERFACE_H
#define _AVATAR_HOST_INTERFACE_H

#include <stdint.h>

/**
 * This structure encapsulates data for the GDB serial protocol host interface.
 */
//TODO: This is GDB specific, move it
typedef struct
{
    uint8_t recv_checksum;
    uint8_t recv_error;
    uint8_t send_checksum;
    uint8_t send_error;
} HostInterfaceState;

typedef enum
{
    AVATAR_RPC_HTD_READ_MEMORY = 0x01,
    AVATAR_RPC_HTD_WRITE_MEMORY = 0x02,
    AVATAR_RPC_HTD_GET_REGISTER = 0x03,
    AVATAR_RPC_HTD_SET_REGISTER = 0x04,
    AVATAR_RPC_HTD_READ_UNTYPED_MEMORY = 0x05,
    AVATAR_RPC_HTD_WRITE_UNTYPED_MEMORY = 0x06,
    AVATAR_RPC_HTD_CODELET_EXECUTE = 0x07,

    AVATAR_RPC_HTD_INSERT_PAGE = 0x10,
    AVATAR_RPC_HTD_EXTRACT_PAGE = 0x11,
    AVATAR_RPC_HTD_UNMAP_PAGE = 0x12,
    AVATAR_RPC_HTD_SET_MEMORY_MAP = 0x13,
    AVATAR_RPC_HTD_GET_DIRTY_PAGES = 0x14,

    AVATAR_RPC_HTD_SET_EXCEPTION_CONFIG = 0x20,
    AVATAR_RPC_HTD_CLEAR_EXCEPTION = 0x21,

    AVATAR_RPC_HTD_ADD_EMULATED_INSTRUCTION = 0x30,
    AVATAR_RPC_HTD_CLEAR_EMULATED_INSTRUCTIONS = 0x31,

    AVATAR_RPC_HTD_RESUME_VM = 0x40,
    AVATAR_RPC_HTD_QUERY_STATE = 0x41,






    AVATAR_RPC_DTH_INFO_EXCEPTION = 0x80 + 0x20,
    AVATAR_RPC_DTH_STATE = 0x80 + 1,
    AVATAR_RPC_DTH_REPLY_STATE = 0x80 + 2,
    AVATAR_RPC_DTH_REPLY_OK = 0x80 + 0x31,
    AVATAR_RPC_DTH_REPLY_ERROR = 0x80 + 0x32,
    AVATAR_RPC_DTH_REPLY_READ_MEMORY = 0x80 + 0x10,
    AVATAR_RPC_DTH_REPLY_GET_REGISTER = 0x80 + 0x11,
    AVATAR_RPC_DTH_REPLY_EXTRACT_PAGE = 0x80 + 0x12,
    AVATAR_RPC_DTH_REPLY_READ_UNTYPED_MEMORY = 0x94,
    AVATAR_RPC_DTH_REPLY_CODELET_EXECUTION_FINISHED = 0x95,

    AVATAR_RPC_DTH_PAGEFAULT = 0xA4,
    AVATAR_RPC_HTD_CONTINUE_FROM_PAGEFAULT = 0x42,
    AVATAR_RPC_DTH_REPLY_GET_DIRTY_PAGES = 0x93


} AvatarRpcCommand;

typedef enum
{
	AVATAR_EXCEPTION_IRQ_FORWARD = 1,
	AVATAR_EXCEPTION_FIQ_FORWARD = 2,
	AVATAR_EXCEPTION_SVC_FORWARD = 4,
	AVATAR_EXCEPTION_UND_FORWARD = 8,
	AVATAR_EXCEPTION_DAB_FORWARD = 0x10,
	AVATAR_EXCEPTION_PAB_FORWARD = 0x20, /* TODO: How to do this? */
	AVATAR_EXCEPTION_IRQ_PRINT = 0x100,
	AVATAR_EXCEPTION_FIQ_PRINT = 0x200,
	AVATAR_EXCEPTION_SVC_PRINT = 0x400,
	AVATAR_EXCEPTION_UND_PRINT = 0x800,
	AVATAR_EXCEPTION_DAB_PRINT = 0x1000,
	AVATAR_EXCEPTION_PAB_PRINT = 0x2000, /* TODO: How to do this? */
	/* Disable IRQs and FIQs while in supervisor */
	AVATAR_EXCEPTION_INTERRUPTS_DISABLE = 0x10000,
} AvatarExceptionConfiguration;

typedef enum
{
    AVATAR_ERROR_NONE = 0,
    AVATAR_ERROR_CHECKSUM = 1,
    AVATAR_ERROR_OUT_OF_BOUNDS = 2,
    AVATAR_ERROR_NOT_FOUND = 3,
    AVATAR_ERROR_OUT_OF_MEMORY = 4
} AvatarError;

typedef enum
{
        AVATAR_VMSTATE_RUNNING =    0x01,
        AVATAR_VMSTATE_PAGE_MISS =  0x02,
        AVATAR_VMSTATE_BREAKPOINT = 0x04,
        AVATAR_VMSTATE_EMULATE_INSTRUCTION = 0x08,
        AVATAR_VMSTATE_EXCEPTION = 0x10
} AvatarVmState;

//TODO: ARM specific
typedef enum
{
    CPU_EXCEPTION_RST = 0,
    CPU_EXCEPTION_UND = 1,
    CPU_EXCEPTION_SVC = 2,
    CPU_EXCEPTION_PAB = 3,
    CPU_EXCEPTION_DAB = 4,
    CPU_EXCEPTION_IRQ = 6,
    CPU_EXCEPTION_FIQ = 7
} AvatarProcessorException;

// void Avatar_report_state(AvatarVmState state);
// void Avatar_report_exception(AvatarProcessorException exc);
// void Avatar_handle_incoming_command();

#endif /* _AVATAR_HOST_INTERFACE_H */