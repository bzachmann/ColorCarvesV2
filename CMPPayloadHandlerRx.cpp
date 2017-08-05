#include "CMPPayloadHandlerRx.h"

CMPPayloadHandlerRx::CMPPayloadHandlerRx() :
	portRx(0),
	dataHandler(0)
{

}

void CMPPayloadHandlerRx::init(CMPPortRx const * portRx)
{
	this->portRx = portRx;
}

void CMPPayloadHandlerRx::run()
{
	if(portRx != 0)
	{
		while(portRx->available())
		{
			CMPPayload tempPayload = portRx->read();
			processPayload(&tempPayload);
		}
	}
}


void CMPPayloadHandlerRx::registerDataHandler(CMPDataHandler * newHandler)
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

void CMPPayloadHandlerRx::processPayload(CMPPayload * payload)
{
	CMPDataHandler * currentHandler = dataHandler;
	while(currentHandler != 0)
	{
		if(currentHandler->id.getID() == payload->id.getID())
		{
			currentHandler->callback(&(payload->data));
		}

		currentHandler = currentHandler->next();
	}

}
