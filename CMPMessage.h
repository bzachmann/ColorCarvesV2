/*
 * CMPMessage.h
 *
 *  Created on: Aug 2, 2017
 *      Author: Boston
 */
#ifndef CMPMESSAGE_H_
#define CMPMESSAGE_H_

#include <stdint.h>
#include "cmpid.h"
#include "cmppayload.h"

class CMPMessage {
public:
	CMPMessage();

private:
	CMPID id;
	CMPPayload data;
};

#endif /* CMPMESSAGE_H_ */
