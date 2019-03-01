//
// CLASS: Admission.h
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is a Station in the emergency department. Which handles assessments.
//
//-----------------------------------------


#ifndef ADMISSION_H
#define ADMISSION_H

#include <iostream>
using namespace std;

#include "Patient.h"
#include "Station.h"
#include "Queue.h"

// Interface: Admission.h
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is a Station in the emergency Department .
//
//-----------------------------------------

class Admission : public Station {
private:
    bool nurseAvailable[2] = {true,true}; //checks the number of nurses available.
    int patientsServed; // number of patients served
    int stationActive; //Time station was active
    int patientWaitTime; // Time Patient was waiting
    double aveServiceTime; // average service time .
    double aveWaitingTime; // average waiting time.
    Queue * Q; // The queue of Patients when they arrive.


public:
    Admission();

    void printSummary();

    int Available(); // checks if the nurses are available.

    //Getter and setter methods.

    Queue *getQ() ;

    void setNurseTreating(int nurse);

    void setPatientsServed(int patientsServed);

    void setStationActive(int stationActive);

    void setPatientWaitTime(int patientWaitTime);

    void setAveServiceTime(double aveServiceTime);

    void setAveWaitingTime(double aveWaitingTime);

    int getPatientsServed() ;

    int getStationActive() ;

    int getPatientWaitTime() ;

    double getAveServiceTime() ;

    double getAveWaitingTime() ;


};


#endif //ASSIGNMENT2_ADMISSION_H
