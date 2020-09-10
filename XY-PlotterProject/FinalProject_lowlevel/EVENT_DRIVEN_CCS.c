/*
*************************** C SOURCE FILE ************************************

project   :
filename  : EVENT_DRIVEN_CCS.C
version   : 2
date      :

******************************************************************************

Copyright (c) 20xx
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

#define EVENT_DRIVEN_CCS_C_SRC

/****************************************************************************/
/**                                                                        **/
/**                             MODULES USED                               **/
/**                                                                        **/
/****************************************************************************/

#include "EVENT_DRIVEN_CCS.h"

/****************************************************************************/
/**                                                                        **/
/**                        DEFINITIONS AND MACROS                          **/
/**                                                                        **/
/****************************************************************************/


/****************************************************************************/
/**                                                                        **/
/**                        TYPEDEFS AND STRUCTURES                         **/
/**                                                                        **/
/****************************************************************************/


/****************************************************************************/
/**                                                                        **/
/**                      PROTOTYPES OF LOCAL FUNCTIONS                     **/
/**                                                                        **/
/****************************************************************************/


/****************************************************************************/
/**                                                                        **/
/**                           EXPORTED VARIABLES                           **/
/**                                                                        **/
/****************************************************************************/

volatile int16u EvQFullCount = 0;

/****************************************************************************/
/**                                                                        **/
/**                            GLOBAL VARIABLES                            **/
/**                                                                        **/
/****************************************************************************/


/****************************************************************************/
/**                                                                        **/
/**                           EXPORTED FUNCTIONS                           **/
/**                                                                        **/
/****************************************************************************/

/****************************************************************************/
//							Library Functions
/****************************************************************************/

/***************************************************************************/
//							Event Queue Functions
/***************************************************************************/
void EvStructInit (EV_STRUCT *evStruct, EV_TYPE evType, void *evDataPtr)
{
	evStruct->evType = evType;
	evStruct->evDataPtr = evDataPtr;
}

void EvQInit (EVQ_STRUCT *evQ, EV_STRUCT *evArray, int8u qL)
{
	evQ->evQLength = qL;
	evQ->evQCount = 0;
	evQ->evQPut = 0;
	evQ->evQGet = 0;
	evQ->evQArray = evArray;
}

void EvQPut (EVQ_STRUCT *evQ, EV_STRUCT evSource, Q_ERR *errPtr)
{
	if (evQ->evQCount == evQ->evQLength)
	{
		*errPtr = EVQ_FULL;
	}
	else
	{
		evQ->evQCount++;
		evQ->evQArray[evQ->evQPut] = evSource;
		evQ->evQPut ++ ;
		if (evQ->evQPut == evQ->evQLength)
		{
			evQ->evQPut = 0;
		}
		*errPtr = EVQ_OK;
	}
}

void EvQGet (EVQ_STRUCT *evQ, EV_STRUCT *evDest, Q_ERR *errPtr)
{
	EV_STRUCT tempEvDest;
	if (evQ->evQCount == 0)
	{
		*errPtr = EVQ_EMPTY;
	}
	else
	{
		evQ->evQCount--;
		tempEvDest = evQ->evQArray[evQ->evQGet];
		*evDest = tempEvDest;
		evQ->evQGet++;
		if (evQ->evQGet == evQ->evQLength)
		{
			evQ->evQGet = 0;
		}
		*errPtr = EVQ_OK;
	}
}

int16u EvQCount (EVQ_STRUCT *evQ)
{
	return evQ->evQCount;
}

/***************************************************************************/
//							Memory Functions
/***************************************************************************/

void MemStructArrayInit (void *memArrayPtr, int16u blockByteSize, int16u nBlock, PTR_STRUCT *memQArrayPtr, MCB_STRUCT *memQcbPtr)
{
	int16u i;
	for (i=0; i < nBlock; i++)
	{
		memQArrayPtr[i].blockPtr = (void *)((int8u *)memArrayPtr + (blockByteSize * i));		
	}
	memQcbPtr->memPtr = memArrayPtr;
	memQcbPtr->qArrayLength = nBlock;
	memQcbPtr->count = nBlock;
	memQcbPtr->put = 0;
	memQcbPtr->get = 0;
	memQcbPtr->qArrayPtr = memQArrayPtr;
}

void MemPtrPut (MCB_STRUCT *memQcbPtr, void *memBlockPtr, int8u *errPtr)
{
	if (memQcbPtr->count == memQcbPtr->qArrayLength)
	{
		*errPtr = Q_FULL;
	}
	else
	{
		memQcbPtr->count++;
		memQcbPtr->qArrayPtr[memQcbPtr->put].blockPtr = memBlockPtr;
		memQcbPtr->put++;
		if (memQcbPtr->put == memQcbPtr->qArrayLength)
		{
			memQcbPtr->put = 0;
		}
		*errPtr = 0;
	}
}

void MemPtrGet (MCB_STRUCT *memQcbPtr, PTR_STRUCT *destStructPtr, int8u *errPtr)
{
	if (memQcbPtr->count == 0)
	{
		destStructPtr->blockPtr = (void *)NULL;
		*errPtr = Q_EMPTY;
	}
	else
	{
		memQcbPtr->count --;
		destStructPtr->blockPtr = memQcbPtr->qArrayPtr[memQcbPtr->get].blockPtr;
		memQcbPtr->get++;
		if (memQcbPtr->get == memQcbPtr->qArrayLength)
		{
			memQcbPtr->get = 0;
		}
		*errPtr = Q_OK;
	}
}

int16u MemQReadyCount (MCB_STRUCT *memQcbPtr)
{
	return memQcbPtr->count;
}

/***************************************************************************/
//							QPTRX Functions
/***************************************************************************/

void QPtrXInit (QPTRX_STRUCT *qStructPtr, PTR_STRUCT *buffPtr, int16u qL)
{
	qStructPtr->arrayLength = qL;
	qStructPtr->count = 0;
	qStructPtr->put = 0;
	qStructPtr->get = 0;
	qStructPtr->arrayPtr = buffPtr;
}

void QPtrXPut (QPTRX_STRUCT *qStructPtr, PTR_STRUCT ptrStruct, int8u *errPtr)
{
	if (qStructPtr->count == qStructPtr->arrayLength)
	{
		*errPtr = Q_FULL;
	}
	else
	{
		qStructPtr->count++;
		qStructPtr->arrayPtr[qStructPtr->put] = ptrStruct;
		qStructPtr->put++;
		if (qStructPtr->put == qStructPtr->arrayLength)
		{
			qStructPtr->put = 0;
		}
		*errPtr = Q_OK;
	}
}

void QPtrXGet (QPTRX_STRUCT *qStructPtr, PTR_STRUCT *destPtr, int8u *errPtr)
{
	if (qStructPtr->count == 0)
	{
		*errPtr = Q_EMPTY;
	}
	else
	{
		qStructPtr->count--;
		destPtr->blockPtr = qStructPtr->arrayPtr[qStructPtr->get].blockPtr;
		qStructPtr->get++;
		if (qStructPtr->get == qStructPtr->arrayLength)
		{
			qStructPtr->get = 0;
		}
		*errPtr = Q_OK;
	}
}

int16u QPtrXCount (QPTRX_STRUCT *qStructPtr)
{
	return qStructPtr->count;
}

/***************************************************************************/
//							Q8UX Functions
/***************************************************************************/

void Q8UXInit (Q8UX_STRUCT *qStructPtr, int8u *buffPtr, int16u qL)
{
	qStructPtr->arrayLength = qL;
	qStructPtr->count = 0;
	qStructPtr->put = 0;
	qStructPtr->get = 0;
	qStructPtr->arrayPtr = buffPtr;
}

void Q8UXPut (Q8UX_STRUCT *qStructPtr, int8u dataSource, int8u *errPtr)
{
	if (qStructPtr->count == qStructPtr->arrayLength)
	{
		*errPtr = Q_FULL;
	}
	else
	{
		qStructPtr->count ++;
		qStructPtr->arrayPtr[qStructPtr->put] = dataSource;
		qStructPtr->put++;
		if (qStructPtr->put == qStructPtr->arrayLength)
		{
			qStructPtr->put = 0;
		}
		*errPtr = Q_OK;
	}
}

void Q8UXGet (Q8UX_STRUCT *qStructPtr, int8u *destPtr, int8u *errPtr)
{
	if (qStructPtr->count == 0)
	{
		*errPtr = Q_EMPTY;
	}
	else
	{
		qStructPtr->count--;
		*destPtr = qStructPtr->arrayPtr[qStructPtr->get];
		qStructPtr->get++;
		if(qStructPtr->get == qStructPtr->arrayLength)
		{
			qStructPtr->get = 0;
		}
		*errPtr = 0;
	}
}

int16u Q8UXCount (Q8UX_STRUCT *qStructPtr)
{
	return qStructPtr->count;
}

/***************************************************************************/
//							Q8UX Functions
/***************************************************************************/

void SoftwareTimer (STMR_STRUCT *sTmrPtr, int8u nMaxSTmr)
{
	int8u k;
	Q_ERR err;
	for (k=0 ; k < nMaxSTmr; k++)
	{
		if (sTmrPtr[k].tmrEnb == ON)
		{
			sTmrPtr[k].tmrCount--;
			if (sTmrPtr[k].tmrCount == 0)
			{
				EvQPut (sTmrPtr[k].evQPtr, sTmrPtr[k].sTmrEvStruct, &err);
				if (err == EVQ_FULL)
				{
					EvQFullCount ++;
				}
				sTmrPtr[k].tmrCount = sTmrPtr[k].tmrInit;
				if (sTmrPtr[k].tmrMode == SINGLE)
				{
					sTmrPtr[k].tmrEnb = OFF;
				}
			}
		}
	}
}

/*****************************************************************************/

void STmrSystemDeInit (STMR_STRUCT *sTmrPtr, int8u nMaxSTmr)
{
	int8u k;
	for (k=0; k<nMaxSTmr; k++)
	{
		sTmrPtr[k].tmrEnb = OFF;
		sTmrPtr[k].evQPtr = NULL;
	}
}

/*****************************************************************************/

void STmrInit (STMR_STRUCT *sTmrPtr, int8u z, tickType initValue, int8u mode, EV_TYPE evType, void *evDataPtr, EVQ_STRUCT *evQPtr)
{
	sTmrPtr[z].tmrEnb = OFF;
	sTmrPtr[z].tmrMode = mode;
	sTmrPtr[z].tmrInit = initValue;
	sTmrPtr[z].tmrCount = initValue;
	sTmrPtr[z].evQPtr = evQPtr;
	EvStructInit (&(sTmrPtr[z].sTmrEvStruct), evType, evDataPtr);
}

/*****************************************************************************/

void STmrStart (STMR_STRUCT *sTmrPtr, int8u z)
{
	Q_ERR err;
	if (sTmrPtr[z].tmrEnb == OFF)
	{
		if (sTmrPtr[z].tmrCount != 0)
		{
			sTmrPtr[z].tmrEnb = ON;
		}
		else
		{
			EvQPut (sTmrPtr[z].evQPtr, sTmrPtr[z].sTmrEvStruct, &err);
			if (err == EVQ_FULL)
			{
				EvQFullCount++;
			}
		}
	}
}

/*****************************************************************************/

void STmrPause (STMR_STRUCT *sTmrPtr, int8u z)
{
	(sTmrPtr + z)->tmrEnb = OFF;
}
/*****************************************************************************/

void STmrStop (STMR_STRUCT *sTmrPtr, int8u z)
{
	sTmrPtr[z].tmrEnb = OFF;
	sTmrPtr[z].tmrCount = sTmrPtr[z].tmrInit;
}
/*****************************************************************************/

/*****************************************************************************/
//								CPU Dependent Functions
/*****************************************************************************/

void DisableIntr(void)
{
	disable_interrupts (INTR_GLOBAL);
}

void EnableIntr(void)
{
	enable_interrupts (INTR_GLOBAL);
}

void CpuIdle (void)
{
}


/****************************************************************************/
/**                                                                        **/
/**                             LOCAL FUNCTIONS                            **/
/**                                                                        **/
/****************************************************************************/


/****************************************************************************/

/****************************************************************************/
/**                                                                        **/
/**                                 EOF                                    **/
/**                                                                        **/
/****************************************************************************/