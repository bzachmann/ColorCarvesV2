/*
 * debugserial.cpp
 *
 *  Created on: Sep 4, 2017
 *      Author: bzachmann
 */

#include "debugserial.h"

#ifdef DEBUGMODE
SoftwareSerial debugSerial(5, 6); //rx, tx
#endif

void debugserial_init()
{
#ifdef DEBUGMODE
	debugSerial.begin(9600);
#endif
}

