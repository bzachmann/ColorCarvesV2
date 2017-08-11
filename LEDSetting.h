/*
 * LEDSetting.h
 *
 *  Created on: Aug 10, 2017
 *      Author: Boston
 */

#ifndef LEDSETTING_H_
#define LEDSETTING_H_

#include <stdint.h>

#define DEFAULT_CT_OFFSET	(0)
#define DEFAULT_CT_STATE	(true)

class LEDSetting
{
private:
	enum color_t
	{
		COLOR_RED,
		COLOR_GREEN,
		COLOR_BLUE,
	};

public:
	LEDSetting() : offset(DEFAULT_CT_OFFSET), state(DEFAULT_CT_STATE) {}

	void setState(bool const &value);
	void setOffset(uint16_t const &value);
	void getRGB(uint16_t const & baseOffset, uint8_t &r, uint8_t &g, uint8_t &b);

private:
	uint8_t baseFunc(uint16_t value);
	uint8_t colorFunc(uint16_t value, color_t color);

private:
	uint16_t offset;
	bool state;
};

#endif /* LEDSETTING_H_ */
