//

// Interface.: Arrival.h
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is an arrival event of a patient.
//
//-----------------------------------------



#ifndef ARRIVAL_H
#define ARRIVAL_H


#include "Patient.h"
#include "Event.h"

class Arrival: public Event{
private:
    Patient * patient; // An arrival a patient.

public:


    Arrival(Patient * p); // Constructor .
    void print(); // Print stats.
    Patient  * getPatient();
};


#endif //ASSIGNMENT2_ARRIVAL_H
