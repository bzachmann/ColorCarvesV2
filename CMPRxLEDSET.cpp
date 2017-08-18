/*
 * CMPRxLEDSET.cpp
 *
 *  Created on: Aug 5, 2017
 *      Author: bzachmann
 */

#include "cmprxledset.h"
#include "apservice.h"
#include "apmain.h"
#include "apeeprom.h"

#define LED_STATE_DC		(0x03)
#define LED_OFFSET_DC		(0x03FF)
#define LED_INDEX_ALL		(0x3F)

CMPRxLEDSET::CMPRxLEDSET() :
	CMPDataHandler()
{

}

void CMPRxLEDSET::callback(CMPData * data)
{
	uint16_t ledOffset = (((uint16_t)data->getByte(1) & 0x03) << 8) | ((uint16_t)data->getByte(0) & 0xFF);
	uint8_t ledIndex = data->getByte(1) >> 2;
	uint8_t ledState = data->getByte(2) & 0x03;

	if(ledIndex == LED_INDEX_ALL)
	{
		setAllLEDs(ledState, ledOffset);
	}
	else
	{
		setLED(ledIndex, ledState, ledOffset);
	}
}
void CMPRxLEDSET::init()
{
	id.setID(LEDSET_ID);
	ApService::inst.payloadHandler.registerDataHandler(this);
}

void CMPRxLEDSET::setLED(uint8_t const &ledIndex, uint8_t const &state, uint16_t const &offset)
{
	if(state != LED_STATE_DC)
	{
		if(state == 0)
		{
			ApMain::inst.ledStrip.settings.setLEDState(ledIndex, false);
			ApEEPROM::inst.mem.ledStripSettings.setLEDState(ledIndex, false);
			ApEEPROM::inst.writeRequired();
		}
		else if(state == 1)
		{
			ApMain::inst.ledStrip.settings.setLEDState(ledIndex, true);
			ApEEPROM::inst.mem.ledStripSettings.setLEDState(ledIndex, true);
			ApEEPROM::inst.writeRequired();
		}
	}

	if(offset != LED_OFFSET_DC)
	{
		ApMain::inst.ledStrip.settings.setLEDOffset(ledIndex, offset);
		ApEEPROM::inst.mem.ledStripSettings.setLEDOffset(ledIndex, offset);
		ApEEPROM::inst.writeRequired();
	}
}

void CMPRxLEDSET::setAllLEDs(uint8_t const &state, uint16_t const &offset)
{
	uint8_t limit = ApMain::inst.ledStrip.settings.getNumLeds();
	for(uint8_t i = 0; i < limit; i++)
	{
		setLED(i, state, offset);
	}
}

