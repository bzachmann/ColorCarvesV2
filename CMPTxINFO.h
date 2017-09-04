/*
 * CMPTxINFO.h
 *
 *  Created on: Sep 3, 2017
 *      Author: bzachmann
 */

#ifndef CMPTXINFO_H_
#define CMPTXINFO_H_

#include "CMPDataHandlerTx.h"


class CMPTxINFO: public CMPDataHandlerTx
{
public:
	CMPTxINFO();
	void callback(CMPData * data) override;
	void init();

	void setSpeed(float mpers);
	void setTiltAngle(float degrees);

private:
	float speed;
	float tiltAngle;

};

#endif /* CMPTXINFO_H_ */
