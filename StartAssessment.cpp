//
// CLASS: StartAssessment.cpp
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is an Assessment event of a patient .
//
//-----------------------------------------

#include "StartAssessment.h"

StartAssessment::StartAssessment(Patient* p, int time,int initnurse) :time(time),p(p),nurse(initnurse) {
}
//Getter and setter methods.
//Printing the event

void StartAssessment::print() {
    cout << "Start Assessment.. "<<endl;
}


int StartAssessment::getTime(){
    return time;
}


int  StartAssessment::getNurse(){
    return nurse;
}

Patient* StartAssessment::getPatient(){
    return p;
}
