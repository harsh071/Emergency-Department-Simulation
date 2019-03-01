//
//
// CLASS: Queue.cpp
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is a queue.
//
//-----------------------------------------

#include <iostream>
#include "Queue.h"
#include "Node.h"
using namespace std;
class Item;

Queue::Queue() : front(NULL),end(NULL){} //constructor.


void Queue::enqueue(Item *item) { //inserts item to the end.
    Node * newNode =  new Node(item, NULL);
    if(front == NULL){
        front =  newNode;
        end = newNode;
    }else{
        end->setLink(newNode);
        end = end->getLink();
    }

}//enqueue

Node * Queue::dequeue() { //removes the first item .
    Node * remove = front;
    if(front!=NULL) {
        front = front->getLink();
    }

    return remove;
}

void Queue::print() { // prints the queue
    if(front!=NULL) {
        front->print();
    }
}

bool Queue::isEmpty() { // checks if the queue is empty
    bool empty = false;
    if(front==NULL){
        empty = true;
    }
    return empty;
}


Node * Queue::getFront() {
    return front;
}

Node * Queue::getEnd() {
    return end;
}


