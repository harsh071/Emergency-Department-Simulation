//
//
// CLASS: Queue.h
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is a queue.
//
//-----------------------------------------

#ifndef QUEUE_H
#define QUEUE_H


using namespace std;
#include "Item.h"

class Node;

class Queue {

private: //pointers to the queue
    Node * front;
    Node * end;

public:
    //constructor.
    Queue();

    //inserts to the end of the queue.
    void enqueue(Item * item);

    //removes from the front.
    Node * dequeue();

    //verifies if empty
    bool isEmpty();

    //prints the queue
    void print();

    //gets the front item
    Node * getFront();

    //gets the front item
    Node * getEnd();


};




#endif //ASSIGNMENT2_QUEUE_H
