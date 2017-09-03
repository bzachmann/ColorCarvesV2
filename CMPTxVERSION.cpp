/*
 * CMPTxVERSION.cpp
 *
 *  Created on: Sep 3, 2017
 *      Author: bzachmann
 */

#include "CMPTxVERSION.h"
#include "apservice.h"

#define VERSION_ID				(0x80)

CMPTxVERSION::CMPTxVERSION() :
	CMPDataHandlerTx(),
	versionType(0),
	versionMajor(0),
	versionMinor(0)
{

}

void CMPTxVERSION::callback(CMPData * data)
{
	data->setByte(0, versionMinor);
	data->setByte(1, versionMajor);
	data->setByte(2, versionType);
}

void CMPTxVERSION::init(uint8_t const &type, uint8_t const &minor, uint8_t const &major)
{
	versionType = type;
	versionMajor = major;
	versionMinor = minor;

	id.setID(VERSION_ID);

	ApService::inst.payloadHandlerTx.registerDataHandler(this);
}

