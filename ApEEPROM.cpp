/*
 * ApEEPROM.cpp
 *
 *  Created on: Aug 16, 2017
 *      Author: Boston
 */

#include "ApEEPROM.h"
#include <eeprom.h>

#include "apmain.h"
#include "debugserial.h"

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
	debugPrint(F("initializing eeprom\n\r"));
	timer.reset();

	debugPrint(F("reading\n\r"));
	read();
	if(checkChecksum())
	{
		debugPrint(F("checksum good... restoring\n\r"));
		restore();
	}
	else
	{
		debugPrint(F("checksum bad.. reverse restoring\n\r"));
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
	debugPrint(F("reading memory at offset: "));
	debugPrint(EEPROM_OFFSET);
	debugPrint(F("\n\r"));
	EEPROM.get(EEPROM_OFFSET, mem);

	debugPrint(F("reading memory at offset: "));
	debugPrint(sizeof(MemContainer) + EEPROM_OFFSET);
	debugPrint(F("\n\r"));
	EEPROM.get(sizeof(MemContainer) + EEPROM_OFFSET, checksumReserve);
}

void ApEEPROM::write()
{
	debugPrint(F("writing eeprom!\n\r"));

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

