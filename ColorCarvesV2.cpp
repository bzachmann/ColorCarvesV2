#include <Arduino.h>

//TODO create scheduler and move these there
#include "apmain.h"
#include "CMPPortRx.h"

void setup()
{
	Serial.begin(9600);
	//CMPPort::inst.init();
	ApMain::inst.init();
}

void loop()
{
	//CMPPort::inst.run();
	ApMain::inst.run();

}
