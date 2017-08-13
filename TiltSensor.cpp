/*
 * TiltSensor.cpp
 *
 *  Created on: Aug 7, 2017
 *      Author: Boston
 */

#include "TiltSensor.h"
#include "apservice.h"

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))

bool TiltSensor::init()
{
	initialized = bno.begin(Adafruit_BNO055::OPERATION_MODE_NDOF);
	if(initialized)
	{
		bno.setExtCrystalUse(true);
	}
	return initialized;
}

void TiltSensor::run()
{
	if(initialized)
	{
		imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
		switch(axis)
		{
		case TILT_AXIS_X:
			setAngle(euler.x());
			break;
		case TILT_AXIS_Y:
			setAngle(euler.y());
			break;
		case TILT_AXIS_Z:
			setAngle(euler.z());
			break;
		default:
			setAngle(0.0);
			break;
		}
	}
}

float TiltSensor::getAngle()
{
	return angle;
}

uint16_t TiltSensor::getAngleUnified()
{
	return convertUnified(angle, (angleLimit * -1), angleLimit, UNIFIED_VALUE_LOW, UNIFIED_VALUE_HIGH);
}

float TiltSensor::getAngleLimit()
{
	return angleLimit;
}

void TiltSensor::setAngleLimit(float limit)
{
	if((limit > 0.0f) && (limit <= MAX_EULER_ANGLE))
	{
		angleLimit = limit;
	}
}

void TiltSensor::setAngle(float degrees)
{
	angle = min(degrees, angleLimit);
	angle = max(angle, (angleLimit * -1));
}

uint16_t TiltSensor::convertUnified(
		float const &x,
		float const &inMin,
		float const &inMax,
		uint16_t const &outMin,
		uint16_t const &outMax)
{
	return (uint16_t)((((x - inMin)/(inMax - inMin)) * (outMax - outMin)) + outMin);
}
