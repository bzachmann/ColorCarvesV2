#ifndef CMPPORTRX_H_
#define CMPPORTRX_H_

#include "stream.h"
#include "fifo.h"
#include "cmpmessage.h"

#define CMP_PORT_RX_PAYLOAD_FIFO_SIZE		(10)

class CMPPortRx {
public:
	CMPPortRx(Stream const * stream);
	void init();
	void run();

public:
	Stream * stream;

	uint8_t byteBuffer[CMP_PAYLOAD_SIZE];
	Fifo<CMPPayload, CMP_PORT_RX_PAYLOAD_FIFO_SIZE> messageFifo;

};

#endif /* CMPPORTRX_H_ */
