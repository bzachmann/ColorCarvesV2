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

class ApService {
public:
	ApService();

	void init();
	void run();

public:
	static ApService inst;

	CMPPort cmpPort;
	CMPPayloadHandlerRx payloadHandler;
};

#endif /* APSERVICE_H_ */
