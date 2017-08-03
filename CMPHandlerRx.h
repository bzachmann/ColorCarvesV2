#ifndef CMPHANDLERRX_H_
#define CMPHANDLERRX_H_

#include "fifo.h"
#include "cmpmessage.h"
#include "cmpmessageobjectrx.h"

#define CMP_MESSAGE_FIFO_SIZE				(10)
#define CMP_REGISTERED_OBJECTS_SIZE			(10)
#define CMP_BYTE_BUFFER_LENGTH				(CMP_PAYLOAD_SIZE + CMP_ID_SIZE)

class CMPHandlerRx {
public:

	CMPHandlerRx();
	void init();
	void run();

	void registerCMPObject(CMPMessageObjectRx const * object);

public:
	uint8_t byteBuffer[CMP_BYTE_BUFFER_LENGTH];

	Fifo<CMPMessage, CMP_MESSAGE_FIFO_SIZE> messageFifo;

	CMPMessageObjectRx* registeredObjects[CMP_REGISTERED_OBJECTS_SIZE];
	uint8_t registeredObjectsIndex;
};

#endif /* CMPHANDLERRX_H_ */
