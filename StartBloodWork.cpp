//
// CLASS: StartBloodWork.cpp
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is an BloodWork event of a patient .
//
//-----------------------------------------

#include "StartBloodWork.h"
StartBloodWork::StartBloodWork(Patient* p, int time,int initech) :time(time),p(p),tech(initech) {
}

//Getter and setter methods.
//Printing the event


void StartBloodWork::print() {
    cout << "Start BloodWork.. "<<endl;
}

int StartBloodWork::getTime(){
    return time;
}


int  StartBloodWork::getTech(){
    return tech;
}

Patient* StartBloodWork::getPatient(){
    return p;
}