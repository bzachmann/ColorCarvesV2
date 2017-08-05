/*
 * ApService.cpp
 *
 *  Created on: Aug 5, 2017
 *      Author: bzachmann
 */

#include <Arduino.h>
#include "ApService.h"

static ApService * ApService::inst;

ApService::ApService()
{

}

void ApService::init()
{
	cmpPort.init(&Serial);
	payloadHandler.init(&(cmpPort.rx));
}

void ApService::run()
{
	cmpPort.run();
	payloadHandler.run();
}
