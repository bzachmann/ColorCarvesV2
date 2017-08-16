/*
 * CMPRxSPECSET.h
 *
 *  Created on: Aug 15, 2017
 *      Author: Boston
 */

#ifndef CMPRXSPECSET_H_
#define CMPRXSPECSET_H_

#include "cmpdatahandler.h"

#define SPECSET_ID		(0x13)

class CMPRxSPECSET : public CMPDataHandler
{
public:
	CMPRxSPECSET();
	void callback(CMPData * data) override;
	void init();
};

#endif /* CMPRXSPECSET_H_ */
