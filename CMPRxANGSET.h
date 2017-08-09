/*
 * CMPRxANGSET.h
 *
 *  Created on: Aug 8, 2017
 *      Author: Boston
 */

#ifndef CMPRXANGSET_H_
#define CMPRXANGSET_H_

#include "CMPDataHandler.h"

#define ANGSET_ID		(0x11)

class CMPRxANGSET: public CMPDataHandler
{
public:
	CMPRxANGSET();
	void callback(CMPData * data) override;
	void init();
};

#endif /* CMPRXANGSET_H_ */
