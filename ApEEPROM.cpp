/*
 * ApEEPROM.cpp
 *
 *  Created on: Aug 16, 2017
 *      Author: Boston
 */

#include "ApEEPROM.h"
#include <eeprom.h>

#include "apmain.h"

#warning todo remove after testing
#include <Arduino.h>

#define DEBOUNCE_EEPROM_WRITE	(1000)
#define EEPROM_OFFSET			(0)
#define CHECKSUM_GOOD			(0xEE)

ApEEPROM ApEEPROM::inst;

ApEEPROM::ApEEPROM() :
		timer(),
		writeRequiredFlag(false),
		checksumReserve(0)
{

}

void ApEEPROM::init()
{
	Serial.println(F("initializing eeprom"));
	timer.reset();

	Serial.println(F("reading"));
	read();
	if(checkChecksum())
	{
		Serial.println(F("checksum good... restoring"));
		restore();
	}
	else
	{
		Serial.println(F("checksum bad.. reverse restoring"));
		reverseRestore();
		write();
	}
}

void ApEEPROM::run()
{
	timer.run();

	if((writeRequiredFlag) && (timer.getTimeMs() > DEBOUNCE_EEPROM_WRITE))
	{
		write();
	}
}

void ApEEPROM::writeRequired()
{
	if(!writeRequiredFlag)
	{
		writeRequiredFlag = true;
	}
	timer.reset();
	timer.start();
}

void ApEEPROM::read()
{
	Serial.print(F("reading memory at offset: "));
	Serial.println(EEPROM_OFFSET);
	EEPROM.get(EEPROM_OFFSET, mem);

	Serial.print(F("reading memory at offset: "));
	Serial.println(sizeof(MemContainer) + EEPROM_OFFSET);
	EEPROM.get(sizeof(MemContainer) + EEPROM_OFFSET, checksumReserve);
}

void ApEEPROM::write()
{
	Serial.println(F("writing eeprom!"));

	writeRequiredFlag = false;
	timer.stop();

	calcChecksumReserve();
	EEPROM.put(EEPROM_OFFSET, mem);
	EEPROM.put(sizeof(mem) + EEPROM_OFFSET, checksumReserve);
}

void ApEEPROM::restore()
{
	memcpy(&ApMain::inst.tiltSensor.settings, &mem.tiltSensorSettings, sizeof(TiltSensor::Settings));
	memcpy(&ApMain::inst.speedSensor.settings, &mem.speedSensorSettings, sizeof(SpeedSensor::Settings));
	memcpy(&ApMain::inst.ledTracker.settings, &mem.ledTrackerSettings, sizeof(LEDTracker::Settings));
	memcpy(&ApMain::inst.ledStrip.settings, &mem.ledStripSettings, sizeof(LEDStrip<NUM_LEDS, PIN_LED_STRIP>::Settings));
}

void ApEEPROM::reverseRestore()
{
	memcpy(&mem.tiltSensorSettings, &ApMain::inst.tiltSensor.settings, sizeof(TiltSensor::Settings));
	memcpy(&mem.speedSensorSettings, &ApMain::inst.speedSensor.settings, sizeof(SpeedSensor::Settings));
	memcpy(&mem.ledTrackerSettings, &ApMain::inst.ledTracker.settings, sizeof(LEDTracker::Settings));
	memcpy(&mem.ledStripSettings, &ApMain::inst.ledStrip.settings, sizeof(LEDStrip<NUM_LEDS, PIN_LED_STRIP>::Settings));
}

bool ApEEPROM::checkChecksum()
{
	uint8_t * eePtr = (uint8_t*)(&mem);
	uint16_t eeBytes = sizeof(MemContainer);

	uint8_t eeChecksum = *eePtr;
	eePtr++;
	for(uint16_t i = 1; i < eeBytes; i++)
	{
		eeChecksum = eeChecksum ^ *eePtr;
		eePtr++;
	}

	eeChecksum = eeChecksum ^ checksumReserve;

	return (eeChecksum == CHECKSUM_GOOD);
}

void ApEEPROM::calcChecksumReserve()
{
	uint8_t * eePtr = (uint8_t*)(&mem);
	uint16_t eeBytes = sizeof(MemContainer);

	uint8_t xorTemp = *eePtr;
	eePtr++;
	for(uint16_t i = 1; i < eeBytes; i++)
	{
		xorTemp = xorTemp ^ *eePtr;
		eePtr++;
	}

	checksumReserve = xorTemp ^ CHECKSUM_GOOD;
}

