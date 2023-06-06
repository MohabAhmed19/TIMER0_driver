/*
 * Timer_0.h
 *
 * Created: 4/11/2023 8:57:45 PM
 *  Author: Mohab
 */ 


#ifndef TIMER_0_H_
#define TIMER_0_H_

#include "../../utils/STD_TYPES.h"
#include "../../utils/registers.h"
#include "../../utils/utilities.h"
#include "../../MCAL/Interrupt/Interrupt.h"


#define Normal 0
#define PWM 1
#define CTC 2
#define Fast_PWM 3


uint8_t timer0_init(uint8_t mode_of_operation, uint8_t timer_starting_value);

uint8_t start_timer0(unsigned int prescaler);


#endif /* TIMER_0_H_ */