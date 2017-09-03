/*
 * CMPTxINFO.cpp
 *
 *  Created on: Sep 3, 2017
 *      Author: bzachmann
 */

#include "CMPTxINFO.h"
#include "apservice.h"

#define INFO_ID			(0x81)
#define INFO_SEND_RATE	(250)

CMPTxINFO::CMPTxINFO() :
	CMPDataHandlerTx()
{

}

void CMPTxINFO::init()
{
	id.setID(INFO_ID);
	sendRate = INFO_SEND_RATE;

	ApService::inst.payloadHandlerTx.registerDataHandler(this);

	timer.reset();
	timer.start();
}
