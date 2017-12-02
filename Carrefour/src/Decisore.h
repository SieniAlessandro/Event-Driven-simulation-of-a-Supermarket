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
    int newCustomer(int i);
    void ServiceComplete(int i);
    virtual ~Decisore();
};

#endif

/* DECISORE_H_ */
