/*
 * ApMain.cpp
 *
 *  Created on: Aug 2, 2017
 *      Author: Boston
 */

#include "ApMain.h"

#warning todo remove this when testing done
#include <Arduino.h>

ApMain ApMain::inst;

ApMain::ApMain() :
		tiltSensor(),
		ledStrip()
{

}

void ApMain::init()
{
	tiltSensor.init();
	ledStrip.init();

#warning todo change this to restoring from eeprom
	ledStrip.setOffsetInfluencedEnabled(true);
}

void ApMain::run()
{
	tiltSensor.run();

	//speedSensor.run() //might be unnecessary

	//ledTracker.setSpeed(speedSensor.getSpeed())
	//ledTracker.run();

	Serial.println(tiltSensor.getAngleUnified());
	ledStrip.setInfluencedBaseOffset(tiltSensor.getAngleUnified());
	//ledstrip.setBrightness(speedSensor.getSpeedUnified())
	//ledstrip.setOnIndex(ledTracker.getLedIndex())
	ledStrip.run();

}
