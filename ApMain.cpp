/*
 * ApMain.cpp
 *
 *  Created on: Aug 2, 2017
 *      Author: Boston
 */

#include "ApMain.h"
#include "apcmp.h"

ApMain ApMain::inst;

ApMain::ApMain() :
		tiltSensor(),
		speedSensor(),
		ledTracker(NUM_LEDS),
		ledStrip()
{

}

void ApMain::init()
{
	tiltSensor.init();
	speedSensor.init(); //note: does nothing
	ledTracker.init();
	ledStrip.init();

#warning todo change this to restoring from eeprom
	//speedSensor.setMaxSpeed(4.0);
	//speedSensor.setMinSpeed(0.0);

	//tiltSensor.setAbsoluteMode(true);

	//ledStrip.setOffsetInfluencedEnabled(true);
	//ledStrip.setBrightnessInfluencedEnabled(true);
	//ledStrip.setPatternInfluencedEnabled(true);

}

void ApMain::run()
{
	//run sensors
	tiltSensor.run();
	speedSensor.run();

	ApCMP::inst.infoMsgTx.setSpeed(speedSensor.getSpeed());
	ApCMP::inst.infoMsgTx.setTiltAngle(tiltSensor.getAngle());

	ledTracker.setSpeed(speedSensor.getSpeed());
	ledTracker.run();

	//Use sensor values to adjust strip
	ledStrip.setInfluencedBaseOffset(tiltSensor.getAngleUnified());
	//ledStrip.setInfluencedBaseOffset(speedSensor.getSpeedUnified());

	ledStrip.setInfluencedBrightnessUnified(speedSensor.getSpeedUnified());
	//ledStrip.setInfluencedBrightnessUnified(tiltSensor.getAngleUnified());

	//ledStrip.setOnIndexUnified(tiltSensor.getAngleUnified());
	//ledStrip.setOnIndexUnified(speedSensor.getSpeedUnified());
	ledStrip.setOnIndex(ledTracker.getLEDIndex());

	//run strip
	ledStrip.run();

}
