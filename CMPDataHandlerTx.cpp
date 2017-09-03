/*
 * CMPDataHandlerTx.cpp
 *
 *  Created on: Sep 3, 2017
 *      Author: bzachmann
 */

#include "CMPDataHandlerTx.h"

void CMPDataHandlerTx::run()
{
	if(timer.getTimeMs() > sendRate)
	{
		sendFlag = true;
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
