#ifndef __CARREFOUR_CASSA_H_
#define __CARREFOUR_CASSA_H_

#include <omnetpp.h>
#include <vector>
#include "Decisore.h"
#include "Customer.h"
using namespace omnetpp;

class Cassa : public cSimpleModule
{
private:
    //Used to put an identifier to all the Cassa
    static int numeroCasse;
    //The identifier of the Cassa
    int numeroCassa;
    //The reference of our decisore that we use to choose the right tie
    Decisore *decisore;
    //This attribute indicates if tills is working or in idle at the moment
    bool isWorking;
    //Used to put
    std::vector<cMessage*> customers;
    //Random Number Generator
    cMersenneTwister *rng;
    int ServiceType;    //This variable is used to indicate the distribution of the service demand
                        //0 : exponential
                        //1 : lognormal
 protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    //Method used to know if this till are actually working, and used by the module "Cassa".
};

int Cassa::numeroCasse = 0;

#endif
