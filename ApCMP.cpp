/*
 * ApCMP.cpp
 *
 *  Created on: Aug 5, 2017
 *      Author: bzachmann
 */

#include "apcmp.h"
#include "cmpport.h"
#include "apversion.h"

ApCMP ApCMP::inst;

ApCMP::ApCMP() :
		ledsetMsgRx(),
		angsetMsgRx(),
		speedsetMsgRx(),
		specsetMsgRx(),
		basesetMsgRx(),
		influsetMsgRx(),
		versionMsgTx(),
		infoMsgTx()
{

}

void ApCMP::init()
{
	ledsetMsgRx.init();
	angsetMsgRx.init();
	speedsetMsgRx.init();
	specsetMsgRx.init();
	basesetMsgRx.init();
	influsetMsgRx.init();
	versionMsgTx.init(versionType, versionMajor, versionMinor);
	infoMsgTx.init();
}

void ApCMP::run()
{
	infoMsgTx.run();
}

