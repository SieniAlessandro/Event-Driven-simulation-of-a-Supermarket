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
    numeroCassa = 0;
    seed = 1;
    //Obtaining the reference to the module Decisore,to use its own methods
    this->decisore = check_and_cast<Decisore *> (getModuleByPath("Decisore"));
    numeroCassa = numeroCasse++;
    isWorking = false;
}

void Cassa::handleMessage(cMessage *msg)
{
    //Service complete
    if(msg->isSelfMessage()){
        //Inform Decisore
        customers.erase(customers.begin());
        decisore->ServiceComplete(this->numeroCassa);
        isWorking = false;
    }else{
        //Buffering the client
        customers.push_back(msg);
    }
    if(customers.size() > 0 && !isWorking){
        scheduleAt(omnetpp::exponential(getRNG(seed++), 1/atoi(par("mu"))), customers[0]);
        isWorking = true;
    }
}
