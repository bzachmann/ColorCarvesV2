/*
 * TiltSensor.h
 *
 *  Created on: Aug 7, 2017
 *      Author: Boston
 */

#include <Adafruit_BNO055.h>

#ifndef TILTSENSOR_H_
#define TILTSENSOR_H_

#define DEFAULT_BNO055_ID		(21)
#define DEFAULT_ANGLE_LIMIT		(50.0f)
#define MAX_EULER_ANGLE			(180.0f)
#define UNIFIED_VALUE_LOW		(0)
#define UNIFIED_VALUE_HIGH		(765)

class TiltSensor {
public:
	enum axis_t
	{
		TILT_AXIS_X = 0,
		TILT_AXIS_Y,
		TILT_AXIS_Z,
	};

	TiltSensor(axis_t axis = TILT_AXIS_Z) :
		bno(DEFAULT_BNO055_ID),
		initialized(false),
		angle(0.0),
		axis(axis),
		angleLimit(DEFAULT_ANGLE_LIMIT){}

	bool init();
	void run();
	float getAngle();
	uint16_t getAngleUnified();
	float getAngleLimit();
	void setAngleLimit(float limit);

private:
	void setAngle(float degrees);
	uint16_t convertUnified(float const &x, float const &inMin, float const &inMax,
							uint16_t const &outMin, uint16_t const &outMax);

private:
	Adafruit_BNO055 bno;

	bool initialized;
	float angle;
	uint8_t axis;
	float angleLimit;

};

#endif /* TILTSENSOR_H_ */
