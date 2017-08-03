/*
 * CMPID.h
 *
 *  Created on: Aug 2, 2017
 *      Author: Boston
 */

#ifndef CMPID_H_
#define CMPID_H_

#include <stdint.h>

#define CMP_ID_SIZE		(1)

class CMPID {
public:
	CMPID();
	uint8_t getID();
	void setID(uint8_t id);
private:
	uint8_t id;
};
#endif /* CMPID_H_ */
