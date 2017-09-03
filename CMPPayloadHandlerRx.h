#ifndef CMPPAYLOADHANDLERRX_H_
#define CMPPAYLOADHANDLERRX_H_

#include "cmpportrx.h"
#include "cmpdatahandler.h"

class CMPPayloadHandlerRx {
public:
	CMPPayloadHandlerRx();
	void init(CMPPortRx const * portRx);
	void run();

	void registerDataHandler(CMPDataHandler * newHandler);

private:
	void processPayload(CMPPayload * payload);

#warning todo does this need to be public?
public:
	CMPPortRx * portRx;

	CMPDataHandler * dataHandler;
};

#endif /* CMPPAYLOADHANDLERRX_H_ */
