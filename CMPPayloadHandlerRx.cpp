#include "CMPPayloadHandlerRx.h"

CMPPayloadHandlerRx::CMPPayloadHandlerRx(CMPPortRx const * portRx) :
	portRx(portRx)
{
	// TODO Auto-generated constructor stub

}


void CMPPayloadHandlerRx::registerDataHandler(CMPDataHandler * newHandler)
{
	dataHandler->add(newHandler);
}
