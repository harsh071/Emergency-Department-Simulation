//
// Interface: CompeleteAssessment.h
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is an Assessment event of a patient .
//
//-----------------------------------------

#ifndef COMPLETEASSESSMENT_H
#define COMPLETEASSESSMENT_H


#include "Event.h"
#include "Patient.h"

class CompleteAssessment: public Event {
private:
    int time;  // The time it would take to complete the assessment.
    int nurse; // The nurse treating
    Patient * p; // The patient
public:
    CompleteAssessment(Patient *p, int time,int nurse);//Constructor.
    void print();//Printing the event
    //Getter and setter methods.
    int getTime();
    int getNurse();
    Patient* getPatient();
};


#endif //ASSIGNMENT2_COMPLETEASSESSMENT_H
