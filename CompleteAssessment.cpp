//
// CLASS: CompeleteAssessment.cpp
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is an Assessment event of a patient .
//
//-----------------------------------------

#include <iostream>
using namespace std;
#include "CompleteAssessment.h"

//Constructor.
CompleteAssessment::CompleteAssessment(Patient* p, int time,int initnurse) :time(time),p(p),nurse(initnurse){}

//Printing the event
void CompleteAssessment::print() {
    cout<< "CompleteAssessment..."<<endl ;
}

//Getter and setter methods.

int CompleteAssessment::getTime() {
    return time;
}

Patient * CompleteAssessment::getPatient() {
    return p;
}

int CompleteAssessment::getNurse() {
    return nurse;
 }