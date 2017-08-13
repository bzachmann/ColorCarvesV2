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
	bsp_timercapt_init(CLOCK_MHZ, TIMER_CAPT_PRESCALER);
	ApService::inst.init();
	ApCMP::inst.init();
	ApMain::inst.init();
	//Serial.println("init finished");
}

void loop()
{
	ApService::inst.run();
	ApCMP::inst.run();
	ApMain::inst.run();
	//delay(1000);
}
