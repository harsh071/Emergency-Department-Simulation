//
// CLASS: StartTreatment.cpp
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is an Treatment event of a patient .
//
//-----------------------------------------

#include "StartTreatment.h"

StartTreatment::StartTreatment(Patient* p, int time,int initech) :time(time),p(p),tech(initech) {
}
//Printing the event
void StartTreatment::print() {
    cout << "Start Treatment.. "<<endl;
}
//Getter and setter methods.


int StartTreatment::getTime(){
    return time;
}


int  StartTreatment::getTech(){
    return tech;
}



Patient* StartTreatment::getPatient(){
    return p;
}