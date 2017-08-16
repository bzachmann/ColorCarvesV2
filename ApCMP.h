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
#include "cmprxspeedset.h"
#include "cmprxspecset.h"
#include "cmprxbaseset.h"
#include "cmprxinfluset.h"

class ApCMP {
public:
	ApCMP();
	void init();
	void run();

public:
	static ApCMP inst;

	CMPRxLEDSET ledsetMsgRx;
	CMPRxANGSET angsetMsgRx;
	CMPRxSPEEDSET speedsetMsgRx;
	CMPRxSPECSET specsetMsgRx;
	CMPRxBASESET basesetMsgRx;
	CMPRxINFLUSET influsetMsgRx;
};

#endif /* APCMP_H_ */
