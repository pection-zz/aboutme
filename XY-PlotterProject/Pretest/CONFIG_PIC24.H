/*
*************************** C HEADER FILE ************************************

project   :
filename  : CONFIG_PIC24.H
version   : 
date      :

******************************************************************************
*/

#ifndef  CONFIG_PIC24_INCLUDED
#define  CONFIG_PIC24_INCLUDED

/****************************************************************************/
/**                                                                        **/
/**                              MODULES USED                              **/
/**                                                                        **/
/****************************************************************************/
#include <24FJ48GA002.H>
//#include <24FJ16GA002.H>
/****************************************************************************/
/**                                                                        **/
/**                        DEFINITIONS AND MACROS                          **/
/**                                                                        **/
/****************************************************************************/

#DEVICE ADC=10
#fuses NOIOL1WAY, NODEBUG, NOWRT, NOPROTECT, NOJTAG, NOWDT
#fuses OSCIO
#fuses FRC_PLL
#case
#type signed
#use delay(internal=8 MHz, clock = 32000000) 
#use fast_io(ALL)
#pin_select U1TX = PIN_B13
#pin_select U1RX = PIN_B12
#use RS232 (UART1, BAUD = 115200, XMIT = PIN_B13, RCV = PIN_B12, STREAM = COM_A)
#BIT TX1IF = 0x0084.12  // Tx1 Interrupt flag  IFS0.12

//////////////////////////////////////////////////
// EXT INT pins
#if 1
// INT0 is RB7
#pin_select INT1 = PIN_B6
//#pin_select INT2 = PIN_B5

#endif
//////////////////////////////////////////////////
#if 0

#pin_select U2TX = PIN_B10
#pin_select U2RX = PIN_B11

//#use RS232 (UART2, BAUD = 9600, XMIT = PIN_B9, RCV = PIN_B8, STREAM = COM_B)
//#use RS232 (BAUD = 9600, XMIT = PIN_B10, RCV = PIN_B11, STREAM = COM_B)

#endif
//////////////////////////////////////////////////
// REMAP i/o pins
#if 1

#pin_select OC1 = PIN_B2  // RP0  AX2
#pin_select IC1 = PIN_B4  // RP1  AX3
#pin_select IC2 = PIN_B5

#endif
//////////////////////////////////////////////////

#include <stdlib.h>  
#include <stdio.h>
#include <stdlibm.h>
#include <string.h>
#include <stdint.h>
//#include "BL_support.h"
/****************************************************************************/
// o/p pins  LED
#define  LED0  PIN_A2
#define  LED1  PIN_A4
#define  LED2  PIN_B2
#define  LED3  PIN_B3

// i/p pins  PBSW
#define  SW0  PIN_B4
#define  SW1  PIN_B5
#define  SW2  PIN_B6
#define  SW3  PIN_B7

// ADC  or  i/o pins if not use ADC
#define  AX0  PIN_A0
#define  AX1  PIN_A1
#define  AX2  PIN_B0  // RP0 remap pin
#define  AX3  PIN_B1  // RP1 remap pin

/****************************************************************************/

#endif
/****************************************************************************/
/**                                                                        **/
/**                              EOF                                       **/
/**                                                                        **/
/****************************************************************************/


