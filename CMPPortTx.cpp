/*
 * CMPPortTx.cpp
 *
 *  Created on: Sep 3, 2017
 *      Author: bzachmann
 */

#include "CMPPortTx.h"

CMPPortTx::CMPPortTx() :
	stream(0),
	byteBuffer({0}),
	payloadFifo(),
	transmissionTimer()
{

}

void CMPPortTx::init(Stream const * stream)
{
	this->stream = stream;
	payloadFifo.flush();
	transmissionTimer.reset();
	transmissionTimer.start();
}

void CMPPortTx::run()
{
	transmissionTimer.run();
	if((transmissionTimer.getTimeMs() > CMP_PORT_TX_TRANSMIT_RATE) && (payloadFifo.notEmpty()))
	{
		uint8_t payloadIndex = 0;
		while(payloadFifo.notEmpty() && (payloadIndex < CMP_PORT_TX_MAX_MSGS_PER_TRANSMIT))
		{
			CMPPayload payload;
			payloadFifo.get(payload);
			byteBuffer[(payloadIndex * CMP_MESSAGE_SIZE) + 0] = CMP_MESSAGE_HEADER_BYTE;
			byteBuffer[(payloadIndex * CMP_MESSAGE_SIZE) + 1] = payload.id.getID();
			byteBuffer[(payloadIndex * CMP_MESSAGE_SIZE) + 2] = payload.data.getByte(2);
			byteBuffer[(payloadIndex * CMP_MESSAGE_SIZE) + 3] = payload.data.getByte(1);
			byteBuffer[(payloadIndex * CMP_MESSAGE_SIZE) + 4] = payload.data.getByte(0);

			payloadIndex++;
		}

		stream->write(byteBuffer, (payloadIndex * CMP_MESSAGE_SIZE));

		transmissionTimer.reset();
	}
}

bool CMPPortTx::enqueue(CMPPayload payload)
{
	bool retVal = false;
	if(payloadFifo.notFull())
	{
		payloadFifo.put(payload);
		retVal = true;
	}
	return retVal;
}


