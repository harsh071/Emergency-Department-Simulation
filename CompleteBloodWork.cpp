//
// CLASS: CompleteBloodWork.cpp
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is an BloodWork event of a patient .
//
//-----------------------------------------

#include "CompleteBloodWork.h"

CompleteBloodWork::CompleteBloodWork(Patient* p, int time,int inittech) :time(time),p(p),tech(inittech){
}//Constructor.


void CompleteBloodWork::print() {
    cout<< "CompleteBloodWork..."<<endl ;
}//Printing the event

//Getter and setter methods.

int CompleteBloodWork::getTime() {
    return time;
}

Patient * CompleteBloodWork::getPatient() {
    return p;
}

int CompleteBloodWork::getTech(){
    return tech;
}