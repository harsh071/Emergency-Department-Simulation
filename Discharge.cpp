//
// CLASS: Discharge.cpp
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is an Discharge event of a patient .
//
//-----------------------------------------

#include "Discharge.h"
Discharge::Discharge(Patient* p, int time,int inittech) :time(time),p(p),tech(inittech){
}

void Discharge::print() {
    cout<< "Discharge..."<<endl ;
}

int Discharge::getTime() {
    return time;
}

Patient * Discharge::getPatient() {
    return p;
}

int Discharge::getDoc(){
    return tech;
}