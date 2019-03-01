//
// CLASS: EmergencyDepartment.h
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is the whole simulation of the Emergency Department.
// .
//
//-----------------------------------------

#ifndef EMERGENCYDEPARTMENT_H
#define EMERGENCYDEPARTMENT_H

#include "Queue.h"
#include "priorityQueue.h"
#include "Arrival.h"
#include "Admission.h"
#include "Xray.h"
#include "BloodLab.h"
#include "TreatmentRoom.h"
#include "StartAssessment.h"
#include "CompleteAssessment.h"
#include "StartBloodWork.h"
#include "CompleteBloodWork.h"
#include "StartXray.h"
#include "CompleteXray.h"
#include "StartTreatment.h"
#include "Discharge.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class EmergencyDepartment {

private:

    //Patient and arrival for reading the file .
    Patient *newPatient;
    Arrival *newArrival;

    //Stations.
    Admission * admission;
    Xray * xrayLab;
    BloodLab * bloodLab;
    TreatmentRoom * treatmentRoom;

    //Event List priority queue , which is prioritized by time.
    priorityQueue * EventList;

    //keeping a track of the times. .
    int currentTime;
    int arrivalTime;
    int assessmentTime;
    int priority;
    string requirements;
    int treatmentTime;

    //keeps a track of the next patient id.
    static int nextPatientId;

    //used to the read file.
    ifstream file;
    string line;



public:
    //this is the constructor.
    EmergencyDepartment();

    //increments and gets the timings.
    int getNextPatientId();

    //Methods which simulate the program.
    void simulate(string name);
    void processArrival(Arrival * arrival);
    void startAssessment(StartAssessment * start);
    void completeAssessment(CompleteAssessment * a);
    void startBloodWork(StartBloodWork * startBloodWork);
    void completeBloodWork(CompleteBloodWork* completeBloodWork);
    void startXray(StartXray * startXray);
    void completeXray(CompleteXray * completeXray);
    void startTreatment(StartTreatment * startTreatment);
    void processDischarge(Discharge * discharge);

    //calculates and prints the summary
    void summary();


};


#endif //ASSIGNMENT2_EMERGENCYDEPARTMENT_H
