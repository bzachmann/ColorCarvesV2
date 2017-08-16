/*
 * CMPRxINFLUSET.h
 *
 *  Created on: Aug 15, 2017
 *      Author: Boston
 */

#ifndef CMPRXINFLUSET_H_
#define CMPRXINFLUSET_H_

#include "CMPDataHandler.h"

#define INFLUSET_ID		(0x15)

class CMPRxINFLUSET : public CMPDataHandler
{
public:
	CMPRxINFLUSET();
	void callback(CMPData * data) override;
	void init();
};

#endif /* CMPRXINFLUSET_H_ */
