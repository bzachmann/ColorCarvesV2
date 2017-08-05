/*
 * CMPRxLEDSET.h
 *
 *  Created on: Aug 5, 2017
 *      Author: bzachmann
 */

#ifndef CMPRXLEDSET_H_
#define CMPRXLEDSET_H_

#include "cmpdatahandler.h"

class CMPRxLEDSET : public CMPDataHandler
{
public:
	CMPRxLEDSET();
	void callback(CMPData * data) override;
	void init();
};

#endif /* CMPRXLEDSET_H_ */
