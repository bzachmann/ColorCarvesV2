/*
 * ApMain.cpp
 *
 *  Created on: Aug 2, 2017
 *      Author: Boston
 */

#include "ApMain.h"

ApMain ApMain::inst;

ApMain::ApMain() :
		tiltSensor(),
		speedSensor(),
		ledStrip()
{

}

void ApMain::init()
{
	tiltSensor.init();
	speedSensor.init(); //note: does nothing
	ledStrip.init();

#warning todo change this to restoring from eeprom
	//speedSensor.setMaxSpeed(4.0);
	//speedSensor.setMinSpeed(0.0);
	ledStrip.setOffsetInfluencedEnabled(true);
	ledStrip.setBrightnessInfluencedEnabled(true);

}

void ApMain::run()
{
	tiltSensor.run();
	speedSensor.run();

	//ledTracker.setSpeed(speedSensor.getSpeed())
	//ledTracker.run();

	ledStrip.setInfluencedBaseOffset(tiltSensor.getAngleUnified());
	ledStrip.setInfluencedBrightnessUnified(speedSensor.getSpeedUnified());
	//ledstrip.setOnIndex(ledTracker.getLedIndex())
	ledStrip.run();

}
