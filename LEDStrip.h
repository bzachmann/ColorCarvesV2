/*
 * LEDStrip.h
 *
 *  Created on: Aug 9, 2017
 *      Author: Boston
 */

#ifndef LEDSTRIP_H_
#define LEDSTRIP_H_

#include <stdint.h>
#include <Adafruit_NeoPixel.h>
#include "ledsetting.h"

#define DEFAULT_CT_BRIGHTNESS		(50)
#define DEFAULT_CT_BASE_OFFSET		(382) //(765/2)
#define DEFAULT_CT_ON_INDEX			(0)
#define UNIFIED_VALUE_MIN			(0)
#define UNIFIED_VALUE_MAX			(765)
#define UINT8_MIN					(0)
#define UINT8_MAX					(255)

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

template <uint8_t numLeds, uint8_t pin> class LEDStrip
{
public:
	LEDStrip<numLeds, pin>() :
		leds(numLeds, pin),
		ledSettings(),
		brightnessInfluencedEnabled(false),
		offsetInfluencedEnabled(false),
		patternInfluencedEnabled(false),
		influencedBrightness(DEFAULT_CT_BRIGHTNESS),
		influencedBaseOffset(DEFAULT_CT_BASE_OFFSET),
		unInfluencedBrightness(DEFAULT_CT_BRIGHTNESS),
		unInfluencedBaseOffset(DEFAULT_CT_BASE_OFFSET),
		onIndex(DEFAULT_CT_ON_INDEX){}

	void init()
	{
		leds.begin();
	}

	void run()
	{
		updateBrightness();
		updateColors();
		leds.show();
	}

	void setBrightnessInfluencedEnabled(bool const &value) {brightnessInfluencedEnabled = value;}
	void setOffsetInfluencedEnabled(bool const &value) {offsetInfluencedEnabled = value;}
	void setPatternInfluencedEnabled(bool const &value) {patternInfluencedEnabled = value;}
	void setInfluencedBrightness(uint8_t const &brightness) {influencedBrightness = brightness;}
	void setInfluencedBrightnessUnified(uint16_t const &brightness)
		{influencedBrightness = convertUnified(brightness, UNIFIED_VALUE_MIN, UNIFIED_VALUE_MAX, UINT8_MIN, UINT8_MAX);}
	void setInfluencedBaseOffset(uint16_t const &offset) {influencedBaseOffset = min(offset, UNIFIED_VALUE_MAX);}
	void setUnInfluencedBrightness(uint8_t const &brightness) {unInfluencedBrightness = brightness;}
	void setUnInfluencedBrightnessUnified(uint16_t const &brightness)
			{unInfluencedBrightness = convertUnified(brightness, UNIFIED_VALUE_MIN, UNIFIED_VALUE_MAX, UINT8_MIN, UINT8_MAX);}
	void setUnInfluencedBaseOffset(uint16_t const &offset) {unInfluencedBaseOffset = min(offset, UNIFIED_VALUE_MAX);}
	void setOnIndex(uint8_t const &led) {onIndex = min(led, numLeds - 1);}
	void setOnIndexUnified(uint16_t const &led)
			{onIndex = convertUnified(led, UNIFIED_VALUE_MIN, UNIFIED_VALUE_MAX, 0, (numLeds - 1));}

	void setLEDState(uint8_t const &index, bool const &state)
	{
		if(index < numLeds)
		{
			ledSettings[index].setState(state);
		}
	}

	void setLEDOffset(uint8_t const &index, uint16_t const &offset)
	{
		if(index < numLeds)
		{
			ledSettings[index].setOffset(offset);
		}
	}


private:
	uint8_t convertUnified(uint16_t const &x, uint16_t const &inMin, uint16_t const &inMax, uint8_t const &outMin, uint8_t const &outMax)
	{
		uint8_t retVal = (uint8_t)(( (((float)(x - inMin)) / (inMax - inMin)) * ((float)(outMax - outMin))) + outMin);
		retVal = min(retVal, inMax);
		retVal = max(retVal, inMin);
		return retVal;
	}

	void updateBrightness()
	{
		uint8_t activeBrightness = (brightnessInfluencedEnabled ? influencedBrightness : unInfluencedBrightness);
		leds.setBrightness(activeBrightness);
	}

	void updateColors()
	{
		uint16_t activeBaseOffset = (offsetInfluencedEnabled ? influencedBaseOffset : unInfluencedBaseOffset);

		uint8_t r,g,b = 0;
		if(patternInfluencedEnabled)
		{
			for(uint8_t i = 0; i < numLeds; i++)
			{
				leds.setPixelColor(i, 0, 0, 0);
			}

			if(onIndex < numLeds)
			{
				ledSettings[onIndex].getRGB(activeBaseOffset, r, g, b);
				leds.setPixelColor(onIndex, r, g, b);
			}
		}
		else
		{
			for(uint8_t i = 0; i < numLeds; i++)
			{
				ledSettings[i].getRGB(activeBaseOffset, r, g, b);
				leds.setPixelColor(i, r, g, b);
			}
		}
	}

private:
	Adafruit_NeoPixel leds;
	LEDSetting ledSettings[numLeds];

	bool brightnessInfluencedEnabled;
	bool offsetInfluencedEnabled;
	bool patternInfluencedEnabled;

	uint8_t influencedBrightness;
	uint16_t influencedBaseOffset;
	uint8_t unInfluencedBrightness;
	uint16_t unInfluencedBaseOffset;

	uint8_t onIndex;
};

#endif /* LEDSTRIP_H_ */
