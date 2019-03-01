//
//
// CLASS: TreatmentRoom.cpp
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is an Treatment Room of a patient .
//
//-----------------------------------------

#ifndef TREATMENTROOM_H
#define TREATMENTROOM_H


#include "Station.h"
#include "priorityQueue.h"

class TreatmentRoom: public Station {
private:
    bool doctors[3] = {true,true,true};
    int patientsServed; // number of patients served
    int stationActive; //Time station was active
    int patientWaitTime; // Time Patient was waiting
    double aveServiceTime; // average service time .
    double aveWaitingTime; // average waiting time.
    priorityQueue * treatmentQueue;

public:
    TreatmentRoom();

    int doctorAvailable();

    void setDocTreating(int tech);

    void printSummary();

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

    priorityQueue *getTreatmentQueue() ;

    void setTreatmentQueue(priorityQueue *treatmentQueue);
};


#endif //ASSIGNMENT2_TREATMENTROOM_H
