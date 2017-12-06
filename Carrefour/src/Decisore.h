/*
 * Decisore.h
 */

#ifndef DECISORE_H_
#define DECISORE_H_
#include <omnetpp.h>

using namespace omnetpp;

class Decisore: public cObject {
private:
   //This array is used to indicate the number of customer for each single queue :
   //-In case of common queue the only possible variable are 0 (idle) or 1(serving one customer, working)
   //-In case of a queue for each till, each position indicates the number of customers that are waiting to be served
   // by that particulare queue
   int* clientiAllaCassa;
   //This attribute indicates the number of tills present in our system
   int numerocasse;
   //This Attribute is used when there is a common queue and indicates the number of customers that are waiting to be
   //served
   //served, and it is set to 5000 (it's important to mantein the status of infinite memory that the maximum number of
   //customer "generated" is lower than the dimension of the array plus then numeber of tills.
   int inAttesa;
   //Private Method used to find the till with the less number of customer in queue
   int findlowest(int);
   cModule *get;
public:
    Decisore();
    int newCustomer(int parameter = 0);
    void ServiceComplete(int i);
    ~Decisore();
protected:

};

#endif

/* DECISORE_H_ */
