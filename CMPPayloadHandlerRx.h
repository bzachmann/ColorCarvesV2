#ifndef CMPPAYLOADHANDLERRX_H_
#define CMPPAYLOADHANDLERRX_H_

#include <Stream.h>

#include "cmpportrx.h"
#include "cmpmessage.h"
#include "cmpdatahandler.h"
#include "linkedlist.h"

//TODO create linked list
//template <class T> class LinkedList;

class CMPPayloadHandlerRx {
public:
	CMPPayloadHandlerRx(CMPPortRx const * portRx);
	void init();
	void run();

	void registerDataHandler(CMPDataHandler * newHandler);

public:
	CMPPortRx * portRx;

	LinkedList<CMPDataHandler> * dataHandler;
};

#endif /* CMPPAYLOADHANDLERRX_H_ */
