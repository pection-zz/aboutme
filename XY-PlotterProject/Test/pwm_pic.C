#include "CONFIG_PIC24.H"  
#include "CDATPIC24.H"

#define CCR1N 62500
#define START_DUTY 0
static void HardwareInit (void) ;
static int16u duty1;
int LED1_Value=0,LED2_Value=0,LED3_Valu=0;
int main (void)
{
	disable_interrupts(INTR_GLOBAL);
	HardwareInit();
	clear_interrupt(INT_EXT1);
	enable_interrupts(INT_EXT1);
	clear_interrupt(INT_EXT2);
	enable_interrupts(INT_EXT2);
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
	set_tris_b (get_tris_b() & 0xfff3); // 1111 1111 1111 0011 B2, B3 o/p
	output_high (LED3);
		set_pwm_duty(1,10000);
	set_pwm_duty(2,10000);
	set_pwm_duty(3,10000);

	clear_interrupt(INT_TIMER1);
	duty1 = START_DUTY;
	set_compare_time(1,duty1);
	set_compare_time(2,duty1);
	set_compare_time(3,duty1);

		
	set_timer1(0);
	setup_timer1(TMR_INTERNAL | TMR_DIV_BY_256, 31249);

	setup_compare(1,COMPARE_PWM | COMPARE_TIMER2);
	setup_compare(2,COMPARE_PWM | COMPARE_TIMER2);
	setup_compare(3,COMPARE_PWM | COMPARE_TIMER2);

	set_timer2(0);
	setup_timer2(TMR_INTERNAL | TMR_DIV_BY_1,99);
	return;
}

#INT_TIMER1
void Time1 (void){
	output_toggle(LED3);
	return ;
}
#INT_EXT1
void Duty_pwm1(void){
	enable_interrupts(INT_TIMER1);
	set_pwm_duty(1,90);
	set_pwm_duty(2,90);
	set_pwm_duty(3,90);	
}
#INT_EXT2
void Duty_pwm2(void){
	disable_interrupts(INTR_GLOBAL);
	set_pwm_duty(1,100);
	set_pwm_duty(2,100);
	set_pwm_duty(3,100);	
}