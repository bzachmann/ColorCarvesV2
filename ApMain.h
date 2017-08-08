/*
 * ApMain.h
 *
 *  Created on: Aug 2, 2017
 *      Author: Boston
 */

#ifndef APMAIN_H_
#define APMAIN_H_

class ApMain {
public:
	ApMain();
	void init();
	void run();

public:
	static ApMain inst;
};

#endif /* APMAIN_H_ */
