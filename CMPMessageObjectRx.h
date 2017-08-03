#ifndef CMPMESSAGEOBJECTRX_H_
#define CMPMESSAGEOBJECTRX_H_

#include "cmpid.h"

class CMPPayload;

class CMPMessageObjectRx {
public:
	CMPMessageObjectRx();
	virtual void rxCallback(CMPPayload const &data) {(void)data;}


private:
	CMPID id;
};

#endif /* CMPMESSAGEOBJECTRX_H_ */
