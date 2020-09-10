/*
*************************** C HEADER FILE ************************************

project   :
filename  : EVENT_DRIVEN_CCS.H
version   : 2
date      :

******************************************************************************

Copyright (c) 20xx ,
All rights reserved.

******************************************************************************

VERSION HISTORY:
----------------------------
Version      : 1
Date         :
Revised by   :
Description  :

Version      : 2
Date         :
Revised by   :
Description  : *
               *
               *

******************************************************************************
*/

#ifndef  EVENT_DRIVEN_CCS_INCLUDED
#define  EVENT_DRIVEN_CCS_INCLUDED

/****************************************************************************/
/**                                                                        **/
/**                              MODULES USED                              **/
/**                                                                        **/
/****************************************************************************/

#include "CONFIG_PIC24.h"
#include "CDATPIC24.h"
#include "EVENT_TYPE_CCS.h"
//#include <stdlib.h>  // depend on application requirements.
//#include "cdat68k.h"  // define data types

/****************************************************************************/
/**                                                                        **/
/**                        DEFINITIONS AND MACROS                          **/
/**                                                                        **/
/****************************************************************************/
#define DECLARE_MEM(BLOCK_TYPE_DEF , MEM_ARRAY, STRUCT_Q_ARRAY, N_BLOCK);\
PTR_STRUCT STRUCT_Q_ARRAY[N_BLOCK]; \
BLOCK_TYPE_DEF MEM_ARRAY[N_BLOCK];

/****************************************************************************/
// Queue error code
#define Q_OK 0
#define Q_FULL 1
#define Q_EMPTY 2

#define SINGLE 0
#define REPEAT 1

#define ON 1
#define OFF 0

/****************************************************************************/
/**                                                                        **/
/**                        TYPEDEFS AND STRUCTURES                         **/
/**                                                                        **/
/****************************************************************************/
// Data type for Tick counter
typedef volatile int32u tickType;

//Event structure
typedef volatile struct 
{
	EV_TYPE evType;
	void *evDataPtr;
} EV_STRUCT;

typedef volatile struct 
{
	int8u evQLength;
	int8u evQCount;
	int8u evQPut;
	int8u evQGet;
	EV_STRUCT *evQArray;
}EVQ_STRUCT;

// Event Queue function error codes
typedef enum
{
	EVQ_OK,
	EVQ_FULL,
	EVQ_EMPTY
} Q_ERR;

// Struct of pointer for mem qeue array 
typedef volatile struct voidPtrStruct
{
	void *blockPtr;
} PTR_STRUCT;

// Structure type for Mem Control Block
typedef volatile struct memControlStruct
{
	void *memPtr;
	int16u qArrayLength;
	int16u count;
	int16u put;
	int16u get;
	PTR_STRUCT *qArrayPtr; // Pointer to array of pointer to void
	
} MCB_STRUCT;

// struct type for queue of pointer
typedef volatile struct qPtrXStruct
{
	int16u arrayLength;
	int16u count;
	int16u put;
	int16u get;
	PTR_STRUCT *arrayPtr; // Pointer to array of pointer to void
} QPTRX_STRUCT;

// struct type for queue of int8u
typedef volatile struct q8UStruct
{
	int16u arrayLength;
	int16u count;
	int16u put;
	int16u get;
	int8u *arrayPtr; // Pointer to array of int8u	
} Q8UX_STRUCT;

//STimer struct
typedef volatile struct 
{
	int8u tmrEnb; //enable (ON) / disable (OFF) software timer
	int8u tmrMode; // Opareting mode : SINGLE / REPEAT
	tickType tmrInit; // Initial value of tick count
	tickType tmrCount; // Down counter value
	EVQ_STRUCT *evQPtr; // Pointer to event queue
	EV_STRUCT sTmrEvStruct; // Software Timer Event  Struct 
} STMR_STRUCT;

// RX Frame State
typedef volatile enum 
{
	FRAME_WAIT,
	FRAME_PROGRESS
} FRAME_STATE;

// Tx State
typedef volatile enum 
{
	TX1_BUSY,
	TX1_READY
} TX1_STATUS;  
/****************************************************************************/
/**                                                                        **/
/**                         EXPORTED VARIABLES                             **/
/**                                                                        **/
/****************************************************************************/

#ifndef EVENT_DRIVEN_CCS_C_SRC
extern volatile int16u EvQFullCount;
#endif

/****************************************************************************/
/**                                                                        **/
/**                       EXPORTED FUNCTIONS                               **/
/**                                                                        **/
/****************************************************************************/

/****************************************************************************/
//							Library Functions
/****************************************************************************/

/****************************************************************************/
//							Event Queue Functions
/****************************************************************************/
void EvStructInit (EVQ_STRUCT *evStruct, EV_TYPE evType, void *evDataPtr);

void EvQInit (EVQ_STRUCT *evQ, EV_STRUCT *evArray, int8u qL);

void EvQPut (EVQ_STRUCT *evQ, EV_STRUCT evSource, Q_ERR *errPtr);

void EvQGet (EVQ_STRUCT *evQ, EV_STRUCT *evDest, Q_ERR *errPtr);

int16u EVQCount (EVQ_STRUCT *evQ);
/****************************************************************************/

/****************************************************************************/
//								Memory Functions 
/****************************************************************************/

void MemStructArrayInit (void *memArrayPtr, int16u blockByteSize, int16u nblock, PTR_STRUCT *memQArrayPtr, MCB_STRUCT *memQcbPtr);

void MemPtrPut (MCB_STRUCT *memQcbPtr, void *memBlockPtr, int8u *errPtr);

void MemPtrGet (MCB_STRUCT *memQcbPtr, PTR_STRUCT *destStructPtr, int8u *errPtr);

int16u MemQReadyCount (MCB_STRUCT *memQcbPtr);
/****************************************************************************/

/****************************************************************************/
//								QPTXR Functions 
/****************************************************************************/
void QPtrXInit (QPTRX_STRUCT *qStructPtr, PTR_STRUCT *buffPtr, int16u qL);

void QPtrXPut (QPTRX_STRUCT *qStructPtr, PTR_STRUCT ptrStruct, int8u *errPtr);

void QPtrXGet (QPTRX_STRUCT *qStructPtr, PTR_STRUCT *destPtr, int8u *errPtr);

int16u QPtrXCount (QPTRX_STRUCT *qStructPtr);


/****************************************************************************/

/****************************************************************************/
//								Q8UX Functions 
/****************************************************************************/

void Q8UXInit (Q8UX_STRUCT *qStructPtr, int8u *buffPtr, int16u qL);

void Q8UXPut (Q8UX_STRUCT *qStructPtr, int8u dataSource, int8u *errPtr);

void Q8UXGet (Q8UX_STRUCT *qStructPtr, int8u *destPtr, int8u *errPtr);

int16u Q8UXCount (Q8UX_STRUCT *qStructPtr);

/****************************************************************************/

/****************************************************************************/
//								Software  Timer Function
/****************************************************************************/

void SoftwareTimer (STMR_STRUCT *sTmrPtr, int8u nMaxSTmr);

void STmrSystemDeInit (STMR_STRUCT *sTmrPtr, int8u nMaxSTmr);

void STmrInit (STMR_STRUCT *sTmrPtr, int8u z, tickType initValue, int8u mode, EV_TYPE evType, void *evDataPtr, EVQ_STRUCT *evQPtr);

void STmrStart (STMR_STRUCT *sTmrPtr, int8u z);

void STmrPause (STMR_STRUCT *sTmrPtr, int8u z);

void STmrStop (STMR_STRUCT *sTmrPtr, int8u z);	

/****************************************************************************/

/****************************************************************************/
//								CPU Dependent Functions
/****************************************************************************/

void DisableIntr (void);

void EnableIntr (void);

void CpuIdle (void);

/****************************************************************************/

/****************************************************************************/
/**                                                                        **/
/**                              EOF                                       **/
/**                                                                        **/
/****************************************************************************/