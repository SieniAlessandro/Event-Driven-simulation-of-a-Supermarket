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
 protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

#endif
