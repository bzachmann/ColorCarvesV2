/*
 * debugserial.h
 *
 *  Created on: Sep 4, 2017
 *      Author: bzachmann
 */

#ifndef DEBUGSERIAL_H_
#define DEBUGSERIAL_H_

#include <SoftwareSerial.h>

//comment out the line below to disable DEBUG Messages
#define DEBUGMODE

#ifdef DEBUGMODE
extern SoftwareSerial debugSerial;
#define debugPrint(x)	debugSerial.print(x)
#else
#define debugPrint(x)
#endif


extern void debugserial_init();


#endif /* DEBUGSERIAL_H_ */
