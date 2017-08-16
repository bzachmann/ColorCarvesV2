/*
 * CMPRxINFLUSET.cpp
 *
 *  Created on: Aug 15, 2017
 *      Author: Boston
 */

#include "CMPRxINFLUSET.h"
#include "apservice.h"
#include "apmain.h"

#define ENABLE_DC					(0x03)
#define MASK_ENABLE					(0x03)
#define SHIFT_OFFSET_ENABLE			(0)
#define SHIFT_BRIGHTNESS_ENABLE		(2)
#define SHIFT_PATTERN_ENABLE		(4)

CMPRxINFLUSET::CMPRxINFLUSET() :
	CMPDataHandler()
{

}

void CMPRxINFLUSET::callback(CMPData * data)
{
	uint8_t tempByte = (data->getByte(0) >> SHIFT_OFFSET_ENABLE) & MASK_ENABLE;
	if(tempByte == 0)
	{
		ApMain::inst.ledStrip.setOffsetInfluencedEnabled(false);
	}
	else if(tempByte == 1)
	{
		ApMain::inst.ledStrip.setOffsetInfluencedEnabled(true);
	}

	tempByte = (data->getByte(0) >> SHIFT_BRIGHTNESS_ENABLE) & MASK_ENABLE;
	if(tempByte == 0)
	{
		ApMain::inst.ledStrip.setBrightnessInfluencedEnabled(false);
	}
	else if(tempByte == 1)
	{
		ApMain::inst.ledStrip.setBrightnessInfluencedEnabled(true);
	}

	tempByte = (data->getByte(0) >> SHIFT_PATTERN_ENABLE) & MASK_ENABLE;
	if(tempByte == 0)
	{
		ApMain::inst.ledStrip.setPatternInfluencedEnabled(false);
	}
	else if(tempByte == 1)
	{
		ApMain::inst.ledStrip.setPatternInfluencedEnabled(true);
	}
}

void CMPRxINFLUSET::init()
{
	id.setID(INFLUSET_ID);
	ApService::inst.payloadHandler.registerDataHandler(this);
}

