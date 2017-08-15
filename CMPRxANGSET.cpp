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
#define ANGLE_DC			(0x03FF)
#define ABS_MODE_DC			(0x03)

CMPRxANGSET::CMPRxANGSET() :
	CMPDataHandler()
{

}

void CMPRxANGSET::callback(CMPData * data)
{
	uint16_t angleLimitWord = (((uint16_t)(data->getByte(1) & 0x03)) << 8) | (data->getByte(0) & 0xFF);
	uint8_t absoluteMode = (data->getByte(2) & 0x03);

	if(angleLimitWord != ANGLE_DC)
	{
		float newAngleLimit = angleLimitWord * SCALE_CMP_ANGLE;
		ApMain::inst.tiltSensor.setAngleLimit(newAngleLimit);
	}

	if(absoluteMode != ABS_MODE_DC)
	{
		if(absoluteMode == 0)
		{
			ApMain::inst.tiltSensor.setAbsoluteMode(false);
		}
		else if(absoluteMode == 1)
		{
			ApMain::inst.tiltSensor.setAbsoluteMode(true);
		}
	}
}

void CMPRxANGSET::init()
{
	id.setID(ANGSET_ID);
	ApService::inst.payloadHandler.registerDataHandler(this);
}
