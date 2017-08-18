/*
 * ApMain.h
 *
 *  Created on: Aug 2, 2017
 *      Author: Boston
 */

#ifndef APMAIN_H_
#define APMAIN_H_

#include "tiltsensor.h"
#include "speedsensor.h"
#include "ledtracker.h"
#include "ledstrip.h"

#define	NUM_LEDS			(11)
#define	PIN_LED_STRIP		(6)

class ApMain {
public:
	ApMain();
	void init();
	void run();

public:
	static ApMain inst;

	TiltSensor tiltSensor;
	SpeedSensor speedSensor;
	LEDTracker ledTracker;

	LEDStrip<NUM_LEDS, PIN_LED_STRIP> ledStrip;
};

#endif /* APMAIN_H_ */
