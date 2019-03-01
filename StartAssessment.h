// CLASS: StartAssessment.cpp
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is an Assessment event of a patient .
//
//-----------------------------------------
#include "Patient.h"
#include "Event.h"

#ifndef STARTASSESSMENT_H
#define STARTASSESSMENT_H


class StartAssessment: public Event {
private:
    int time;
    int nurse;
    Patient * p;

public:
    StartAssessment(Patient *p, int time,int nurse);
    void print();//Printing the event
    //Getter and setter methods.
    int getTime();
    int getNurse();
    Patient* getPatient();

};


#endif //ASSIGNMENT2_STARTASSESSMENT_H
