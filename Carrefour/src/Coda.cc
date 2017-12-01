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
//PROVA
#include "Coda.h"
#include <omnetpp.h>
Define_Module(Coda);

void Coda::initialize()
{
}

void Coda::handleMessage(cMessage *msg) {
    QueueMessage* message = check_and_cast<QueueMessage*>(msg);
        if (message->getOperationType() == NEW_CUSTOMER) {
            queue.insert(message);
        } else if (message->getOperationType() == CASSA_LIBERA) {
            if (!queue.isEmpty()) {
                QueueMessage* reply = check_and_cast<QueueMessage*>(queue.pop());
                send(reply, msg->getSenderGate());
            } else {
                //Rimuovere dalla coda il primo entrato e mandarlo alla cassa
            }
        }
}

