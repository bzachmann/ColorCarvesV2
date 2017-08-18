/*
 * ApEEPROM.h
 *
 *  Created on: Aug 16, 2017
 *      Author: Boston
 */

#ifndef APEEPROM_H_
#define APEEPROM_H_

#include "Timer.h"
#include "tiltsensor.h"
#include "speedsensor.h"
#include "ledtracker.h"
#include "ledstrip.h"
#include "apmain.h"

class ApEEPROM {
private:
	typedef struct MemContainer
	{
		TiltSensor::Settings tiltSensorSettings;
		SpeedSensor::Settings speedSensorSettings;
		LEDTracker::Settings ledTrackerSettings;
		LEDStrip<NUM_LEDS, PIN_LED_STRIP>::Settings ledStripSettings;


	} MemContainer;

public:
	ApEEPROM();
	void init();
	void run();
	void writeRequired();

private:
	void read();
	void write();
	void restore();
	void reverseRestore();
	bool checkChecksum();
	void calcChecksumReserve();

public:
	static ApEEPROM inst;
	MemContainer mem;

private:
	Timer timer;
	bool writeRequiredFlag;
	uint8_t checksumReserve;


};

#endif /* APEEPROM_H_ */
