/*
 * CMPRxBASESET.h
 *
 *  Created on: Aug 15, 2017
 *      Author: Boston
 */

#ifndef CMPRXBASESET_H_
#define CMPRXBASESET_H_

#include "cmpdatahandler.h"

#define BASESET_ID		(0x14)

class CMPRxBASESET : public CMPDataHandler
{
public:
	CMPRxBASESET();
	void callback(CMPData * data) override;
	void init();
};

#endif /* CMPRXBASESET_H_ */
