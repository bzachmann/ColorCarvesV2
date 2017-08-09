/*
 * ApCMP.h
 *
 *  Created on: Aug 5, 2017
 *      Author: bzachmann
 */

#ifndef APCMP_H_
#define APCMP_H_

#include "cmprxledset.h"
#include "cmprxangset.h"

class ApCMP {
public:
	ApCMP();
	void init();
	void run();

public:
	static ApCMP inst;

	CMPRxLEDSET ledsetMsgRx;
	CMPRxANGSET angsetMsgRx;
};

#endif /* APCMP_H_ */
