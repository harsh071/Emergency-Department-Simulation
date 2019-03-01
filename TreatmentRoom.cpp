//
//
// CLASS: TreatmentRoom.cpp
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is an Treatment Room of a patient .
//
//-----------------------------------------
#include "iostream"
using namespace std;
#include "TreatmentRoom.h"
#include <iomanip>


TreatmentRoom::TreatmentRoom() : patientsServed(0), stationActive(0),
                                                   patientWaitTime(0), aveServiceTime(0),
                                                   aveWaitingTime(0),treatmentQueue(new priorityQueue) {}
void TreatmentRoom::printSummary() {
    cout << setw(10) <<"Treatment";
    cout << setw(10) << patientsServed;
    cout << setw(10) <<stationActive;
    cout << setw(10) <<aveServiceTime;
    cout << setw(10) <<patientWaitTime;
    cout << setw(10) <<aveWaitingTime << endl;


}


int TreatmentRoom::doctorAvailable() { // checks if Doctor is available or not.
    if(doctors[0] == true){
        return 1;
    }else if(doctors[1] == true){
        return 2;
    }else if (doctors[2] == true){
        return 3;
    }else{
        return 0;
    }
}


/*GETTER AND SETTER METHODS.*/

void TreatmentRoom::setDocTreating(int tech){
    if(doctors[tech - 1] == true) {
        doctors[tech - 1] = false;
    }else if(doctors[tech - 1] == false){
        doctors[tech - 1] = true;
    }
}



int TreatmentRoom::getPatientsServed()  {
    return patientsServed;
}

void TreatmentRoom::setPatientsServed(int patientsServed) {
    TreatmentRoom::patientsServed = patientsServed;
}

int TreatmentRoom::getStationActive()  {
    return stationActive;
}

void TreatmentRoom::setStationActive(int stationActive) {
    TreatmentRoom::stationActive = stationActive;
}

int TreatmentRoom::getPatientWaitTime()  {
    return patientWaitTime;
}

void TreatmentRoom::setPatientWaitTime(int patientWaitTime) {
    TreatmentRoom::patientWaitTime = patientWaitTime;
}

double TreatmentRoom::getAveServiceTime()  {
    return aveServiceTime;
}

void TreatmentRoom::setAveServiceTime(double aveServiceTime) {
    TreatmentRoom::aveServiceTime = aveServiceTime;
}

double TreatmentRoom::getAveWaitingTime()  {
    return aveWaitingTime;
}

void TreatmentRoom::setAveWaitingTime(double aveWaitingTime) {
    TreatmentRoom::aveWaitingTime = aveWaitingTime;
}

priorityQueue *TreatmentRoom::getTreatmentQueue()  {
    return treatmentQueue;
}

void TreatmentRoom::setTreatmentQueue(priorityQueue *treatmentQueue) {
    TreatmentRoom::treatmentQueue = treatmentQueue;
}
