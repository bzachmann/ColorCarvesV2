/*
 * CMPPortTx.h
 *
 *  Created on: Sep 3, 2017
 *      Author: bzachmann
 */

#ifndef CMPPORTTX_H_
#define CMPPORTTX_H_

#include "stream.h"
#include "fifo.h"
#include "cmpmessage.h"
#include "timer.h"

#define CMP_PORT_TX_PAYLOAD_FIFO_SIZE				(10)
#define CMP_PORT_TX_TRANSMIT_RATE					(200)
#define CMP_PORT_TX_MAX_MSGS_PER_TRANSMIT			(4)
#define CMP_PORT_TX_MAX_SEND_BUFFER_SIZE			(CMP_PORT_TX_MAX_MSGS_PER_TRANSMIT * CMP_MESSAGE_SIZE)

class CMPPortTx {
public:
	CMPPortTx();
	void init(Stream const * stream);
	void run();

	bool enqueue(CMPPayload payload);

private:
	Stream * stream;

	uint8_t byteBuffer[CMP_PORT_TX_MAX_SEND_BUFFER_SIZE];
	Fifo<CMPPayload, CMP_PORT_TX_PAYLOAD_FIFO_SIZE> payloadFifo;

	Timer transmissionTimer;
};

#endif /* CMPPORTTX_H_ */
