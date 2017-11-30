/*
 * Decisore.h
 *
 *  Created on: 30 nov 2017
 *      Author: elena
 */

#ifndef DECISORE_H_
#define DECISORE_H_
using namespace omnetpp;

//int numerocasse = 5; useremo un parametro di configurazione

class Decisore {
private:
   int* clientiAllaCassa;
public:
    Decisore();
    virtual void invia(cMessage persona);
    virtual void ricevi(cMessage persona);
    virtual ~Decisore();
};

#endif /* DECISORE_H_ */
//decisore di elena

