#ifndef CMPPORTRX_H_
#define CMPPORTRX_H_

#include "stream.h"
#include "fifo.h"
#include "cmpmessage.h"

#define CMP_PORT_RX_PAYLOAD_FIFO_SIZE		(10)

class CMPPortRx {
public:
	CMPPortRx();
	void init(Stream const * stream);
	void run();

	bool available();
	CMPPayload read();

private:
	void addToByteBuffer(uint8_t value);
	void parseAndQueue();
	void resetBuffer();

public:
	Stream * stream;

	uint8_t byteBuffer[CMP_PAYLOAD_SIZE];

	Fifo<CMPPayload, CMP_PORT_RX_PAYLOAD_FIFO_SIZE> messageFifo;

	bool headerRcvd;
	uint8_t byteBufferIndex;

};

#endif /* CMPPORTRX_H_ */
