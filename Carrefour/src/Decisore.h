/*
 * Decisore.h
 */

#ifndef DECISORE_H_
#define DECISORE_H_
using namespace omnetpp;

//int numerocasse = 5; useremo un parametro di configurazione

class Decisore {
private:
   int* clientiAllaCassa;
   int numerocasse;
   int findlowest(int);
public:
    Decisore();
    virtual int invia();
    virtual int ricevi();
    virtual ~Decisore();
};

#endif /* DECISORE_H_ */
//decisore di elena
