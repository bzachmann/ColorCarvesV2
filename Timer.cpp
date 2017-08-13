/*
 * Timer.cpp
 *
 *  Created on: Aug 13, 2017
 *      Author: Boston
 */

#include "Timer.h"
#include "bsp_timercapt.h"


void Timer::start()
{
	started = true;
	usOld = bsp_timercapt_elapsedUs();
}

void Timer::run()
{
	if(started)
	{
		uint32_t usNew = bsp_timercapt_elapsedUs();
		uint32_t tempUsElapsed = usNew - usOld;

		if(elapsedUs <= (0xFFFFFFFF - tempUsElapsed))
		{
			elapsedUs += tempUsElapsed;
		}
		else
		{
			elapsedUs = 0xFFFFFFFF;
		}

		usOld = usNew;
	}
}

void Timer::stop()
{
	started = false;
}

void Timer::reset()
{
	elapsedUs = 0;
}

uint32_t Timer::getTimeUs()
{
	return elapsedUs;
}

uint32_t Timer::getTimeMs()
{
	return elapsedUs / 1000;
}
