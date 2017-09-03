/*
 * CMPRxSPECSET.cpp
 *
 *  Created on: Aug 15, 2017
 *      Author: Boston
 */

#include "CMPRxSPECSET.h"
#include "apmain.h"
#include "apservice.h"
#include "apeeprom.h"

#define MASK_WHEEL_DIAMETER		(0x7F)
#define SCALE_CMP_LED_SPACING	(0.1f)
#define LED_SPACING_DC			(0x03FF)
#define WHEEL_DIAMETER_DC		(0x7F)

CMPRxSPECSET::CMPRxSPECSET() :
	CMPDataHandler()
{

}

void CMPRxSPECSET::callback(CMPData * data)
{
	uint16_t tempWord = (((uint16_t)(data->getByte(1) & 0x03)) << 8) | (data->getByte(0) & 0xFF);
	if(tempWord != LED_SPACING_DC)
	{
		ApMain::inst.ledTracker.settings.setLEDSpacing(((float)tempWord * SCALE_CMP_LED_SPACING));
		ApEEPROM::inst.mem.ledTrackerSettings.setLEDSpacing(((float)tempWord * SCALE_CMP_LED_SPACING));
		ApEEPROM::inst.writeRequired();
	}

	uint8_t tempByte = (data->getByte(2) & MASK_WHEEL_DIAMETER);
	if(tempByte != WHEEL_DIAMETER_DC)
	{
		ApMain::inst.speedSensor.settings.setWheelDiameter(tempByte);
		ApEEPROM::inst.mem.speedSensorSettings.setWheelDiameter(tempByte);
		ApEEPROM::inst.writeRequired();
	}
}

void CMPRxSPECSET::init()
{
	id.setID(SPECSET_ID);
	ApService::inst.payloadHandlerRx.registerDataHandler(this);

}
