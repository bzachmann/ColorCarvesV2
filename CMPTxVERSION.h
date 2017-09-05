/*
 * CMPTxVERSION.h
 *
 *  Created on: Sep 3, 2017
 *      Author: bzachmann
 */

#ifndef CMPTXVERSION_H_
#define CMPTXVERSION_H_

#include "CMPDataHandlerTx.h"

#define VERSION_ID				(0x80)

class CMPTxVERSION: public CMPDataHandlerTx
{
public:
	CMPTxVERSION();
	void callback(CMPData * data) override;
	void init(uint8_t const &type, uint8_t const &minor, uint8_t const &major);

private:

	uint8_t versionType;
	uint8_t versionMinor;
	uint8_t versionMajor;
};

#endif /* CMPTXVERSION_H_ */
