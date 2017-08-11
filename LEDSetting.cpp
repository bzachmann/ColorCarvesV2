/*
 * LEDSetting.cpp
 *
 *  Created on: Aug 10, 2017
 *      Author: Boston
 */

#include "LEDSetting.h"

#define UNIFIED_VALUE_MIN			(0)
#define UNIFIED_VALUE_MAX			(765)

#define RED_FUNCTION_SHIFT			(0)
#define GREEN_FUNCTION_SHIFT		(255)
#define BLUE_FUNCTION_SHIFT			(510)

void LEDSetting::setState(bool const &value)
{
	state = value;
}

void LEDSetting::setOffset(uint16_t const &value)
{
	if(value <= UNIFIED_VALUE_MAX)
	{
		offset = value;
	}
}

void LEDSetting::getRGB(uint16_t const & baseOffset, uint8_t &r, uint8_t &g, uint8_t &b)
{
	uint16_t combinedOffset = baseOffset + offset;

	if(state)
	{
		r = colorFunc(combinedOffset, COLOR_RED);
		g = colorFunc(combinedOffset, COLOR_GREEN);
		b = colorFunc(combinedOffset, COLOR_BLUE);
	}
	else
	{
		r = 0;
		g = 0;
		b = 0;
	}
}

uint8_t LEDSetting::baseFunc(uint16_t value)
{
	uint16_t normalizedValue = value % 765;

	uint8_t retVal = 0;
	if(normalizedValue <= 255)
	{
		retVal = value;
	}
	else if((normalizedValue > 255) && (normalizedValue <= 510))
	{
		retVal = 510 - value;
	}
	else
	{
		retVal = 0;
	}

}

uint8_t LEDSetting::colorFunc(uint16_t value, color_t color)
{
	uint8_t retVal = 0;

	switch(color)
	{
	case COLOR_RED:
		retVal = baseFunc(value + RED_FUNCTION_SHIFT);
		break;
	case COLOR_GREEN:
		retVal = baseFunc(value + GREEN_FUNCTION_SHIFT);
		break;
	case COLOR_BLUE:
		retVal = baseFunc(value + BLUE_FUNCTION_SHIFT);
		break;
	default:
		break;
	}

	return retVal;
}
