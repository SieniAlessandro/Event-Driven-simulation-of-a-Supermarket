/*
 * Decisore.h
 */

#ifndef DECISORE_H_
#define DECISORE_H_
using namespace omnetpp;

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

#endif

/* DECISORE_H_ */
