/*
 * CMPRxLEDSET.cpp
 *
 *  Created on: Aug 5, 2017
 *      Author: bzachmann
 */

#include "cmprxledset.h"
#include "apservice.h"
#include "apmain.h"

CMPRxLEDSET::CMPRxLEDSET() :
	CMPDataHandler()
{

}

void CMPRxLEDSET::callback(CMPData * data)
{
	uint16_t ledOffset = (((uint16_t)data->getByte(1) & 0x03) << 8) | ((uint16_t)data->getByte(0) & 0xFF);
	uint8_t ledIndex = data->getByte(1) >> 2;
	bool ledState = (data->getByte(2) & 0x01) > 0;

	ApMain::inst.ledStrip.setLEDState(ledIndex, ledState);
	ApMain::inst.ledStrip.setLEDOffset(ledIndex, ledOffset);
}
void CMPRxLEDSET::init()
{
	id.setID(LEDSET_ID);
	ApService::inst.payloadHandler.registerDataHandler(this);
}

