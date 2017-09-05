/*
 * CMPRxRQST.h
 *
 *  Created on: Sep 4, 2017
 *      Author: bzachmann
 */

#ifndef CMPRXRQST_H_
#define CMPRXRQST_H_

#include "CMPDataHandler.h"

#define RQST_ID			(0x16)

class CMPRxRQST: public CMPDataHandler
{
public:
	CMPRxRQST();
	void callback(CMPData * data) override;
	void init();
};

#endif /* CMPRXRQST_H_ */
