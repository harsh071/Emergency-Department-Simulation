//
// CLASS: CompeleteXray.cpp
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is an Xray event of a patient .
//
//-----------------------------------------

#include "CompleteXray.h"
  
CompleteXray::CompleteXray(Patient* p, int time,int inittech) :time(time),p(p),tech(inittech){
}

void CompleteXray::print() {
    cout<< "CompleteXray..."<<endl ;
}//Printing the event
//Getter and setter methods.

int CompleteXray::getTime() {
    return time;
}

Patient * CompleteXray::getPatient() {
    return p;
}

int CompleteXray::getTech(){
    return tech;
}