//
// CLASS: StartBloodWork.cpp
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is an BloodWork event of a patient .
//
//-----------------------------------------


#ifndef ASSIGNMENT2_STARTBLOODWORK_H
#define ASSIGNMENT2_STARTBLOODWORK_H


#include "Event.h"
#include "Patient.h"

class StartBloodWork : public Event{

private:
    int time;
    int tech;
    Patient * p;
public:
    StartBloodWork(Patient *p, int time,int tech);
    void print();//Printing the event
    //Getter and setter methods.

    int getTime();
    int getTech();
    Patient* getPatient();

};



#endif //ASSIGNMENT2_STARTBLOODWORK_H
