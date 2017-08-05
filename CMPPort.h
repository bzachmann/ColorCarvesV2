/*
 * CMPPort.h
 *
 *  Created on: Aug 4, 2017
 *      Author: bzachmann
 */

#ifndef CMPPORT_H_
#define CMPPORT_H_

#include "cmpportrx.h"
#include "stream.h"

class CMPPort {
public:
	CMPPort();
	void init(Stream const * stream);
	void run();

public:

	CMPPortRx rx;
};

#endif /* CMPPORT_H_ */
