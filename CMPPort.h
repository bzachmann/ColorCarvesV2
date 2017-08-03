/*
 * CMPPort.h
 *
 *  Created on: Aug 2, 2017
 *      Author: Boston
 */
#ifndef CMPPORT_H_
#define CMPPORT_H_

#include "fifo.h"
#include "cmpmessage.h"

#define CMP_MESSAGE_FIFO_SIZE		(10)


class CMPPort {
public:


	//TODO rename to CMPHandlerRx
	//add new class CMPPort that hodls the CMPHandlerRx and Tx

	CMPPort();
	void init();
	void run();

public:
	static CMPPort inst;

	Fifo<CMPMessage, CMP_MESSAGE_FIFO_SIZE> messageFifo;
};

#endif /* CMPPORT_H_ */
