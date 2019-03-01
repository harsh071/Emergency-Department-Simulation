
// CLASS: Admission.cpp
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is a Station in the emergency department. Which handles assessments.
//
//-----------------------------------------

#include "iostream"
using namespace std;
#include "Admission.h"
#include "Node.h"
#include "Patient.h"
#include <iomanip>

Admission::Admission()
        : patientsServed(0), stationActive(0), patientWaitTime(0),
          aveServiceTime(0), aveWaitingTime(0),Q(new Queue()) {}


//Prints the summary
void Admission::printSummary() {
    cout<< setw(10) << "Assessment";
    cout << setw(10) << patientsServed;
    cout << setw(10) <<stationActive;
    cout << setw(10) <<aveServiceTime;
    cout << setw(10) <<patientWaitTime;
    cout << setw(10) <<aveWaitingTime<< endl;

}

// Gives you the nurse which is available.
int Admission::Available() {

    if(nurseAvailable[0] == true){
        return 1;
    }else if(nurseAvailable[1] == true){
        return 2;
    }else{
        return 0;
    }

}


// GETTER AND SETTER METHODS

Queue *Admission::getQ()  {
    return Q;
}

void Admission::setPatientsServed(int patientsServed) {
    Admission::patientsServed = patientsServed;
}

void Admission::setStationActive(int stationActive) {
    Admission::stationActive = stationActive;
}

void Admission::setPatientWaitTime(int patientWaitTime) {
    Admission::patientWaitTime = patientWaitTime;
}

void Admission::setAveServiceTime(double aveServiceTime) {
        Admission::aveServiceTime = aveServiceTime;
}

void Admission::setAveWaitingTime(double aveWaitingTime) {
    Admission::aveWaitingTime = aveWaitingTime;
}

int Admission::getPatientsServed()  {
    return patientsServed;
}

int Admission::getPatientWaitTime() {
    return patientWaitTime;
}

int Admission::getStationActive()  {
    return stationActive;
}

double Admission::getAveWaitingTime() {
    return aveWaitingTime;
}

double Admission::getAveServiceTime() {
    return aveServiceTime;
}


// Makes a nurse available if not available, and vice versa

void Admission::setNurseTreating(int nurse) {
    if(nurseAvailable[nurse - 1] == true) {
        nurseAvailable[nurse - 1] = false;
    }else if(nurseAvailable[nurse - 1] == false){
        nurseAvailable[nurse - 1] = true;
    }
}

