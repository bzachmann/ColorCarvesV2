/*
 * SpeedSensor.h
 *
 *  Created on: Aug 13, 2017
 *      Author: Boston
 */

#ifndef SPEEDSENSOR_H_
#define SPEEDSENSOR_H_

#include <stdint.h>

#define DEFAULT_CT_MAX_SPEED		(9.0f)
#define DEFAULT_CT_MIN_SPEED		(0.0f)
#define DEFAULT_CT_WHEEL_DIAMETER	(70)

class SpeedSensor {
public:
	SpeedSensor() :
		speed(0),
		maxSpeed(DEFAULT_CT_MAX_SPEED),
		minSpeed(DEFAULT_CT_MIN_SPEED),
		wheelDiameter(DEFAULT_CT_WHEEL_DIAMETER) {}

	void init();
	void run();
	float getSpeed();
	uint16_t getSpeedUnified();
	void setMaxSpeed(float mpers);
	void setMinSpeed(float mpers);
	void setWheelDiameter(uint8_t mm);

private:
	float calcSpeed(uint32_t const &usBetweenRotations);
	void setSpeed(float const &mpers);
	uint16_t convertUnified(float const &x, float const &inMin, float const &inMax,
								uint16_t const &outMin, uint16_t const &outMax);

private:
	float speed;
	float maxSpeed;
	float minSpeed;
	uint8_t wheelDiameter;

};

#endif /* SPEEDSENSOR_H_ */
