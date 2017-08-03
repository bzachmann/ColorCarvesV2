/*
 * CMPPort.h
 *
 *  Created on: Aug 2, 2017
 *      Author: Boston
 */

#ifndef CMPPORT_H_
#define CMPPORT_H_

#include "CMPHandlerRx.h"

class CMPPort {
public:
	CMPPort();
	void init();
	void run();

public:
	static CMPPort inst;

	CMPHandlerRx rxHandler;
};

#endif /* CMPPORT_H_ */
