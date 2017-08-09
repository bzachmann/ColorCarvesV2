/*
 * ApMain.cpp
 *
 *  Created on: Aug 2, 2017
 *      Author: Boston
 */

#include "ApMain.h"

ApMain ApMain::inst;

ApMain::ApMain() :
		tiltSensor()
{

}

void ApMain::init()
{
	tiltSensor.init();
}

void ApMain::run()
{
	tiltSensor.run();

	//speedSensor.run() //might be unnecessary

	//ledTracker.setSpeed(speedSensor.getSpeed())
	//ledTracker.run();


	//ledstrip.setBaseOffset(tiltSensor.getAngleUnified())
	//ledstrip.setBrightness(speedSensor.getSpeedUnified())
	//ledstrip.setOnIndex(ledTracker.getLedIndex())
	//ledstrip.run();

}
