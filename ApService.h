/*
 * ApService.h
 *
 *  Created on: Aug 5, 2017
 *      Author: bzachmann
 */

#ifndef APSERVICE_H_
#define APSERVICE_H_

#include "cmpport.h"
#include "cmppayloadhandlerrx.h"

#define UNIFIED_VALUE_LOW		(0)
#define UNIFIED_VALUE_HIGH		(765)

class ApService {
public:
	ApService();

	void init();
	void run();

public:
	static ApService inst;

	CMPPort cmpPort;
	CMPPayloadHandlerRx payloadHandlerRx;
};

#endif /* APSERVICE_H_ */
