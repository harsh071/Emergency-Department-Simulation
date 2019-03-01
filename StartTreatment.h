//
// CLASS: StartTreatment.h
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is an Treatment event of a patient .
//
//-----------------------------------------

#ifndef ASSIGNMENT2_STARTTREATMENT_H
#define ASSIGNMENT2_STARTTREATMENT_H


#include "Event.h"
#include "Patient.h"

class StartTreatment : public Event{
private:
    int time;
    int tech;
    Patient * p;
public:
    StartTreatment(Patient *p, int time,int tech);

    //Printing the event
    void print();

    //Getter and setter methods.
    int getTime();
    int getTech();
    Patient* getPatient();

};


#endif //ASSIGNMENT2_STARTTREATMENT_H
