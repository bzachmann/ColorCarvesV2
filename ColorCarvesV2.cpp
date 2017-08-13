#include <Arduino.h>

//TODO create scheduler and move these there
#include "apservice.h"
#include "apcmp.h"
#include "apmain.h"
#include "bsp_timercapt.h"

#define CLOCK_MHZ				(16)
#define TIMER_CAPT_PRESCALER	(4)

void setup()
{
	Serial.begin(9600);
	bsp_timercapt_init(16, 4);
	ApService::inst.init();
	ApCMP::inst.init();
	ApMain::inst.init();
	Serial.println("init finished");
}

void loop()
{
	uint32_t test = 0xFFFFFFFF;
	Serial.print("run: ");
	Serial.print(test);
	Serial.print(",  ");

	uint16_t test2 = test >> 16;
	uint16_t test3 = test & 0xFFFF;
	Serial.print(test2);
	Serial.print(",  ");
	Serial.println(test3);

	Serial.print("time between captures: ");
	Serial.println(bsp_timercapt_usBetweenCaptures());
	Serial.print("time since last capture: ");
	Serial.println(bsp_timercapt_usSinceCapture());


	ApService::inst.run();
	ApCMP::inst.run();
	ApMain::inst.run();
	delay(1000);
}
