// Interface: CompeleteXray.h
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is an Xray event of a patient .
//
//-----------------------------------------

#ifndef ASSIGNMENT2_COMPLETEXRAY_H
#define ASSIGNMENT2_COMPLETEXRAY_H


#include "Event.h"
#include "Patient.h"

class CompleteXray: public Event {
private:
    int time; // The time it would take to complete the blood work.// The time it would take to complete the blood work.
    int tech;// The tech treating
    Patient * p;//The patient.


public:
    CompleteXray(Patient *p, int time,int tech);
    void print();//Printing the event
    //Getter and setter methods.
    int getTime();
    int getTech();
    Patient* getPatient();
};


#endif //ASSIGNMENT2_COMPLETEXRAY_H
