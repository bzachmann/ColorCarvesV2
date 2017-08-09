/*
 * CMPRxLEDSET.cpp
 *
 *  Created on: Aug 5, 2017
 *      Author: bzachmann
 */

#include "cmprxledset.h"
#include "apservice.h"

#warning remove this after testing done
#include <Arduino.h>

CMPRxLEDSET::CMPRxLEDSET() :
	CMPDataHandler()
{

}

void CMPRxLEDSET::callback(CMPData * data)
{
	Serial.println("callback works for LEDSET");

}
void CMPRxLEDSET::init()
{
	id.setID(LEDSET_ID);
	ApService::inst.payloadHandler.registerDataHandler(this);
}

