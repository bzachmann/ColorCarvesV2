/*
 * CMPPayload.h
 *
 *  Created on: Aug 2, 2017
 *      Author: Boston
 */

#ifndef CMPPAYLOAD_H_
#define CMPPAYLOAD_H_

#include <stdint.h>

#define CMP_PAYLOAD_SIZE		(3)

class CMPPayload  {
public:
	CMPPayload();
	uint8_t getByte(uint8_t index);
	void setByte(uint8_t index);

private:
	uint8_t data[CMP_PAYLOAD_SIZE];
};

#endif /* CMPPAYLOAD_H_ */
