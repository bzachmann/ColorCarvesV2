/*
 * bsp_atmega328p_timercapt.c
 *
 *  Created on: Aug 12, 2017
 *      Author: Boston
 */

#ifndef BSP_ATMEGA328P_TIMERCAPT_C_
#define BSP_ATMEGA328P_TIMERCAPT_C_

#warning todo try to switch to other header files to cut out arduino middle sw
#include <Arduino.h>
//#include <avr/io.h>
//#include <avr/interrupt.h>

volatile uint32_t tickOld = 0;
volatile uint16_t countUpper16 = 0;
volatile uint32_t ticksBetweenCaptures = 0;
volatile uint8_t capturePrescaler = 0;
static uint8_t ticksPerUs = 0;

//what happends if upper16 overflows.
//how how oftne does uppoer 16 overflow?
//how often do you need to interruprt (prescaler) times in order to be accurate?

void bsp_timercapt_init(uint8_t, clockMHz, uint8_t prescaler)
{
	ticksPerUs = clockMHz;
	capturePrescaler = prescaler;

	TCCR1A = 0;
	TCCR1B = 0;
	TCCR1B |= (1 << 7) | (1 << 6) | (1 << 0);  //rising edge detection and no time prescaler
	TIMSK1 |= (1 << 5) | (1 << 0); //enable input capture interrupt and overflow interrupt
	SREG |= (1 << 7);  //global interrupt enable
}

uint32_t bsp_timercapt_ticksBetweenCaptures()
{
	return ticksBetweenCaptures;
}

uint32_t bsp_timercapt_usBetweenCaptures()
{
	uint32_t retVal = 0;
	if(ticksPerUs > 0)
	{
#warning if more cpu cycles needed this could be sped up given that because this is 16 ticksperUs you could do << 4
		retVal = ticksBetweenCaptures / ticksPerUs;
	}
	return retVal;
}

void bsp_timercapt_run()
//*****************************************************************************
/*
 * must be run at a rate faster than ? ms
 *
 *///**************************************************************************
{

}

uint32_t bsp_timercapt_ticksSinceCapture()
{
	uint32_t tickNew =
}

uint32_t bsp_timercapt_usSinceCapture()
{

}


ISR(TIMER1_CAPT_vect)
{
	static volatile interruptCount = 0;
	interruptCount++;
	if(capturePrescaler > 0)
	{
		if(interruptCount == capturePrescaler)
		{
			static uint32_t tickNew = 0;
			tickNew = ( (((uint32_t)(countUpper16)) << 16) | ICR1);
			ticksBetweenCaptures = tickNew - tickOld;

			tickOld = tickNew;
			interruptCount = 0;
		}
	}
}

ISR(TIMER1_OVF_vect)
{
	countUpper16++;
}



#endif /* BSP_ATMEGA328P_TIMERCAPT_C_ */
