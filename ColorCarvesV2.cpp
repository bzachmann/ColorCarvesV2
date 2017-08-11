#include <Arduino.h>

//TODO create scheduler and move these there
#include "apservice.h"
#include "apcmp.h"
#include "apmain.h"

void setup()
{
	Serial.begin(9600);
	ApService::inst.init();
	ApCMP::inst.init();
	ApMain::inst.init();
	//Serial.println("init finished");
}

void loop()
{
	//Serial.println("run");
	ApService::inst.run();
	ApCMP::inst.run();
	ApMain::inst.run();
	//delay(1000);
}
