#define Drivemotor_lib_C_SRC


#include "Drivemotor_lib.H"
void Drive_motor(int axis, int direction, float pwm){
	if (axis == 0){
		if (direction == 1){
            output_low(PIN_B0);
            output_high(PIN_B1);
		}
		else {
            output_low(PIN_B1);
            output_high(PIN_B0);
		}
		set_pwm_duty(1,pwm);
	}
}
	
	
