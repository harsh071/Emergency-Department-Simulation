//
// CLASS: Discharge.h
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is an Discharge event of a patient .
//
//-----------------------------------------


#ifndef DISCHARGE_H
#define DISCHARGE_H


#include "Event.h"
#include "Patient.h"

class Discharge : public Event{

private:
    int time;  // The time it would take to complete the blood work.
    int tech; // The tech treating
    Patient * p; //The patient.

public:
    Discharge(Patient *p, int time,int tech);
    void print();//Printing the event
    //Getter and setter methods.
    int getTime();
    int getDoc();
    Patient* getPatient();
};


#endif //ASSIGNMENT2_DISCHARGE_H
