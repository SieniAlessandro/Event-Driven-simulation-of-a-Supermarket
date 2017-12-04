#include "Coda.h"
#include <omnetpp.h>
Define_Module(Coda);

void Coda::initialize()
{
    gates = new cGate*[atoi(par("numeroCasse"))];
    for(int i = 0; i<gateSize("out"); i++) {
        gates[i] = gate("out", i);
    }


    //Obtaining the reference to the module Decisore,to use its own methods
    this->decisore = check_and_cast<Decisore *> (getModuleByPath("Decisore"));
}

void Coda::handleMessage(cMessage *msg) {
    if(msg->isSelfMessage()) {
        //Inserting the new client ah the endof the queue
        customers.push_back(new cMessage("Cliente"));
    }
    if(customers.size() > 0) {
        //get the index of the till
        int indice = decisore->newCustomer();
        if(indice >= 0) {
            send(customers(0), gates[indice].getFullName());
            customers.erase(customers.begin());
        }

    }

}

