//
//
// CLASS: Xray.cpp
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is a X-ray Lab.
//
//-----------------------------------------

#include <iomanip>
#include "Xray.h"


Xray::Xray()
        : patientsServed(0), stationActive(0), patientWaitTime(0),
          aveServiceTime(0), aveWaitingTime(0), xrayp(new priorityQueue()) {}

int Xray::Available() {
    if(xRayTech[0] == true){
        return 1;
    }else {
        return 0;
    }
}

int Xray::getPatientsServed()  {
    return patientsServed;
}


void Xray::setPatientsServed(int patientsServed) {
    Xray::patientsServed = patientsServed;
}

int Xray::getStationActive()  {
    return stationActive;
}

void Xray::setStationActive(int stationActive) {
    Xray::stationActive = stationActive;
}

int Xray::getPatientWaitTime()  {
    return patientWaitTime;
}

void Xray::setPatientWaitTime(int patientWaitTime) {
    Xray::patientWaitTime = patientWaitTime;
}

int Xray::getAveServiceTime()  {
    return aveServiceTime;
}

void Xray::setAveServiceTime(int aveServiceTime) {
    Xray::aveServiceTime = aveServiceTime;
}

int Xray::getAveWaitingTime()  {
    return aveWaitingTime;
}

void Xray::setAveWaitingTime(int aveWaitingTime) {
    Xray::aveWaitingTime = aveWaitingTime;
}

 priorityQueue * Xray::getP()  {
    return xrayp;
}

void Xray::setTechTreating() {
    if(xRayTech[0]==true){
        xRayTech[0]=false;
    }else{
        xRayTech[0]=true;
    }
}

void Xray::printSummary() {
    cout << setw(10) <<"X-ray";
    cout << setw(10) <<patientsServed;
    cout << setw(10) <<stationActive;
    cout << setw(10) <<aveServiceTime;
    cout << setw(10) <<patientWaitTime;
    cout << setw(10) <<aveWaitingTime << endl;
}