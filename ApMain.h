/*
 * ApMain.h
 *
 *  Created on: Aug 2, 2017
 *      Author: Boston
 */

#ifndef APMAIN_H_
#define APMAIN_H_

#include "tiltsensor.h"

class ApMain {
public:
	ApMain();
	void init();
	void run();

public:
	static ApMain inst;

	TiltSensor tiltSensor;
};

#endif /* APMAIN_H_ */
