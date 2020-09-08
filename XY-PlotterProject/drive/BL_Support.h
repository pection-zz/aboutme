/******************************************************************************/
/* File:    BL_Support.h													  */
/* Author:  Dr.Santi Nuratch												  */
/*          Embedded Computing and Control Lab., INC-KMUTT 				      */
/* Created on 22 September 2016, 13:14										  */
/******************************************************************************/

#ifndef BL_SUPPORT_H
#define	BL_SUPPORT_H

/******************************************************************************/
/*                   BOOTLOADER SUPPORT CONFIGURATION                         */
/*                          (DO NOT CHANGE)                                   */
/******************************************************************************/
/* Bootloader */
#define LOADER_PAGES 	3 
#define ERASE_SIZE 		2048    /* 2048 bytes, 24-bit (3 bytes) per instruction, but it uses 4 bytes aligned --> 4 bytes per word */
                                /* each block has 512 instructions (1024 words), each instruction requires 4 bytes (2 words), so 512*4 = 2048 bytes */
#define LOADER_SIZE 	((LOADER_PAGES * (ERASE_SIZE/2)) - 1)   /* 2 bytes per address, so divided by 2, 2048/2 = 1024 */ 
#define LOADER_END  	LOADER_SIZE                             /* End address      */
#define LOADER_ADDR 	0xC00//(LOADER_END - LOADER_SIZE)       /* Start address    */

#build (reset=LOADER_END+1, interrupt=LOADER_END+5)
#org 0, LOADER_END {}   /* 0x0000 - END */

/******************************************************************************/
/*                                  END                                       */
/******************************************************************************/

#endif	/* BL_SUPPORT_H */

