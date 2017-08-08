/*
 * ApCMP.cpp
 *
 *  Created on: Aug 5, 2017
 *      Author: bzachmann
 */

#include "apcmp.h"
#include "cmpport.h"

ApCMP ApCMP::inst;

ApCMP::ApCMP() :
		ledsetMsgRx()
{

}

void ApCMP::init()
{
	ledsetMsgRx.init();

}

void ApCMP::run()
{

}

