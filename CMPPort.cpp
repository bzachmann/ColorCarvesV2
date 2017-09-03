/*
 * CMPPort.cpp
 *
 *  Created on: Aug 4, 2017
 *      Author: bzachmann
 */

//#include <Arduino.h>
#include "CMPPort.h"


void CMPPort::init(Stream const * stream)
{
	tx.init(stream);
	rx.init(stream);
}

void CMPPort::run()
{
	tx.run();
	rx.run();
}


