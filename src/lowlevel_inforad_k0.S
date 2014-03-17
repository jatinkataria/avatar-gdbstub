/*
 * Copyright 2013-2014 Jonas Zaddach <zaddach@eurecom.fr>, EURECOM
 *
 * You can redistribute and/or modify this program under the terms of the
 * GNU General Public License version 2 or later.
 */

    .global _start

    .extern _arm_PAB_handler
    .extern _arm_DAB_handler
	
	.arm
    .section .exception_table
_start:
		/* The exception vector table */
		b _reset /* RST */
		b .      /* UND */
		b .      /* SVC */
		ldr =_arm_PAB_handler /* PAB */
		ldr =_arm_DAB_handler /* DAB */
		nop /* Reserved */
		b . /* IRQ */
		b . /* FIQ */
		
	.arm
	.section .init
		
_reset:
		/* Set up stack */
		ldr sp, =0x60017ffc
        
        /* Hit breakpoint to allow GDB initialization */
		sub sp, sp, #0x50
		mov r0, #5
		mov r1, sp
		bl stub_handle_exception
        bx r3
	