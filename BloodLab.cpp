
// CLASS: BloodLab.cpp
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is a station in the Emergency Department
//
//-----------------------------------------


#include "BloodLab.h"
#include "iostream"
#include <iomanip>


using namespace std;


BloodLab::BloodLab() // constructor.
        : patientsServed(0), stationActive(0), patientWaitTime(0),
          aveServiceTime(0), aveWaitingTime(0) , bloodLabPq(new priorityQueue()){}


void BloodLab::printSummary() { // Printing the summary.
    cout << setw(10)<<"Blood Work";
    cout << setw(10) << patientsServed;
    cout << setw(10) <<stationActive;
    cout << setw(10) <<aveServiceTime;
    cout << setw(10) <<patientWaitTime;
    cout << setw(10) <<aveWaitingTime << endl;

}


priorityQueue *BloodLab::getBloodLabPq()  {
    return bloodLabPq;
}

int BloodLab::BloodtechAvailable() { // checks if the blood tech is available or not.
    if(bloodTechs[0] == true){
        return 1;
    }else if(bloodTechs[1] == true){
        return 2;
    }else if (bloodTechs[2] == true){
        return 3;
    }else{
        return 0;
    }
}

void BloodLab::setBloodTechTreating(int tech){  // sets the tech who was treating to true or false.
    if(bloodTechs[tech - 1] == true) {
        bloodTechs[tech - 1] = false;
    }else if(bloodTechs[tech - 1] == false){
        bloodTechs[tech - 1] = true;
    }
}

//getter and setter methods .

int BloodLab::getPatientsServed()  {
    return patientsServed;
}

void BloodLab::setPatientsServed(int patientsServed) {
    BloodLab::patientsServed = patientsServed;
}

int BloodLab::getStationActive()  {
    return stationActive;
}

void BloodLab::setStationActive(int stationActive) {
    BloodLab::stationActive = stationActive;
}

int BloodLab::getPatientWaitTime()  {
    return patientWaitTime;
}

void BloodLab::setPatientWaitTime(int patientWaitTime) {
    BloodLab::patientWaitTime = patientWaitTime;
}

double BloodLab::getAveServiceTime()  {
    return aveServiceTime;
}

void BloodLab::setAveServiceTime(double aveServiceTime) {
    BloodLab::aveServiceTime = aveServiceTime;
}

double BloodLab::getAveWaitingTime()  {
    return aveWaitingTime;
}

void BloodLab::setAveWaitingTime(double aveWaitingTime) {
    BloodLab::aveWaitingTime = aveWaitingTime;
}
