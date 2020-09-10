
#ifndef  Drivemotor_lib_INCLUDED
#define  Drivemotor_lib_INCLUDED

#ifndef Drivemotor_lib_C_SRC

#include "CONFIG_PIC24.H"  
#include "CDATPIC24.H"

typedef struct
{
	float K_p;
	float K_i;
	float K_d;

	float error;
	float previous_error;
	float integral_error;
}PID_Parameter;


typedef struct 
{
	float x_position;
	float y_position;	
}Position;

#endif
void drive_motor(int axis, char  direction, float pwm);


#endif
