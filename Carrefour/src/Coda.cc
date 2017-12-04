#include "Coda.h"
#include <omnetpp.h>
#include <string>
Define_Module(Coda);

void Coda::initialize()
{
    //Initializing static fields
    seed = 1;
    //Initializing all the port gates of Coda, because it need as many outputs ports
    //as the number of Casse in the simulation
    gates = new cGate*[atoi(par("numeroCasse"))];
    for(int i = 0; i<gateSize("out"); i++) {
        gates[i] = gate("out", i);
    }

    //Obtaining the reference to the module Decisore,to use its own methods
    this->decisore = check_and_cast<Decisore *> (getModuleByPath("Decisore"));
}

void Coda::handleMessage(cMessage *msg) {
    if(msg->isSelfMessage()) {
        //Inserting the new client at the end of the queue
        std::string name = "Cliente " + std::to_string(seed);
        customers.push_back(new cMessage(name.c_str()));
    }
    if(customers.size() > 0) {
        //get the index of the till
        int indice = decisore->newCustomer();
        if(indice >= 0) {
            //Send the customers, with a FIFO policy, to the Cassa
            //specified by the Decisore
            send(customers[0], gates[indice]->getFullName());
            //Remove that costumers from the queue
            customers.erase(customers.begin());
        }

    }
    //This function simulates the arrival rate, 1/lambda, of the customers
    scheduleAt(omnetpp::exponential(getRNG(seed++), 1/atoi(par("lamda"))), customers[0]);
}

