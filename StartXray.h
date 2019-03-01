//
// CLASS: StartXray.h
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is a Start Xray event
// .
//
//-----------------------------------------


#ifndef STARTXRAY_H
#define STARTXRAY_H


#include "Event.h"
#include "Patient.h"

class StartXray: public Event {

private:
    int time;
    int tech;
    Patient * p;
public:
    StartXray(Patient *p, int time,int nurse);
    //Printing the event
    void print();
    //Getter and setter methods.
    int getTime();
    int getTech();
    Patient* getPatient();

};


#endif //ASSIGNMENT2_STARTXRAY_H
