/*
 * CMPRxSPEEDSET.cpp
 *
 *  Created on: Aug 15, 2017
 *      Author: Boston
 */

#include "CMPRxSPEEDSET.h"
#include "apservice.h"
#include "apmain.h"

#define SCALE_CMP_SPEED			(0.1f)
#define MASK_CMP_SPEED			(0x7F)
#define SPEED_DC				(0x7F)

CMPRxSPEEDSET::CMPRxSPEEDSET() :
	CMPDataHandler()
{

}

void CMPRxSPEEDSET::callback(CMPData * data)
{
	uint8_t tempByte = (data->getByte(0) & MASK_CMP_SPEED);
	if(tempByte != SPEED_DC)
	{
		ApMain::inst.speedSensor.setMinSpeed(((float)tempByte * SCALE_CMP_SPEED));
	}

	tempByte = (data->getByte(1) & MASK_CMP_SPEED);
	if(tempByte != SPEED_DC)
	{
		ApMain::inst.speedSensor.setMaxSpeed(((float)tempByte * SCALE_CMP_SPEED));
	}

}

void CMPRxSPEEDSET::init()
{
	id.setID(SPEEDSET_ID);
	ApService::inst.payloadHandler.registerDataHandler(this);
}

