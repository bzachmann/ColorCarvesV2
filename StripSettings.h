/*
 * StripSettings.h
 *
 *  Created on: Aug 9, 2017
 *      Author: Boston
 */

#ifndef STRIPSETTINGS_H_
#define STRIPSETTINGS_H_

#include <stdint.h>

template <uint8_t numLeds> class StripSettings
{
private:
	class ledSetting
	{
	public:
		ledSetting();

		void setState(bool const &state);
		void setOffset(uint16_t const &offset);
		void getRGB(uint16_t const & baseOffset, uint16_t &r, uint16_t &g, uint16_t &b);

	private:
		uint16_t offset;
		bool state;
	};

public:
	StripSettings<numLeds>();
	void run()
	{
		updateBrightness();
		updateColors();
		//strip.show()
	}
	void init();



private:
	void updateBrightness()
	{
		if(brightnessControlledEnabled)
		{
			//neostrip.setBrightness()
		}
		else
		{

		}
	}

	void updateColors();

private:
	bool brightnessControlledEnabled;
	bool offsetControlledEnabled;
	bool patternControlledEnabled;

	uint16_t influencedBrightness;
	uint16_t influencedBaseOffset;
	uint16_t defaultBrightness;
	uint16_t defaultBaseOffset;

	uint8_t onIndex;

	uint16_t ledSetting[numLeds];
};

#endif /* STRIPSETTINGS_H_ */
