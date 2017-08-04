/*
 * CMPMessage.h
 *
 *  Created on: Aug 2, 2017
 *      Author: Boston
 */
#ifndef CMPMESSAGE_H_
#define CMPMESSAGE_H_

#include <stdint.h>

#define CMP_ID_SIZE				(1)
#define CMP_DATA_SIZE			(3)
#define CMP_PAYLOAD_SIZE		(CMP_DATA_SIZE + CMP_ID_SIZE)

class CMPID {
public:
	CMPID();
	uint8_t getID();
	void setID(uint8_t id);
private:
	uint8_t id;
};

class CMPData  {
public:
	CMPData();
	uint8_t getByte(uint8_t index);
	void setByte(uint8_t index);

private:
	uint8_t data[CMP_DATA_SIZE];
};

class CMPPayload {
public:
	CMPPayload();

private:
	CMPID id;
	CMPData data;
};

#endif /* CMPMESSAGE_H_ */
