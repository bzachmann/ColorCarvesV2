/*
 * ApCMP.h
 *
 *  Created on: Aug 5, 2017
 *      Author: bzachmann
 */

#ifndef APCMP_H_
#define APCMP_H_

class ApCMP {
public:
	ApCMP();
	void init();
	void run();

public:
	static ApCMP * inst;
};

#endif /* APCMP_H_ */
