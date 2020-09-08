/*
*************************** C SOURCE FILE ************************************

project   :
filename  : CTEMPLATE.C
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

#define PIC24_SCAN_DEBOUNCE_SW_C_SRC

/****************************************************************************/
/**                                                                        **/
/**                             MODULES USED                               **/
/**                                                                        **/
/****************************************************************************/

#include "PIC24_SCAN_DEBOUNCE_SW.H"

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

typedef enum 
{
	KEY_IDLE,
	KEY_PRESS,
	KEY_CONFIRM
}KEY_STATE;

/****************************************************************************/
/**                                                                        **/
/**                      PROTOTYPES OF LOCAL FUNCTIONS                     **/
/**                                                                        **/
/****************************************************************************/

static void ReadKey(int8u inPort);
static void SendEventKeyPress(EVQ_STRUCT *evQPtr);

/****************************************************************************/
/**                                                                        **/
/**                           EXPORTED VARIABLES                           **/
/**                                                                        **/
/****************************************************************************/

EV_STRUCT Sw0EvStruct,Sw1EvStruct,Sw2EvStruct,Sw3EvStruct;
EV_STRUCT Sw4EvStruct,Sw5EvStruct,Sw6EvStruct,Sw7EvStruct;

/****************************************************************************/
/**                                                                        **/
/**                            GLOBAL VARIABLES                            **/
/**                                                                        **/
/****************************************************************************/

static int8u KeyCount,OldKey,NewKey,ConfirmKey;

/****************************************************************************/
/**                                                                        **/
/**                           EXPORTED FUNCTIONS                           **/
/**                                                                        **/
/****************************************************************************/

int8u ReadKeyPort()
{
	int8u inPort;
	inPort = ((int8u)(input_b() & 0x00f0) >> 4);
	return inPort;
}

void ScanAndDebounceSW(int8u inPortValue,EVQ_STRUCT *evQueuePtr)
{
	static KEY_STATE KeyState=KEY_IDLE;
	ReadKey (inPortValue);
	switch (KeyState)
	{
		case KEY_IDLE:
			if(KeyCount == 1)
			{
				OldKey = NewKey;
				KeyState = KEY_PRESS;
			}
			break;

		case KEY_PRESS:
			if((KeyCount == 1) && (NewKey == OldKey))
			{
				ConfirmKey = OldKey;
				SendEventKeyPress(evQueuePtr);
				KeyState = KEY_CONFIRM;
			}
			else
			{
				KeyState = KEY_IDLE;
			}
			break;
		case KEY_CONFIRM:
			if(KeyCount == 0)
			{
				KeyState = KEY_IDLE;
			}	
			break;
		
		default:
			break;
	}
}

static void ReadKey(int8u inPort)
{
	int8u maskBit , inBit , maskPort , bitNum;
	KeyCount = 0;
	maskBit = 0x01;
	maskPort = ~((1 << KEY_MAX_NUM)-1);
	inBit = ~(inPort | maskPort);
	if(inBit != 0)
	{
		for (bitNum= 0; bitNum < KEY_MAX_NUM; bitNum++)
		{
			if((inBit & maskBit) != 0)
			{
				KeyCount++;
				NewKey = bitNum;
			}
			maskBit <<= 1;
		}
	}
}

static void SendEventKeyPress(EVQ_STRUCT *evQPtr)
{
	Q_ERR err;
	switch(ConfirmKey)
	{
		case 0:
			EvQPut(evQPtr ,Sw0EvStruct,&err);
			if(err == EVQ_FULL)
			{
				EvQFullCount++;
			}
			break;
		case 1:
			EvQPut(evQPtr ,Sw1EvStruct,&err);
			if(err == EVQ_FULL)
			{
				EvQFullCount++;
			}
			break;
		case 2:
			EvQPut(evQPtr ,Sw2EvStruct,&err);
			if(err == EVQ_FULL)
			{
				EvQFullCount++;
			}
			break;
			
		case 3:
			EvQPut(evQPtr ,Sw3EvStruct,&err);
			if(err == EVQ_FULL)
			{
				EvQFullCount++;
			}
			break;
		case 4:
			EvQPut(evQPtr ,Sw4EvStruct,&err);
			if(err == EVQ_FULL)
			{
				EvQFullCount++;
			}
			break;
		case 5:
			EvQPut(evQPtr ,Sw5EvStruct,&err);
			if(err == EVQ_FULL)
			{
				EvQFullCount++;
			}
			break;
		case 6:
			EvQPut(evQPtr ,Sw6EvStruct,&err);
			if(err == EVQ_FULL)
			{
				EvQFullCount++;
			}
			break;
		case 7:
			EvQPut(evQPtr ,Sw7EvStruct,&err);
			if(err == EVQ_FULL)
			{
				EvQFullCount++;
			}
			break;
		default:
			break;
	}
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