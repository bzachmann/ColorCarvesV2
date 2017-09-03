/*
 * CMPPayloadHandlerTx.h
 *
 *  Created on: Sep 3, 2017
 *      Author: bzachmann
 */

#ifndef CMPPAYLOADHANDLERTX_H_
#define CMPPAYLOADHANDLERTX_H_

#include "cmpporttx.h"
#include "cmpdatahandlertx.h"

class CMPPayloadHandlerTx {
public:
	CMPPayloadHandlerTx();
	void init(CMPPortTx const * portTx);
	void run();

	void registerDataHandler(CMPDataHandlerTx * newHandler);
	bool sendNow(CMPPayload payload);

private:
	bool schedule(CMPID id, CMPData data);

private:
	CMPPortTx * portTx;
	CMPDataHandlerTx * dataHandler;
};

#endif /* CMPPAYLOADHANDLERTX_H_ */
