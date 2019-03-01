//

// Interface: BloodLab.h
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is a station in the Emergency Department
//
//-----------------------------------------

#ifndef BLOODLAB_H
#define BLOODLAB_H


#include "Station.h"
#include "priorityQueue.h"

class BloodLab : public Station {
private:

    bool bloodTechs[3] = {true,true,true};
    priorityQueue * bloodLabPq;
    int patientsServed; // number of patients served
    int stationActive; //Time station was active
    int patientWaitTime; // Time Patient was waiting
    double aveServiceTime; // average service time .
    double aveWaitingTime; // average waiting time.

public:
    BloodLab();

    int BloodtechAvailable();// checks if Tech is available or not.

    void printSummary();

    /*GETTER AND SETTER METHODS.*/

    void setBloodTechTreating(int tech);

    priorityQueue *getBloodLabPq() ;

    void setBloodLabPq(priorityQueue *bloodLabPq);

    int getPatientsServed() ;

    void setPatientsServed(int patientsServed);

    int getStationActive() ;

    void setStationActive(int stationActive);

    int getPatientWaitTime() ;

    void setPatientWaitTime(int patientWaitTime);

    double getAveServiceTime() ;

    void setAveServiceTime(double aveServiceTime);

    double getAveWaitingTime() ;

    void setAveWaitingTime(double aveWaitingTime);
};


#endif //ASSIGNMENT2_BLOODLAB_H
