#ifndef __CARREFOUR_CASSA_H_
#define __CARREFOUR_CASSA_H_

#include <omnetpp.h>

using namespace omnetpp;

/**
 * TODO - Generated class
 */
class Cassa : public cSimpleModule
{
private:
    //The reference of our decisore that we use to choose the right tie
    Decisore *decisore;
    //This attribute indicates if tills is working or in idle at the moment
    bool isWorking;
 protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    //Method used to know if this till are actually working, and used by the module "Cassa".
    bool isWorking() { return this->isWorking;}
};

#endif
