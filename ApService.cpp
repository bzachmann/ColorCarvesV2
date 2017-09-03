/*
 * ApService.cpp
 *
 *  Created on: Aug 5, 2017
 *      Author: bzachmann
 */

#include <Arduino.h>
#include "ApService.h"

ApService ApService::inst;

ApService::ApService()
{

}

void ApService::init()
{
	cmpPort.init(&Serial);
	payloadHandlerTx.init(&(cmpPort.tx));
	payloadHandlerRx.init(&(cmpPort.rx));
}

void ApService::run()
{
	cmpPort.run();
	payloadHandlerTx.run();
	payloadHandlerRx.run();
}
