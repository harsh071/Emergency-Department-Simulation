//
// CLASS: EmergencyDepartment.cpp
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is the whole simulation of the Emergency Department.
// .
//
//-----------------------------------------

#include "EmergencyDepartment.h"
#include "Patient.h"
#include "StartAssessment.h"
#include "CompleteAssessment.h"
#include "StartBloodWork.h"
#include "CompleteBloodWork.h"
#include "Const.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

EmergencyDepartment::EmergencyDepartment():
        currentTime(0),EventList(new priorityQueue()), admission(new Admission()),xrayLab(new Xray()),
        bloodLab(new BloodLab()),treatmentRoom(new TreatmentRoom()){} // constructor.

int EmergencyDepartment::nextPatientId=1;

int EmergencyDepartment::getNextPatientId() {
    return nextPatientId++;
}

//This method reads the file and simulates the program .
void EmergencyDepartment::simulate(string name) {
    file.open("C:\\Users\\Harsh071\\CLionProjects\\Assignment2\\harsh");

    if (!file.is_open()) {
        cout << "The file you have entered is wrong.";
    }else {
        getline(file, line);

        string hashtag;

        stringstream input(line);
        input >> hashtag;
        if (hashtag.compare("#")==0) {
            cout << line << endl;
        }else {
            arrivalTime = stoi(hashtag);
            input >> assessmentTime;
            input >> priority;
            input >> requirements;
            input >> treatmentTime;

            newPatient = new Patient(arrivalTime, assessmentTime, priority, requirements, treatmentTime,
                                     getNextPatientId());
            newArrival = new Arrival(newPatient);

            EventList->enqueue(newArrival, arrivalTime);
            while (!(EventList->isEmpty())) { //Process events while the event list is not empty.


                Node *event = EventList->dequeue();

                Item *item = dynamic_cast<Arrival *>(event->getItem());
                if (item != NULL) {

                    //Process an  arrival .
                    processArrival((Arrival *) event->getItem());

                    if (!file.eof()) {

                        getline(file, line);

                        stringstream input(line);
                        input >> hashtag;
                        if (hashtag.compare("#")==0) {
                            cout << line << endl;
                        }else {
                            arrivalTime = stoi(hashtag);
                            input >> assessmentTime;
                            input >> priority;
                            input >> requirements;
                            input >> treatmentTime;

                            newPatient = new Patient(arrivalTime, assessmentTime, priority, requirements,
                                                     treatmentTime, getNextPatientId());
                            newArrival = new Arrival(newPatient);

                            EventList->enqueue(newArrival, arrivalTime);
                        }

                    }
                } else {
                    item = dynamic_cast<CompleteAssessment *>(event->getItem());
                    if (item != NULL) {
                        completeAssessment((CompleteAssessment *) event->getItem());
                    } else {
                        item = dynamic_cast<StartAssessment *>(event->getItem());
                        if (item != NULL) {
                            startAssessment((StartAssessment *) event->getItem());
                        } else {
                            item = dynamic_cast<StartBloodWork *>(event->getItem());
                            if (item != NULL) {
                                startBloodWork((StartBloodWork *) event->getItem());
                            } else {
                                item = dynamic_cast<CompleteBloodWork *>(event->getItem());
                                if (item != NULL) {
                                    completeBloodWork((CompleteBloodWork *) event->getItem());
                                } else {
                                    item = dynamic_cast<StartXray *>(event->getItem());
                                    if (item != NULL) {
                                        startXray((StartXray *) event->getItem());
                                    } else {
                                        item = dynamic_cast<CompleteXray *>(event->getItem());
                                        if (item != NULL) {
                                            completeXray((CompleteXray *) event->getItem());
                                        } else {
                                            item = dynamic_cast<StartTreatment *>(event->getItem());
                                            if (item != NULL) {
                                                startTreatment((StartTreatment *) event->getItem());
                                            } else {
                                                item = dynamic_cast<Discharge *>(event->getItem());
                                                if (item != NULL) {
                                                    processDischarge((Discharge *) event->getItem());
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }



    cout<< "Current Time : " << currentTime<< endl;


}


/*  This method processes the Arrival , makes a start Assessment event
    and adds it to the event list.
 */
void EmergencyDepartment::processArrival(Arrival *arrival){
    admission->getQ()->enqueue(arrival->getPatient());
    currentTime = arrival->getPatient()->getArrivalTime();

    cout << "Time   " << currentTime << ": Patient : " << arrival->getPatient()->getId();
    int nurse = admission->Available();
    if(nurse) {
        cout <<" arrives in ED Assessment nurse is free;(Patient Assessment begins)."<< endl;
        StartAssessment * start = new StartAssessment(arrival->getPatient(), arrival->getPatient()->getArrivalTime() , nurse);
        EventList->enqueue(start,start->getTime());
    }else{
        cout <<" arrives in ED Assessment nurse is busy;(Patient is queued)."<< endl;
    }

} // process Arrival .



// This is a start assessment which makes a complete assessment event.
void EmergencyDepartment::startAssessment(StartAssessment * start) {

    admission->getQ()->dequeue();
    cout << "Time   " << currentTime << ": Patient : " << start->getPatient()->getId()<<" begins assessment of length "<< start->getPatient()->getAssessmentTime()<<"."<<endl;
    Patient * p = start->getPatient();
    int nurse = start->getNurse();
    admission->setNurseTreating(nurse);
    CompleteAssessment * complete = new CompleteAssessment(p , start->getTime()+p->getAssessmentTime(),nurse);
    EventList->enqueue(complete,complete->getTime());
    admission->setPatientWaitTime(admission->getPatientWaitTime() + start->getTime()-p->getArrivalTime());


}


/* This is a complete assessment.
This event checks for the requirements of the patient and sends them
to the stations accordingly */
void EmergencyDepartment::completeAssessment(CompleteAssessment *a) {

    admission->setPatientsServed(admission->getPatientsServed()+1);
    admission->setStationActive(admission->getStationActive()+a->getPatient()->getAssessmentTime());
    Patient * assess = a->getPatient();
    currentTime = a->getTime();
    admission->setNurseTreating(a->getNurse());
    cout << "Time   " << currentTime << ": Patient : " << assess->getId() << " completes assessment, assigned priority of "<< assess->getPriority();


    if(!admission->getQ()->isEmpty()) {
        Patient *next = (Patient *) admission->getQ()->getFront()->getItem();
        StartAssessment * start = new StartAssessment(next,a->getTime(),a->getNurse());
        EventList->enqueue(start , currentTime);

    }


    //checking for requirements.
    if(assess->getRequirements().substr(0,1).compare("B")==0) {

        bloodLab->getBloodLabPq()->enqueue(a->getPatient(), a->getTime());
        a->getPatient()->setBloodLabArrival(a->getTime());
        int tech = bloodLab->BloodtechAvailable();
        if (tech) {
            cout << " Scheduled for blood work." << endl;
            Patient *next = (Patient *) bloodLab->getBloodLabPq()->getFront()->getItem();
            StartBloodWork  * start = new StartBloodWork(next,currentTime,tech);
            EventList->enqueue(start , currentTime);

        } else {
            cout << " queued for blood work." << endl;

        }

    }else if(assess->getRequirements().substr(1).compare("X")==0){

        xrayLab->getP()->enqueue(a->getPatient(), a->getPatient()->getPriority());
        a->getPatient()->setXrayArrival(a->getTime());
        int tech = xrayLab->Available();
        if (tech) {
            cout << " ,Scheduled for X-ray." << endl;
            Patient *next = (Patient *) xrayLab->getP()->getFront()->getItem();
            StartXray *start = new StartXray(next, currentTime, tech);
            EventList->enqueue(start, currentTime);

        } else {
            cout << " ,queued for X-ray." << endl;

        }
    }else if(assess->getRequirements().substr(0).compare("--")==0) {

        treatmentRoom->getTreatmentQueue()->enqueue(a->getPatient(), a->getPatient()->getPriority());
        a->getPatient()->setTreatmentArrival(a->getTime());
        cout << " ,queued for treatment." << endl;
    }


}

//This is a start xray event which makes a complete xray event .
void EmergencyDepartment::startXray(StartXray *startXray) {
    xrayLab->getP()->dequeue();

    cout << "Time   " << currentTime << ": Patient : " << startXray ->getPatient()->getId() << " begins X-ray"<<endl;

    Patient * p = startXray->getPatient();
    int tech = startXray->getTech();
    xrayLab->setTechTreating();
    CompleteXray * complete = new CompleteXray(p , currentTime+Const::XRayTime,tech);
    EventList->enqueue(complete,complete->getTime());
    xrayLab->setPatientWaitTime(xrayLab->getPatientWaitTime()+ startXray->getTime() - startXray->getPatient()->getXrayArrival());
}


/* This is a complete xray event.
This event checks sends them to the treatment.  */
void EmergencyDepartment::completeXray(CompleteXray *completeXray) {
    xrayLab->setPatientsServed(xrayLab->getPatientsServed() + 1);
    xrayLab->setStationActive(xrayLab->getStationActive() + Const::XRayTime);
    Patient *assess = completeXray->getPatient();
    currentTime = completeXray->getTime();
    xrayLab->setTechTreating();

    cout << "Time   " << currentTime << ": Patient : " << completeXray ->getPatient()->getId()<< " completes X-ray.";


    if(!xrayLab->getP()->isEmpty()) {
        Patient *next = (Patient *) xrayLab->getP()->getFront()->getItem();
        StartXray *start = new StartXray(next, currentTime, completeXray->getTech());
        EventList->enqueue(start, currentTime);

    }

    treatmentRoom->getTreatmentQueue()->enqueue(completeXray->getPatient(), completeXray->getPatient()->getPriority());
    completeXray->getPatient()->setTreatmentArrival(completeXray->getTime());
    int doc = treatmentRoom->doctorAvailable();
    if (doc) {
        cout << " ,Scheduled for treatment." << endl;
        Patient *next = (Patient *) treatmentRoom->getTreatmentQueue()->getFront()->getItem();
        StartTreatment * start = new StartTreatment(next,currentTime,doc);
        EventList->enqueue(start , currentTime);


    } else {
        cout << " ,queued for treatment." << endl;
    }

}

//This is a start bloodwork event which makes a compelte bloodwork  event .
void EmergencyDepartment::startBloodWork(StartBloodWork *startBloodWork) {
    bloodLab->getBloodLabPq()->dequeue();

    cout << "Time   " << currentTime << ": Patient : " << startBloodWork ->getPatient()->getId()<< " begins blood work"<<endl;

    Patient * p = startBloodWork->getPatient();
    int tech = startBloodWork->getTech();
    bloodLab->setBloodTechTreating(tech);
    CompleteBloodWork * complete = new CompleteBloodWork(p , currentTime+Const::bloodWorkTime,tech);
    EventList->enqueue(complete,complete->getTime());
    bloodLab->setPatientWaitTime(bloodLab->getPatientWaitTime()+startBloodWork->getTime()-startBloodWork->getPatient()->getBloodLabArrival());
}




/* This is a complete blood work event.
This event checks sends them to the treatment or the xray .  */
void EmergencyDepartment::completeBloodWork(CompleteBloodWork *completeBloodWork) {
    bloodLab->setPatientsServed(bloodLab->getPatientsServed() + 1);
    bloodLab->setStationActive(bloodLab->getStationActive() + Const::bloodWorkTime);
    Patient *assess = completeBloodWork->getPatient();
    currentTime = completeBloodWork->getTime();
    bloodLab->setBloodTechTreating(completeBloodWork->getTech());

    cout << "Time   " << currentTime << ": Patient : " << completeBloodWork ->getPatient()->getId()
         << " completes blood work";

    if(!bloodLab->getBloodLabPq()->isEmpty()) {
        Patient *next = (Patient *) bloodLab->getBloodLabPq()->getFront()->getItem();
        StartBloodWork  * start = new StartBloodWork(next,currentTime,completeBloodWork->getTech());
        EventList->enqueue(start , currentTime);

    }


    //checks if xray is needed .
    if(assess->getRequirements().substr(1).compare("X")==0) {

        xrayLab->getP()->enqueue(completeBloodWork->getPatient(), completeBloodWork->getPatient()->getPriority());
        completeBloodWork->getPatient()->setXrayArrival(currentTime);

        int tech = xrayLab->Available();
        if (tech) {
            cout << " ,Scheduled for X-ray." << endl;
            Patient *next = (Patient *) xrayLab->getP()->getFront()->getItem();
            StartXray *start = new StartXray(next, currentTime, tech);
            EventList->enqueue(start, currentTime);

        } else {
            cout << " ,queued for X-ray." << endl;

        }
    }else {

        treatmentRoom->getTreatmentQueue()->enqueue(completeBloodWork->getPatient(), completeBloodWork->getPatient()->getPriority());
        completeBloodWork->getPatient()->setTreatmentArrival(completeBloodWork->getTime());
        int doc = treatmentRoom->doctorAvailable();
        if (doc) {
            cout << " ,Scheduled for treatment." << endl;
            Patient *next = (Patient *) treatmentRoom->getTreatmentQueue()->getFront()->getItem();
            StartTreatment * start = new StartTreatment(next,currentTime,doc);
            EventList->enqueue(start , currentTime);

        } else {
            cout << " ,queued for treatment." << endl;
        }


    }

}





/* This is a start treatment event which makes a discharge event and adds it to the event list. */
void EmergencyDepartment::startTreatment(StartTreatment *startTreatment) {
    treatmentRoom->setPatientsServed(treatmentRoom->getPatientsServed()+1);
    treatmentRoom->getTreatmentQueue()->dequeue();

    cout << "Time   " << currentTime << ": Patient : " << startTreatment ->getPatient()->getId()
         << " starts treatment of length "<< startTreatment->getPatient()->getTreatmentTime()<<endl;

    Patient * p = startTreatment->getPatient();
    int tech = startTreatment->getTech();
    treatmentRoom->setDocTreating(tech);
    Discharge * complete = new Discharge(p , currentTime+p->getTreatmentTime(),tech);
    EventList->enqueue(complete,complete->getTime());
    treatmentRoom->setPatientWaitTime(treatmentRoom->getPatientWaitTime() + startTreatment->getTime() - p->getTreatmentArrival());
}



//This discharges the patient from the Emergency department.
void EmergencyDepartment::processDischarge(Discharge *discharge) {
    treatmentRoom->setStationActive(treatmentRoom->getStationActive()+discharge->getPatient()->getTreatmentTime());
    Patient * assess = discharge->getPatient();
    currentTime = discharge->getTime();

    treatmentRoom->setDocTreating(discharge->getDoc());
    cout << "Time   " << currentTime << ": Patient : " << discharge ->getPatient()->getId() << " discharged at time " << currentTime << endl;


    if(!treatmentRoom->getTreatmentQueue()->isEmpty()) {
        Patient *next = (Patient *) treatmentRoom->getTreatmentQueue()->getFront()->getItem();
        StartTreatment * start = new StartTreatment(next,currentTime,discharge->getDoc());
        EventList->enqueue(start , currentTime);

    }

}


//This calculates and prints all the info
void EmergencyDepartment::summary() {
    cout<< setprecision(1)<<fixed;

    if(admission->getPatientsServed()!=0) {
        admission->setAveWaitingTime((double)admission->getPatientWaitTime() / admission->getPatientsServed());
        admission->setAveServiceTime((double)admission->getStationActive() / admission->getPatientsServed());
    }
    if(xrayLab->getPatientsServed()!=0) {
        xrayLab->setAveWaitingTime((double)xrayLab->getPatientWaitTime() / xrayLab->getPatientsServed());
        xrayLab->setAveServiceTime((double)xrayLab->getStationActive() / xrayLab->getPatientsServed());
    }
    if(treatmentRoom->getPatientsServed()!=0) {
        treatmentRoom->setAveWaitingTime((double)treatmentRoom->getPatientWaitTime() / treatmentRoom->getPatientsServed());
        treatmentRoom->setAveServiceTime((double)treatmentRoom->getStationActive() / treatmentRoom->getPatientsServed());
    }
    if(bloodLab->getPatientsServed()!=0) {
        bloodLab->setAveWaitingTime((double)bloodLab->getPatientWaitTime() / bloodLab->getPatientsServed());
        bloodLab->setAveServiceTime((double)bloodLab->getStationActive() / bloodLab->getPatientsServed());
    }

    cout <<"\n"
           "               Total       Service Time          Wait Time\n"
           "  Station     patients    Total   Average      Total   Average\n"
           "----------------------------------------------------------------" << endl;
    admission->printSummary();
    bloodLab->printSummary();
    xrayLab->printSummary();
    treatmentRoom->printSummary();

}