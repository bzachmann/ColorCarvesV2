/*
 * CMPDataHandlerTx.h
 *
 *  Created on: Sep 3, 2017
 *      Author: bzachmann
 */

#ifndef CMPDATAHANDLERTX_H_
#define CMPDATAHANDLERTX_H_

#include "cmpmessage.h"
#include "linkedlist.h"
#include "timer.h"

class CMPDataHandlerTx : public LinkedList<CMPDataHandlerTx>
{
public:
	CMPDataHandlerTx() :
		LinkedList<CMPDataHandlerTx>(),
		id(),
		sendFlag(false),
		sendRate(0xFFFF),
		timer(){}
	virtual void callback(CMPData * data) {(void) data;}
	void run();

	void manualFlagToSend();
	void clearSendFlag();
	bool getSendFlag();

public:
	CMPID id;

private:
	bool sendFlag;
	uint16_t sendRate;

	Timer timer;
};

#endif /* CMPDATAHANDLERTX_H_ */
