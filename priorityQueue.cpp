//
//
// CLASS: priorityQueue.cpp
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is a priority queue.
//
//-----------------------------------------

#include <iostream>
#include "priorityQueue.h"
#include "Node.h"

priorityQueue::priorityQueue() :front(NULL) {} //constructor


void priorityQueue::enqueue(Item * item , int priority) { // Insert according to the priority
    Node * temp =  new Node(item,NULL,priority);
    Node * curr; // Node pointer
    if(front==NULL || priority < (int)front->getPriority()){
        temp->setLink(front);
        front = temp;
    }else{
        curr = front;
        while(curr->getLink()!=NULL && priority>= (int)curr->getLink()->getPriority()){
            // while the priority is greater than curr
            curr = curr->getLink();
        }

        temp->setLink(curr->getLink());
        curr->setLink(temp);
    }// end while
} // enqueue

Node * priorityQueue::dequeue() { // remove the item with the highest priority
    Node * remove = front;
    if(front!=NULL) {
        front = front->getLink();
    }
    return remove;
} //dequeue

void priorityQueue::print() { // Prints the Queue
    if(front!=NULL) {
        front->print();
    }
} // print

bool priorityQueue::isEmpty() { // verifies if the Queue is empty or not.

    bool empty = false;
    if(front == NULL){
        empty = true;
    }

    return empty;
} // isEmpty


Node * priorityQueue::getFront() {
    return front;
}
