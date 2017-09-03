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
	payloadHandlerRx.init(&(cmpPort.rx));
}

void ApService::run()
{
	cmpPort.run();
	payloadHandlerRx.run();
}
