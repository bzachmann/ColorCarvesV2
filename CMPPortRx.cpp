#include "CMPPortRx.h"

CMPPortRx::CMPPortRx() :
		stream(0),
		byteBuffer({0}),
		payloadFifo(),
		headerRcvd(false),
		byteBufferIndex(0)
{

}

void CMPPortRx::init(Stream const * stream)
{
	this->stream = stream;
	payloadFifo.flush();
	byteBufferIndex = 0;
	headerRcvd = false;
}

void CMPPortRx::run()
{
	if(stream != 0)
	{
		while(stream->available() && payloadFifo.notFull())
		{
			uint8_t tempByte = stream->read();

			if(!headerRcvd && (tempByte == CMP_MESSAGE_HEADER_BYTE))
			{
				headerRcvd = true;
			}
			else if(headerRcvd)
			{
				addToByteBuffer(tempByte);
				if(byteBufferIndex == CMP_PAYLOAD_SIZE)
				{
					parseAndQueue();
				}
			}
		}
	}
}

bool CMPPortRx::available()
{
	return payloadFifo.notEmpty();
}

CMPPayload CMPPortRx::read()
{
	CMPPayload tempPayload;
	payloadFifo.get(tempPayload);
	return tempPayload;
}

void CMPPortRx::addToByteBuffer(uint8_t value)
{
	if(byteBufferIndex < CMP_PAYLOAD_SIZE)
	{
		byteBuffer[byteBufferIndex] = value;
		byteBufferIndex++;
	}
}

void CMPPortRx::parseAndQueue()
{
#warning "todo - this function is dependant on the layout of the message.  Switch this to a function call handled by Payload.  This will keep the CMPPortRx separate from message layout"
	//Message always comes accross in the following order:
	//Header, ID, Byte2, Byte1, Byte0.
	//Pack accordingly
	CMPPayload tempPayload;
	tempPayload.id.setID(byteBuffer[0]);
	tempPayload.data.setByte(2, byteBuffer[1]);
	tempPayload.data.setByte(1, byteBuffer[2]);
	tempPayload.data.setByte(0, byteBuffer[3]);

	payloadFifo.put(tempPayload);
	resetBuffer();
}

void CMPPortRx::resetBuffer()
{
	byteBufferIndex = 0;
	headerRcvd = false;
}

