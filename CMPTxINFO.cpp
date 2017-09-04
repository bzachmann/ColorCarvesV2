/*
 * CMPTxINFO.cpp
 *
 *  Created on: Sep 3, 2017
 *      Author: bzachmann
 */

#include "CMPTxINFO.h"
#include "apservice.h"

#define INFO_ID			(0x81)
#define INFO_SEND_RATE	(250)

#define SCALE_ANGLE		(10)
#define MASK_ANGLE		(0x3F)
#define SCALE_SPEED		(100)
#define MASK_SPEED		(0x3F)

CMPTxINFO::CMPTxINFO() :
	CMPDataHandlerTx(),
	speed(0.0f),
	tiltAngle(0.0f)
{

}

void CMPTxINFO::callback(CMPData * data)
{
	uint16_t tempAngle = tiltAngle * SCALE_ANGLE;
	tempAngle &= MASK_ANGLE;

	uint16_t tempSpeed = speed * SCALE_SPEED;
	tempSpeed &= MASK_SPEED;
	tempSpeed = tempSpeed << 2;

	uint8_t tempByte = tempAngle & 0xFF;
	data->setByte(0, tempByte);
	tempByte = ((tempAngle >> 8) & 0x03) || (tempSpeed & 0xFC);
	data->setByte(1, tempByte);
	tempByte = (tempSpeed >> 8) & 0x1F;
	data->setByte(2, tempByte);
}

void CMPTxINFO::init()
{
	id.setID(INFO_ID);
	sendRate = INFO_SEND_RATE;

	ApService::inst.payloadHandlerTx.registerDataHandler(this);

	timer.reset();
	timer.start();
}

void CMPTxINFO::setSpeed(float mpers)
{
	speed = mpers;
}

void CMPTxINFO::setTiltAngle(float degrees)
{
	tiltAngle = degrees;
}
