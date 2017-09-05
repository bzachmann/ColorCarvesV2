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
#define OFFSET_ANGLE	(102.3f)
#define MASK_ANGLE		(0x0FFF)
#define SCALE_SPEED		(100)
#define MASK_SPEED		(0x0FFF)

CMPTxINFO::CMPTxINFO() :
	CMPDataHandlerTx(),
	speed(0.0f),
	tiltAngle(0.0f)
{

}

void CMPTxINFO::callback(CMPData * data)
{
	uint16_t tempAngle = ((uint16_t)((tiltAngle + OFFSET_ANGLE) * SCALE_ANGLE)) & MASK_ANGLE;
	uint16_t tempSpeed = ((uint16_t)(speed * SCALE_SPEED)) & MASK_SPEED;

	uint8_t tempByte = tempAngle & 0xFF;
	data->setByte(0, tempByte);
	tempByte = ((tempAngle >> 8) & 0x0F) | ((tempSpeed & 0x0F) << 4);
	data->setByte(1, tempByte);
	tempByte = (tempSpeed >> 4) & 0xFF;
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
