/*
 * CMPRxRQST.cpp
 *
 *  Created on: Sep 4, 2017
 *      Author: bzachmann
 */

#include "CMPRxRQST.h"
#include "apservice.h"
#include "apcmp.h"
#include "cmptxversion.h"

CMPRxRQST::CMPRxRQST() :
	CMPDataHandler()
{


}

void CMPRxRQST::callback(CMPData * data)
{
	uint8_t requestedId = data->getByte(0);

	switch(requestedId)
	{
	case VERSION_ID:
		ApCMP::inst.versionMsgTx.manualFlagToSend();
		break;
	default:
		break;
	}
}

void CMPRxRQST::init()
{
	id.setID(RQST_ID);
	ApService::inst.payloadHandlerRx.registerDataHandler(this);
}
