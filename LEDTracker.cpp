/*
 * LEDTracker.cpp
 *
 *  Created on: Aug 13, 2017
 *      Author: Boston
 */

#include "LEDTracker.h"

void LEDTracker::init()
{
	timer.start();
}

void LEDTracker::run()
{
	timer.run();

	ledIndex = (ledIndex + getElapsedLEDs()) % numLeds;

	timer.reset();
}

void LEDTracker::setSpeed(float mpers)
{
	if(mpers >= 0.0f)
	{
		speed = mpers;
	}
}

void LEDTracker::setLEDSpacing(float mm)
{
	if(mm > 0.0f)
	{
		ledSpacing = mm;
	}
}

uint8_t LEDTracker::getLEDIndex()
{
	return ledIndex;
}

uint16_t LEDTracker::getElapsedLEDs()
{
	uint16_t retVal = 0;
	if(ledSpacing != 0)
	{
		uint32_t elapsedUs = timer.getTimeUs();
		elapsedLedRemainder += (speed * elapsedUs)/(ledSpacing * 1000);
		retVal = (uint16_t)elapsedLedRemainder;
		elapsedLedRemainder -= retVal;
	}
	return retVal;
}
