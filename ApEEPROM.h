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

class ApEEPROM {
private:
	typedef struct MemContainer
	{
		TiltSensor::Settings tiltSensorSettings;
		SpeedSensor::Settings speedSensorSettings;


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
