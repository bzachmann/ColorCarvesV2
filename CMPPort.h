/*
 * CMPPort.h
 *
 *  Created on: Aug 2, 2017
 *      Author: Boston
 */

#ifndef CMPPORT_H_
#define CMPPORT_H_

#include "CMPHandlerRx.h"
#include "stream.h"

#define CMP_PORT_STREAM_BAUD_RATE		(9600)

class CMPPort {
public:
	CMPPort(Stream const * stream);
	void init();
	void run();

public:
	Stream * stream;

	static CMPPort inst;

	CMPHandlerRx rxHandler;
};

#endif /* CMPPORT_H_ */
