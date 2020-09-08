#include "CONFIG_PIC24.H"  
#include "CDATPIC24.H"
#include "BL_Support.h"
#define START_DUTY 0
static void HardwareInit (void) ;
float target=0,currentPosition=0,e,int_e=0,p_e=0,u=0,pwm;
static int16u ip_b, c_a, c_b, direction, NewCap, OldCap, Interval;
int distance;
float tolerance = 3;
float Kp = 1000.0f;
float Ki = 1.0f;
float Kd = 70.0f;
int main (void)
{
	disable_interrupts(INTR_GLOBAL);
	clear_interrupt(INT_EXT0);
	enable_interrupts(INT_EXT0);
	clear_interrupt(INT_EXT1);
	enable_interrupts(INT_EXT1);
	HardwareInit();
	enable_interrupts(INTR_GLOBAL);
	for(;;){


	}
	return 0;
}

static void HardwareInit (void)
{
	setup_adc_ports(NO_ANALOGS);
	//GPIO LED 0-3 : A2, A4, B2, B3 ; Sw 0-3 : B4, B5, B6, B7
	set_tris_a (get_tris_a() & 0xffeb); // 1111 1111 1110 1011 A2, A4 o/p
	set_tris_b (get_tris_b() & 0xfff0); // 1111 1111 1111 0000 B2, B3 o/p

	set_compare_time(1, 0);
	clear_interrupt(INT_TIMER2);
	setup_compare(1, COMPARE_PWM | COMPARE_TIMER2);
	set_timer2(0);
	setup_timer2(TMR_INTERNAL | TMR_DIV_BY_256, 624);
	set_pwm_duty(1,0);



	clear_interrupt(INT_TIMER5);
	set_timer5(0);
	setup_timer5(TMR_INTERNAL | TMR_DIV_BY_64,24); /////0.0001s
	disable_interrupts(INT_TIMER5);

	setup_capture(1, CAPTURE_EE | INTERRUPT_EVERY_CAPTURE |CAPTURE_TIMER3);
	clear_interrupt(INT_IC1);
	enable_interrupts(INT_IC1);

	setup_capture(2, CAPTURE_EE | INTERRUPT_EVERY_CAPTURE |CAPTURE_TIMER3);
	clear_interrupt(INT_IC2);
	enable_interrupts(INT_IC2);

	set_timer3(0);
	setup_timer3(TMR_INTERNAL | TMR_DIV_BY_1, 65535);


	return;
}


#INT_TIMER5
void Pidcontrol_check(void){
	currentPosition = (7.5 * 22* (float)(distance) * 60)/(7 * 180 * 64);

	e = target - currentPosition;
	
	
	int_e = int_e + e;
	u = Kp*e + Ki*int_e + Kd*(e-p_e);
	p_e = e;
	
	
	if(abs(e) > tolerance){
		pwm = abs(u);
	}
	else {
		pwm = 0;
		set_pwm_duty(1,0);
		disable_interrupts(INT_TIMER5);
	}
	printf("%d\n", (int16)e);
	if( u > 0){
		output_high(PIN_B0);
		if (pwm > 200000){ pwm = 200000;}
		pwm = pwm *800 / 200000;
		set_pwm_duty(1,(int16u)pwm);
	}
	else{
		output_high(PIN_B1);
		if (pwm > 100000){ pwm = 100000;}
		pwm = pwm *800 / 100000;
		set_pwm_duty(1,(int16u)pwm);
	}
	return;
}	


#INT_IC1
void IC1ISR (void){
	ip_b = input_b();
	NewCap = get_capture(1);
	Interval = NewCap - OldCap;
	OldCap = NewCap;
	c_a = (ip_b & 0x10) >> 4;
	c_b = (ip_b & 0x20) >> 5;
	if(c_a == c_b){
		direction = 0;
		distance -=1;
	}
	else{
		direction = 1;
		distance +=1;
	}
	// printf("a\n");

	return;
}



#INT_IC2
void IC2ISR (void){
	ip_b = input_b();
	NewCap = get_capture(2);
	Interval = NewCap - OldCap;
	OldCap = NewCap;
	c_a = (ip_b & 0x10) >> 4;
	c_b = (ip_b & 0x20) >> 5;
	if(c_a != c_b){
		direction = 0;
		distance -=1;
	}
	else{
		direction = 1;
		distance+=1;
	}
	// printf("b\n");
	return;
}

#INT_EXT0
void set_target(void){
	target = 0 ;
	enable_interrupts(INT_TIMER5);
	printf("HELLO2");

}
#INT_EXT1
void set_target_2(void){
	target = 1500;
	enable_interrupts(INT_TIMER5);
	printf("HELLO");
	output_low(LED0);
	output_low(LED1);
}
