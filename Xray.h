//
//
// CLASS: Xray.h
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is a X-ray Lab.
//
//-----------------------------------------

#ifndef XRAY_H
#define XRAY_H


#include "Station.h"
#include "priorityQueue.h"
#include "Patient.h"

class Xray : public Station {
private:
    bool xRayTech[1] = {true};
    int patientsServed; // number of patients served
    int stationActive; //Time station was active
    int patientWaitTime; // Time Patient was waiting
    double aveServiceTime; // average service time .
    double aveWaitingTime; // average waiting time.
    priorityQueue * xrayp;

public:
    Xray();

    void printSummary();

    int Available();

    int getPatientsServed() ;

    void setPatientsServed(int patientsServed);

    int getStationActive() ;

    void setStationActive(int stationActive);

    int getPatientWaitTime() ;

    void setPatientWaitTime(int patientWaitTime);

    int getAveServiceTime() ;

    void setAveServiceTime(int aveServiceTime);

    int getAveWaitingTime() ;

    void setAveWaitingTime(int aveWaitingTime);

     priorityQueue * getP() ;

     void setTechTreating();

};


#endif //ASSIGNMENT2_XRAY_H
