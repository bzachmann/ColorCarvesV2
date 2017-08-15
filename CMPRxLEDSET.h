/*
 * CMPRxLEDSET.h
 *
 *  Created on: Aug 5, 2017
 *      Author: bzachmann
 */

#ifndef CMPRXLEDSET_H_
#define CMPRXLEDSET_H_

#include "cmpdatahandler.h"

#define LEDSET_ID		(0x10)

class CMPRxLEDSET : public CMPDataHandler
{
public:
	CMPRxLEDSET();
	void callback(CMPData * data) override;
	void init();

private:
	void setLED(uint8_t const &ledIndex, uint8_t const &state, uint16_t const &offset);
	void setAllLEDs(uint8_t const &state, uint16_t const &offset);
};

#endif /* CMPRXLEDSET_H_ */
