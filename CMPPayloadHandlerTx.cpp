/*
 * CMPPayloadHandlerTx.cpp
 *
 *  Created on: Sep 3, 2017
 *      Author: bzachmann
 */

#include "CMPPayloadHandlerTx.h"

CMPPayloadHandlerTx::CMPPayloadHandlerTx() :
	portTx(0),
	dataHandler(0)
{

}

void CMPPayloadHandlerTx::init(CMPPortTx const * portTx)
{
	this->portTx = portTx;
}

void CMPPayloadHandlerTx::run()
{
	if(portTx != 0)
	{
		CMPDataHandlerTx * currentHandler = dataHandler;
		while(currentHandler != 0)
		{
			if(currentHandler->getSendFlag())
			{
				CMPData data;
				currentHandler->callback(&data);
				if(schedule(currentHandler->id, data))
				{
					currentHandler->clearSendFlag();
				}
			}

			currentHandler = currentHandler->next();
		}
	}
}

void CMPPayloadHandlerTx::registerDataHandler(CMPDataHandlerTx * newHandler)
{
	if(dataHandler == 0)
	{
		dataHandler = newHandler;
	}
	else
	{
		dataHandler->add(newHandler);
	}
}

bool CMPPayloadHandlerTx::sendNow(CMPPayload payload)
{
	bool retVal = false;
	if(portTx != 0)
	{
		retVal = portTx->enqueue(payload);
	}
	return retVal;
}

bool CMPPayloadHandlerTx::schedule(CMPID id, CMPData data)
{
	bool retVal = false;

	if((portTx != 0))
	{
		CMPPayload payload;
		payload.id = id;
		payload.data = data;

		retVal = portTx->enqueue(payload);
	}

	return retVal;
}
