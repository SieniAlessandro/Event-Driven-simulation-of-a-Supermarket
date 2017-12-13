
/*
 * This class represents a customer and it is use instead of a cMessage beacause  it allows to manage some important
 * Statistic information (like the moment when the message start, the arrive in queue ...
 * */
#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <omnetpp.h>
#include <string>
using namespace omnetpp;
using namespace std;
class Customer: public cMessage{
    static int global_id;
    int id;
    //This Attribute stands for the object of the messagge
    string Message;
    //this attribute is used to store the moment when the message start
    simtime_t sending_time;

public:
    simtime_t getArrivalTime(){ return this->sending_time;}
    int operator==(Customer a);
    int operator==(string a);
    int operator==(char * a);
    Customer();
    Customer(char *);
    Customer(string );
    virtual ~Customer();
};

#endif /* CUSTOMER_H_ */
