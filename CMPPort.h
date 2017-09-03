/*
 * CMPPort.h
 *
 *  Created on: Aug 4, 2017
 *      Author: bzachmann
 */

#ifndef CMPPORT_H_
#define CMPPORT_H_

#include "cmpportrx.h"
#include "cmpporttx.h"
#include "stream.h"

class CMPPort {
public:
	CMPPort() : tx(), rx() {}
	void init(Stream const * stream);
	void run();

public:

	CMPPortTx tx;
	CMPPortRx rx;
};

#endif /* CMPPORT_H_ */
