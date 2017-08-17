/*
 * SpeedSensor.cpp
 *
 *  Created on: Aug 13, 2017
 *      Author: Boston
 */

#include "SpeedSensor.h"
#include "bsp_timercapt.h"
#include "apservice.h"

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define PARTIAL_SCALE	(3141.59265359f)

float SpeedSensor::Settings::getMinSpeed() const
{
	return minSpeed;
}

float SpeedSensor::Settings::getMaxSpeed() const
{
	return maxSpeed;
}

uint8_t SpeedSensor::Settings::getWheelDiameter() const
{
	return wheelDiameter;
}

void SpeedSensor::Settings::setMinSpeed(float mpers)
{
	if((mpers >= 0.0f) && (mpers != maxSpeed))
	{
		minSpeed = mpers;
	}
}

void SpeedSensor::Settings::setMaxSpeed(float mpers)
{
	if((mpers > 0.0f) && (mpers != minSpeed))
	{
		maxSpeed = mpers;
	}
}

void SpeedSensor::Settings::setWheelDiameter(uint8_t mm)
{
	wheelDiameter = mm;
}

void SpeedSensor::init()
{

}

void SpeedSensor::run()
{
	uint32_t usBetweenCaptures = bsp_timercapt_usBetweenCaptures();
	uint32_t usSinceLastCapture = bsp_timercapt_usSinceCapture();

	if(usSinceLastCapture > usBetweenCaptures)
	{
		usBetweenCaptures = usSinceLastCapture;
	}

	setSpeed(calcSpeed(usBetweenCaptures));
}

float SpeedSensor::getSpeed()
{
	return speed;
}

uint16_t SpeedSensor::getSpeedUnified()
{
	return convertUnified(speed, settings.getMinSpeed(), settings.getMaxSpeed(), UNIFIED_VALUE_LOW, UNIFIED_VALUE_HIGH);
}

float SpeedSensor::calcSpeed(uint32_t const &usBetweenRotations)
{
	float retVal = 0;
	if(usBetweenRotations != 0)
	{
		retVal = (PARTIAL_SCALE * settings.getWheelDiameter()) / usBetweenRotations;

	}
	return retVal;
}

void SpeedSensor::setSpeed(float const &mpers)
{
	speed = min(mpers, settings.getMaxSpeed());
	speed = max(speed, settings.getMinSpeed());
}

uint16_t SpeedSensor::convertUnified(
		float const &x,
		float const &inMin,
		float const &inMax,
		uint16_t const &outMin,
		uint16_t const &outMax)
{
	return (uint16_t)((((x - inMin)/(inMax - inMin)) * (outMax - outMin)) + outMin);
}
