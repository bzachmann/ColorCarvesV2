/*
 * debugserial.cpp
 *
 *  Created on: Sep 4, 2017
 *      Author: bzachmann
 */

#include "debugserial.h"

#ifdef DEBUGMODE
SoftwareSerial debugSerial(3, 4); //rx, tx //physical pin 5 and 6 respectively
#endif

void debugserial_init()
{
#ifdef DEBUGMODE
	debugSerial.begin(9600);
#endif
}

