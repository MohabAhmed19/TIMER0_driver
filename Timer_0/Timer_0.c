/*
 * Timer_0.c
 *
 * Created: 4/11/2023 9:00:42 PM
 *  Author: Mohab
 */ 

#include "Timer_0.h"

uint8_t timer0_init(uint8_t mode_of_operation, uint8_t timer_starting_value)
{
	uint8_t error=0;
	switch(mode_of_operation)
	{
		case Normal:
			Clear_Bit(TCCR0,6);
			Clear_Bit(TCCR0,3);
			break;
		case PWM:
			Set_Bit(TCCR0,6);
			Clear_Bit(TCCR0,3);
			break;
		case CTC:
			Clear_Bit(TCCR0,6);
			Set_Bit(TCCR0,3);
			break;
		case Fast_PWM:
			Set_Bit(TCCR0,6);
			Set_Bit(TCCR0,3);
			break;
		default:
			error=1;
			break;
	}
	TCNT0 = timer_starting_value;
	Set_Bit(SREG,7);
	Set_Bit(TIMSK,0);
}

uint8_t start_timer0(unsigned int prescaler)
{
	uint8_t error=0;
	switch(prescaler)
	{
		case 0:
			Clear_Bit(TCCR0,0);
			Clear_Bit(TCCR0,1);
			Clear_Bit(TCCR0,2);
			break;
		case 1:
			Set_Bit(TCCR0,0);
			Clear_Bit(TCCR0,1);
			Clear_Bit(TCCR0,2);
			break;
		case 8:
			Clear_Bit(TCCR0,0);
			Set_Bit(TCCR0,1);
			Clear_Bit(TCCR0,2);
			break;
		case 64:
			Set_Bit(TCCR0,0);
			Set_Bit(TCCR0,1);
			Clear_Bit(TCCR0,2);
			break;
		case 256:
			Clear_Bit(TCCR0,0);
			Clear_Bit(TCCR0,1);
			Set_Bit(TCCR0,2);
			break;
		case 1024:
			Set_Bit(TCCR0,0);
			Clear_Bit(TCCR0,1);
			Set_Bit(TCCR0,2);
			break;
		default:
			error = 1;
			break;
	}
}