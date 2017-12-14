#include "Coda.h"
#include <omnetpp.h>
#include <string>
Define_Module(Coda);

void Coda::initialize()
{
    //Initializing all the port gates of Coda, because it need as many outputs ports
    //as the number of Casse in the simulation
    this->gates = new cGate*[getParentModule()->par("numeroCasse").longValue()];
    for(int i = 0; i<gateSize("out"); i++) {
        this->gates[i] = gate("out", i);
    }
    //Declaring the rng
    this->rng = new cMersenneTwister();
    //Obtaining the reference to the module Decisore,to use its own methods
    decisore = check_and_cast<Decisore *> (getParentModule()->getModuleByPath("decisore"));
    //Starting the simulation
    scheduleAt(simTime()+7,new cMessage());
    //Initilazing the signal
    time_prec = 0;
    this->interarrivalSignal = registerSignal("Interarrivals");
    this->queueingtimeSignal = registerSignal("Queuing");
}

//If self message then is arrived a new customer
//else if there is at least one customer in the queue and there is at least one available till
//send the customer
void Coda::handleMessage(cMessage *msg) {
    if(msg->isSelfMessage()) {
        //Registering the Interarrival time of the customer
        emit(interarrivalSignal,simTime() - time_prec);
        //Updating the precedent time
        time_prec = simTime();
        //Inserting the new client at the end of the queue
        this->customers.push_back(new Customer("Cliente"));
        //This function simulates the arrival rate, 1/lambda, of the customers
        scheduleAt(simTime()+omnetpp::exponential(rng, getParentModule()->par("lambda").longValue()), new cMessage());
    }
    if(this->customers.size() > 0) {
        //get the index of the till
        int indice = decisore->newCustomer();
        if(indice >= 0) {
            //Registering the queuing time

            //Send the customers, with a FIFO policy, to the Cassa
            //specified by the Decisore
            send(this->customers[0], this->gates[indice]);
            //Remove that costumers from the queue
            this->customers.erase(this->customers.begin());
        }
    }

}

