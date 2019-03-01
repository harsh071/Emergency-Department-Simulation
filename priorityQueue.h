//
//
// CLASS: priorityQueue.h
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is a priority queue.
//
//-----------------------------------------

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
using namespace std;
#include "Item.h"
#include "Node.h"


class priorityQueue{

private:
    Node * front;

public:

    //constructor
    priorityQueue();

    //insert according to the priority
    void enqueue(Item * item , int priority);

    //remove with priority
    Node * dequeue();

    //check if priorityQueue is empty
    bool isEmpty();

    //print the priorityQueue
    void print();

    //gets front of the Queue
    Node * getFront();
};


#endif //ASSIGNMENT2_PRIORITYQUEUE_H
