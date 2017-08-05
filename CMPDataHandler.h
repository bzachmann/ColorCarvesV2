#ifndef CMPDATAHANDLER_H_
#define CMPDATAHANDLER_H_

#include "cmpmessage.h"
#include "linkedlist.h"

class CMPDataHandler : public LinkedList<CMPDataHandler>
{
public:
	CMPDataHandler() : LinkedList<CMPDataHandler>(), id() {}
    virtual void callback(CMPData * data) {(void)data;} //virtual

public:
	CMPID id;
};

#endif /* CMPDATAHANDLER_H_ */
