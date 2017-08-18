/*
 * LEDTracker.cpp
 *
 *  Created on: Aug 13, 2017
 *      Author: Boston
 */

#include "LEDTracker.h"

float LEDTracker::Settings::getLEDSpacing()
{
	return ledSpacing;
}

void LEDTracker::Settings::setLEDSpacing(float mm)
{
	if(mm > 0.0f)
	{
		ledSpacing = mm;
	}
}

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

uint8_t LEDTracker::getLEDIndex()
{
	return ledIndex;
}

uint16_t LEDTracker::getElapsedLEDs()
{
	uint16_t retVal = 0;
	if(settings.getLEDSpacing() != 0)
	{
		uint32_t elapsedUs = timer.getTimeUs();
		elapsedLedRemainder += (speed * elapsedUs)/(settings.getLEDSpacing() * 1000);
		retVal = (uint16_t)elapsedLedRemainder;
		elapsedLedRemainder -= retVal;
	}
	return retVal;
}
