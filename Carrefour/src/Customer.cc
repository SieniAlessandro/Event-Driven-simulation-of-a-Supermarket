#include "Customer.h"
int Customer::global_id = 0;
Customer::Customer() {
    this->Message = "Messaggio";
    this->id = global_id++;
    this->sending_time = simTime();
}
Customer::Customer(string a) {
    this->Message = a;
    this->id = global_id++;
    this->sending_time = simTime();
}
Customer::Customer(char * a) {
    this->Message.copy(a, strlen(a));
    this->id = global_id++;
    this->sending_time = simTime();
}
Customer::~Customer() {
    // TODO Auto-generated destructor stub
}
int Customer::operator ==(string a){
    return this->Message == a;
}
int Customer::operator ==(Customer a){
    return this->Message == a.Message;
}
int Customer::operator ==(char *a){
    return strcmp(this->Message.c_str(),a);
}
