/*
 * CMPDataHandlerTx.cpp
 *
 *  Created on: Sep 3, 2017
 *      Author: bzachmann
 */

#include "CMPDataHandlerTx.h"

void CMPDataHandlerTx::run()
{
	timer.run();
	if(timer.getTimeMs() > sendRate)
	{
		sendFlag = true;
		timer.reset();
	}
}

void CMPDataHandlerTx::manualFlagToSend()
{
	sendFlag = true;
}

void CMPDataHandlerTx::clearSendFlag()
{
	sendFlag = false;
}

bool CMPDataHandlerTx::getSendFlag()
{
	return sendFlag;
}
