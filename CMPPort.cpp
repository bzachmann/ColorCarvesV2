/*
 * CMPPort.cpp
 *
 *  Created on: Aug 4, 2017
 *      Author: bzachmann
 */

//#include <Arduino.h>
#include "CMPPort.h"

CMPPort::CMPPort()
{

}

void CMPPort::init(Stream const * stream)
{
	rx.init(stream);
}

void CMPPort::run()
{
	rx.run();
}


