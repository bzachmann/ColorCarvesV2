/*
 * CMPRxBASESET.cpp
 *
 *  Created on: Aug 15, 2017
 *      Author: Boston
 */

#include "CMPRxBASESET.h"
#include "apmain.h"
#include "apservice.h"

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
		ApMain::inst.ledStrip.setUnInfluencedBaseOffset(tempWord);
	}

	tempWord = ((((uint16_t)(data->getByte(2) & 0x0F)) << 8) | (data->getByte(1) & 0xFF)) >> 2;
	if(tempWord != UNIFIED_DC)
	{
		ApMain::inst.ledStrip.setUnInfluencedBrightnessUnified(tempWord);
	}
}

void CMPRxBASESET::init()
{
	id.setID(BASESET_ID);
	ApService::inst.payloadHandler.registerDataHandler(this);
}
