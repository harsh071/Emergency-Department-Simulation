/*
 * A2main.cpp
 * COMP 2150 Object Orientation
 * (C) Computer Science, University of Manitoba
 *
 * Main function for Assignment 2
 */

//-----------------------------------------
// NAME		: Harsh Patel
// STUDENT NUMBER	: 7846258
// COURSE		: COMP 2150
// INSTRUCTOR	: Gord Boyer
// ASSIGNMENT	: assignment #2
// QUESTION	: question #1
//
// REMARKS: This is an Emergency Simulation.
//
//-----------------------------------------
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "priorityQueue.h"
#include "Patient.h"
#include "EmergencyDepartment.h"

using namespace std;


int main(int argc, char *argv[]){
//      if(argc < 2){
//      cout << "Usage: " << argv[0] << " <file name>\n";
//      exit(1);
//    }

  EmergencyDepartment * department = new EmergencyDepartment();

  cout << "Simulation begins...\n";

  department->simulate("harsh");

  cout << "\n...Simulation complete.    Final Summary;" << endl;

  department->summary();

  cout << "\nEnd of processing.\n";

  return 0;
}// main
