/*
 * CMPRxANGSET.cpp
 *
 *  Created on: Aug 8, 2017
 *      Author: Boston
 */

#include "CMPRxANGSET.h"
#include "apservice.h"
#include "apmain.h"

CMPRxANGSET::CMPRxANGSET() :
	CMPDataHandler()
{

}

void CMPRxANGSET::callback(CMPData * data)
{
#warning todo do calculation here to set angle from data sent over CMP
	ApMain::inst.tiltSensor.setAngleLimit(20.0);
}

void CMPRxANGSET::init()
{
	id.setID(ANGSET_ID);
	ApService::inst.payloadHandler.registerDataHandler(this);
}
