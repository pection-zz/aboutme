#include "CONFIG_PIC24.H"
#include "CDATPIC24.H"
#define START_DUTY 0;
static void HardwareInit(void);
int main(void)
{
disable_interrupts(INTR_GLOBAL);
HardwareInit();
enable_interrupts(INTR_GLOBAL);
clear_interrupt(INT_EXT1);
clear_interrupt(INT_EXT2);
enable_interrupts(INT_EXT1);
enable_interrupts(INT_EXT2);
for(;;)
{
}
return 0;

}
static void HardwareInit(void)
{
	int xx=9,yy=9;
	yy=yy>>1;
	setup_adc_ports(NO_ANALOGS);
	set_tris_a(get_tris_a	() &0xffeb);
	set_tris_b(get_tris_b()&0xfff3);
	
	set_compare_time(1,0);
	setup_compare(1,COMPARE_PWM | COMPARE_TIMER3);
	
	set_compare_time(2,0);
	setup_compare(2,COMPARE_PWM | COMPARE_TIMER3);
	
	set_compare_time(3,0);
	setup_compare(3,COMPARE_PWM | COMPARE_TIMER3);
	
	set_timer3(0);
	setup_timer3(TMR_INTERNAL | TMR_DIV_BY_1 , 100);

	clear_interrupt(INT_TIMER1);
	set_timer1(0);
	
	setup_timer1(TMR_INTERNAL | TMR_DIV_BY_256 31249);
	set_pwm_duty(1,100);
	set_pwm_duty(2,100);
	set_pwm_duty(3,100);
	output_high(LED3);

}

#INT_TIMER1
void Timer1(void){
 output_toggle(LED3);
}


#INT_EXT1 
void MIKE1ISR(void){
	enable_interrupts(INT_TIMER1);
	set_pwm_duty(1,75);
	set_pwm_duty(2,50);
	set_pwm_duty(3,25);
}
#INT_EXT2 
void IISR(void){
	set_pwm_duty(1,100);
	set_pwm_duty(2,100);
	set_pwm_duty(3,100);
}