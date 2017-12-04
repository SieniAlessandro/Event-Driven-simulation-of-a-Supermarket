#ifndef __CARREFOUR_CASSA_H_
#define __CARREFOUR_CASSA_H_

#include <omnetpp.h>
#include <vector>
#include "Decisore.h"
using namespace omnetpp;

class Cassa : public cSimpleModule
{
private:
    //Used to put an identifier to all the Cassa
    static int numeroCasse;
    //Used to use always a different seed for every message, becouse they are IID
    static int seed;
    //The identifier of the Cassa
    int numeroCassa;
    //The reference of our decisore that we use to choose the right tie
    Decisore *decisore;
    //This attribute indicates if tills is working or in idle at the moment
    bool isWorking;
    //Used to put
    std::vector<cMessage*> customers;
 protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    //Method used to know if this till are actually working, and used by the module "Cassa".
};

int Cassa::numeroCasse;
int Cassa::seed;

#endif
