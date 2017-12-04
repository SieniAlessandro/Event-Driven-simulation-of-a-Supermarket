#ifndef __CARREFOUR_CASSA_H_
#define __CARREFOUR_CASSA_H_

#include <omnetpp.h>
#include <vector>
using namespace omnetpp;

/**
 * TODO - Generated class
 */
class Cassa : public cSimpleModule
{
private:
    static int numeroCasse = 0;
    int numeroCassa;
    //The reference of our decisore that we use to choose the right tie
    Decisore *decisore;
    //This attribute indicates if tills is working or in idle at the moment
    std::vector<cMessage*> customers;
 protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    //Method used to know if this till are actually working, and used by the module "Cassa".
    bool isWorking() { return this->isWorking;}
};

#endif
