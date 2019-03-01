//
// CLASS: CompleteBloodWork.h
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is an BloodWork event of a patient .
//
//-----------------------------------------
#ifndef COMPLETEBLOODWORK_H
#define COMPLETEBLOODWORK_H


#include "Event.h"
#include "Patient.h"

class CompleteBloodWork: public Event{
private:
    int time;  // The time it would take to complete the blood work.
    int tech; // The tech treating
    Patient * p; //The patient.


public:
    CompleteBloodWork(Patient *p, int time,int tech);//Constructor.
    void print();//Printing the event
    //Getter and setter methods.
    int getTime();
    int getTech();
    Patient* getPatient();
};


#endif //ASSIGNMENT2_COMPLETEBLOODWORK_H
