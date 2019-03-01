//
// CLASS: Patinet.cpp
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This Contains the details of the patients.
//
//-----------------------------------------

#ifndef ASSIGNMENT2_PATIENT_H
#define ASSIGNMENT2_PATIENT_H

#include <iostream>
#include "Item.h"
using namespace std;

class Patient : public Item{
private:
    //Patient Data
    int id; //Patient Id
    int arrivalTime; //Patient arrival Time
    int xrayArrival; //Patient arrival Time at the xray lab
    int bloodLabArrival;//Patient arrival Time at the blood lab
    int treatmentArrival;//Patient arrival Time at the treatment room
    int assessmentTime;//Patient assessment time
    int priority; // Patient priority
    string requirements; // Patient requirement.
    int treatmentTime; // Treatment time



public:
    //constructor.
    Patient(int arrival,int assessment,int priority,string requirements,int treatment, int id);

    //getter and setter methods.

    int getArrivalTime() ;

    int getAssessmentTime() ;

    int getPriority() ;

    string getRequirements() ;

    int getTreatmentTime() ;

    int getId();


    //Print method.
    void print();

    int getXrayArrival() const;

    void setXrayArrival(int xrayArrival);

    int getBloodLabArrival() const;

    void setBloodLabArrival(int bloodLabArrival);

    int getTreatmentArrival() const;

    void setTreatmentArrival(int treatmentArrival);

};


#endif //ASSIGNMENT2_PATIENT_H
