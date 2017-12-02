#include "Coda.h"
#include <omnetpp.h>
Define_Module(Coda);

void Coda::initialize()
{
    //Obtaining the reference to the module Decisore,to use its own methods
    this->decisore = check_and_cast<Decisore *> (getModuleByPath("Decisore"));
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

