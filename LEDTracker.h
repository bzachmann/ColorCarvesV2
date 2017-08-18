/*
 * LEDTracker.h
 *
 *  Created on: Aug 13, 2017
 *      Author: Boston
 */

#ifndef LEDTRACKER_H_
#define LEDTRACKER_H_

#include <stdint.h>
#include "timer.h"

#define DEFAULT_CT_LED_SPACING		(17.0f)

class LEDTracker {
public:
	class Settings
	{
	public:
		Settings() :
			ledSpacing(DEFAULT_CT_LED_SPACING) {}

		float getLEDSpacing();
		void setLEDSpacing(float mm);

	private:
		float ledSpacing;
	};

	LEDTracker(uint8_t numLEDs) :
		settings(),
		numLeds(numLEDs),
		speed(0.0f),
		elapsedLedRemainder(0.0f),
		ledIndex(0),
		timer() {}

	void init();
	void run();
	void setSpeed(float mpers);
	uint8_t getLEDIndex();

public:
	Settings settings;

private:
   uint16_t getElapsedLEDs();

private:
   	uint8_t numLeds;

	float speed;
	float elapsedLedRemainder;
	uint8_t ledIndex;

	Timer timer;
};

#endif /* LEDTRACKER_H_ */
