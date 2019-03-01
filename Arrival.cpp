
// CLASS: Arrival.cpp
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is an Arrival event of a patient .
//
//-----------------------------------------


#include "Arrival.h"

Arrival::Arrival(Patient * Initp) : patient(Initp){}  //constructor

//Prints the details.
void Arrival::print() {
    cout << "Arrival at:" <<  patient->getArrivalTime();
}

//GETER METHOD .
Patient * Arrival::getPatient() {
    return patient;
}