/*
 * CMPRxSPEEDSET.h
 *
 *  Created on: Aug 15, 2017
 *      Author: Boston
 */

#ifndef CMPRXSPEEDSET_H_
#define CMPRXSPEEDSET_H_

#include "cmpdatahandler.h"

#define SPEEDSET_ID		(0x12)

class CMPRxSPEEDSET: public CMPDataHandler
{
public:
	CMPRxSPEEDSET();
	void callback(CMPData * data) override;
	void init();
};

#endif /* CMPRXSPEEDSET_H_ */
