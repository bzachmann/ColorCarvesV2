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
	class Settings
	{
	public:
		Settings() :
			minSpeed(DEFAULT_CT_MIN_SPEED),
			maxSpeed(DEFAULT_CT_MAX_SPEED),
			wheelDiameter(DEFAULT_CT_WHEEL_DIAMETER) {}

		float getMinSpeed() const;
		float getMaxSpeed() const;
		uint8_t getWheelDiameter() const;
		void setMinSpeed(float mpers);
		void setMaxSpeed(float mpers);
		void setWheelDiameter(uint8_t mm);

	private:
		float minSpeed;
		float maxSpeed;
		uint8_t wheelDiameter;
	};

	SpeedSensor() :
		settings(),
		speed(0.0f) {}

	void init();
	void run();
	float getSpeed();
	uint16_t getSpeedUnified();

public:
	Settings settings;

private:
	float calcSpeed(uint32_t const &usBetweenRotations);
	void setSpeed(float const &mpers);
	uint16_t convertUnified(float const &x, float const &inMin, float const &inMax,
								uint16_t const &outMin, uint16_t const &outMax);

private:
	float speed;

};

#endif /* SPEEDSENSOR_H_ */
