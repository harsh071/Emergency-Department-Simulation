//
//
// CLASS: StartXray.cpp
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is an Xray event of a patient .
//
//-----------------------------------------
#include "StartXray.h"
StartXray::StartXray(Patient* p, int time,int initech) :time(time),p(p),tech(initech) {
}


//Printing the event
void StartXray::print() {
    cout << "Start Xray.. "<<endl;
}

//Getter and setter methods.
int StartXray::getTime(){
    return time;
}


int  StartXray::getTech(){
    return tech;
}



Patient* StartXray::getPatient(){
    return p;
}
