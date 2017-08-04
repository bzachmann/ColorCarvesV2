#ifndef CMPDATAHANDLER_H_
#define CMPDATAHANDLER_H_

#include "cmpmessage.h"

class CMPDataHandler {
public:
	CMPDataHandler() : id() {}
    virtual void callback(CMPData * data) {(void)data;} //virtual

private:
	CMPID id;
};

#endif /* CMPDATAHANDLER_H_ */
