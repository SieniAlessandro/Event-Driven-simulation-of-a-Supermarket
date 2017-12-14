//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "Cassa.h"

Define_Module(Cassa);

void Cassa::initialize()
{
    //Initializing the static parameters

    //Setting the identifier of the single Cassa
    this->numeroCassa = numeroCasse++;
    EV << "io sono la cassa numero "<<this->numeroCassa<<endl;
    //Obtaining the reference to the module Decisore,to use its own methods
    decisore = check_and_cast<Decisore *> (getParentModule()->getModuleByPath("decisore"));
    //Setting the Cassa in idle state
    this->isWorking = false;
    //Initialize the own rng for the each till
    this->rng = new cMersenneTwister();
}

void Cassa::handleMessage(cMessage *msg)
{
    //If it's a selfMessage means that a service is completed
    if(msg->isSelfMessage()){
        //remove the customer from the Cassa
        //Getting the Element in the first position to store the arrival time in a till
        simtime_t queueEnteringTime = ((Customer*) this->customers[0])->getArrivalTime();
        this->customers.erase(this->customers.begin());
        EV << "Tempo di attesa in coda: "<< simTime().dbl() - queueEnteringTime.dbl() << endl;
        //Inform the Decisore that one of its customer leaves
        if(decisore->ServiceComplete(this->numeroCassa)){
            send(new cMessage(), "out");
        }
        //Setting the cassa in idle state
        this->isWorking = false;
        //Debugging
        EV << "Ho servito un cliente" << endl;
    }else{//otherwise a new client arrives in the Cassa
        //Debugging
        EV << "Mi e' arrivato un customer"<< endl;
        //Buffering the new client
        this->customers.push_back(msg);

    }
    //If there's at least one customer and the Cassa isn't in the idle state
    if(this->customers.size() > 0 && !this->isWorking){
        //schedule a self message that will occur @ random time generated by a seed
        //that is different for each message that arrives in all the Casse
        //in this case is used an exponential variable ----> in the future we'll need the lognormal case
        scheduleAt(simTime()+omnetpp::exponential(this->rng, getParentModule()->par("mu").longValue()), new cMessage());
        //at this point the Cassa isn't idle anymore
        this->isWorking = true;
    }
}
