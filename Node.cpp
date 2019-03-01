///
//
// CLASS: Node.cpp
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is a generic Node Class..
//
//-----------------------------------------

#include <iostream>
#include "Node.h"
using namespace std;

Node::Node(Item *initItem, Node *initLink)    // Node constructor without priority
    : theItem(initItem),link(initLink),priority(0){}

Node::Node(Item *initItem, Node *initLink, int initPriority)  //Node constructor with priority
        : theItem(initItem),link(initLink),priority(initPriority){}


Node * Node::getLink(){ // Returns you Link
    return link;
}

Item * Node::getItem() { // Returns the Item
    return theItem;
}

int Node::getPriority() { // Returns the Priority
    return priority;
}

void Node::setLink(Node * setNext){ //Sets the Link
    link = setNext;
}

void Node::print() {  // Prints the contents of the Node.
    if(theItem!=NULL) {
        theItem->print();
        if (link != NULL) {
            link->print();
        }
    }
}