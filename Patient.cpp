//
//
// CLASS: Patient.cpp
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is a Patient class
//
//-----------------------------------------

#include "Patient.h"
#include "Const.h"

Patient::Patient(int arrival,int assessment,int initpriority,string initrequirements,int treatment,int initId)
:  arrivalTime(arrival),xrayArrival(0),treatmentArrival(0),bloodLabArrival(0),assessmentTime(assessment),priority(initpriority),requirements(initrequirements),treatmentTime(treatment),id(initId)
{} // constuctor.


//GETTER AND SETTER METHODS .

int Patient::getId() {
    return id;
}

int Patient::getXrayArrival() const {
    return xrayArrival;
}

void Patient::setXrayArrival(int xrayArrival) {
    Patient::xrayArrival = xrayArrival;
}

int Patient::getBloodLabArrival() const {
    return bloodLabArrival;
}

void Patient::setBloodLabArrival(int bloodLabArrival) {
    Patient::bloodLabArrival = bloodLabArrival;
}

int Patient::getTreatmentArrival() const {
    return treatmentArrival;
}

void Patient::setTreatmentArrival(int treatmentArrival) {
    Patient::treatmentArrival = treatmentArrival;
}

int Patient::getArrivalTime() {
    return arrivalTime;
}

int Patient::getAssessmentTime()  {
    return assessmentTime;
}

int Patient::getPriority()  {
    return priority;
}

string Patient::getRequirements() {
    return requirements;
}

int Patient::getTreatmentTime() {
    return treatmentTime;
}

void Patient::print() {
    cout << "Patient Number :" << id << arrivalTime << assessmentTime << priority << requirements << treatmentTime << endl;
}

