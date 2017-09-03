/*
 * CMPMessage.h
 *
 *  Created on: Aug 2, 2017
 *      Author: Boston
 */
#ifndef CMPMESSAGE_H_
#define CMPMESSAGE_H_

#include <stdint.h>

#define CMP_MESSAGE_HEADER_BYTE	(0xE1)
#define CMP_ID_SIZE				(1)
#define CMP_DATA_SIZE			(3)
#define CMP_PAYLOAD_SIZE		(CMP_DATA_SIZE + CMP_ID_SIZE)
#define CMP_MESSAGE_SIZE		(CMP_PAYLOAD_SIZE + 1)

class CMPID {
public:
	CMPID() : m_id(0xFF) {}
	uint8_t getID() { return m_id; }
	void setID(uint8_t id) {m_id = id;}
private:
	uint8_t m_id;
};

class CMPData  {
public:
	CMPData() : data({0}) {}

	uint8_t getByte(uint8_t index)
	{
		uint8_t retVal = 0;
		if(index < CMP_DATA_SIZE)
		{
			retVal = data[index];
		}
		return retVal;
	}

	void setByte(uint8_t index, uint8_t value)
	{
		if(index < CMP_DATA_SIZE)
		{
			data[index] = value;
		}
	}

private:
	uint8_t data[CMP_DATA_SIZE];
};

class CMPPayload {
public:
	CMPPayload() : id(), data () {}

public:
	CMPID id;
	CMPData data;
};

#endif /* CMPMESSAGE_H_ */
