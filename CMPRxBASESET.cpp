/*
 * CMPRxBASESET.cpp
 *
 *  Created on: Aug 15, 2017
 *      Author: Boston
 */

#include "CMPRxBASESET.h"
#include "apmain.h"
#include "apservice.h"
#include "apeeprom.h"

#define UNIFIED_DC		(0x03FF)

CMPRxBASESET::CMPRxBASESET() :
	CMPDataHandler()
{

}

void CMPRxBASESET::callback(CMPData * data)
{
	uint16_t tempWord = (((uint16_t)(data->getByte(1) & 0x03)) << 8) | (data->getByte(0) & 0xFF);
	if(tempWord != UNIFIED_DC)
	{
		ApMain::inst.ledStrip.settings.setUnInfluencedBaseOffset(tempWord);
		ApEEPROM::inst.mem.ledStripSettings.setUnInfluencedBaseOffset(tempWord);
		ApEEPROM::inst.writeRequired();
	}

	tempWord = ((((uint16_t)(data->getByte(2) & 0x0F)) << 8) | (data->getByte(1) & 0xFF)) >> 2;
	if(tempWord != UNIFIED_DC)
	{
		ApMain::inst.ledStrip.settings.setUnInfluencedBrightnessUnified(tempWord);
		ApEEPROM::inst.mem.ledStripSettings.setUnInfluencedBrightnessUnified(tempWord);
		ApEEPROM::inst.writeRequired();
	}
}

void CMPRxBASESET::init()
{
	id.setID(BASESET_ID);
	ApService::inst.payloadHandlerRx.registerDataHandler(this);
}
