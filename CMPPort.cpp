/*
 * CMPPort.cpp
 *
 *  Created on: Aug 2, 2017
 *      Author: Boston
 */
#include <Arduino.h>
#include "CMPPort.h"

CMPPort CMPPort::inst(&Serial);

CMPPort::CMPPort(Stream const * stream) :
		stream(stream),
		rxHandler(stream)
{
	// TODO Auto-generated constructor stub

}

void CMPPort::init()
{
}

void CMPPort::run()
{

}

