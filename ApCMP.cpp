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
		ledsetMsgRx(),
		angsetMsgRx(),
		speedsetMsgRx(),
		specsetMsgRx(),
		basesetMsgRx()
{

}

void ApCMP::init()
{
	ledsetMsgRx.init();
	angsetMsgRx.init();
	speedsetMsgRx.init();
	specsetMsgRx.init();
	basesetMsgRx.init();
}

void ApCMP::run()
{

}

