/*
 * CMPRxANGSET.cpp
 *
 *  Created on: Aug 8, 2017
 *      Author: Boston
 */

#include "CMPRxANGSET.h"
#include "apservice.h"
#include "apmain.h"

#define SCALE_CMP_ANGLE		(0.1f)

CMPRxANGSET::CMPRxANGSET() :
	CMPDataHandler()
{

}

void CMPRxANGSET::callback(CMPData * data)
{
	uint16_t tempWord = (((uint16_t)data->getByte(0) << 2) | (data->getByte(1) >> 6));
	float newAngleLimit = tempWord * SCALE_CMP_ANGLE;
	ApMain::inst.tiltSensor.setAngleLimit(newAngleLimit);
}

void CMPRxANGSET::init()
{
	id.setID(ANGSET_ID);
	ApService::inst.payloadHandler.registerDataHandler(this);
}
