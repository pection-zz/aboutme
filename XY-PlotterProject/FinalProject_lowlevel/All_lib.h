/*
*************************** C HEADER FILE ************************************

project   :
filename  : All_lib.H
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

#ifndef  All_lib_INCLUDED
#define  All_lib_INCLUDED

/****************************************************************************/
/**                                                                        **/
/**                              MODULES USED                              **/
/**                                                                        **/
/****************************************************************************/

#include "BITWISE_LIB.H"  
#include "EVENT_DRIVEN_CCS.H"
#include "math.h"

/****************************************************************************/
/**                                                                        **/
/**                        DEFINITIONS AND MACROS                          **/
/**                                                                        **/
/****************************************************************************/

#define AXIS_Y 0
#define AXIS_X 1
#define X_Y_AXIS 2

float targetX = 0;
float targetY = 0;

/****************************************************************************/
/**                                                                        **/
/**                        TYPEDEFS AND STRUCTURES                         **/
/**                                                                        **/
/****************************************************************************/

typedef struct
{
  float K_p;
  float K_i;
  float K_d;

  float u;
  float error;
  float previous_error;
  float integral_error;
  float currentPosition;

  float delta_u;
  float previous_u;
  float previous_previous_error;
}PID_PARAMIT;


typedef struct 
{
  float x_position;
  float y_position; 
}Position;

typedef enum 
{
  Y,
  N,
  C
}Limit;

typedef enum
{
  CW,
  CCW
}Rotation;

typedef struct 
{ 
  float Interval;
  int32u distance;
}Encoder;

typedef enum
{
  PID,
  Serial,
  wait,
  XY_SETZERO,
  STOP_MOTOR
}state;





float pwm = 0;


#ifndef All_lib_C_SRC

#endif


void drive_motor(unsigned int8 axis,Rotation &direction, float pwm);

void Encod_Get_B(unsigned int8 Capture, Encoder *PTR_ENCODER, int16u Pin_A, int16u Pin_B);
void Encod_Get_A(unsigned int8 Capture, Encoder *PTR_ENCODER, int16u Pin_A, int16u Pin_B);
void Control_POSITION_PID(unsigned int8 axis, float target, Encoder *PTR_ENCODER, PID_PARAMIT *PTR_PID_PARAM, float tolerance);
void Velocity_POSITION_PID(unsigned int8 axis, float target, Encoder *PTR_ENCODER, PID_PARAMIT *PTR_PID_PARAM, float tolerance);
void PackageSerial(int8u instruction, int8u *Package, PID_PARAMIT *PTR_PID_PARAMX, PID_PARAMIT *PTR_PID_PARAMY);

#endif

