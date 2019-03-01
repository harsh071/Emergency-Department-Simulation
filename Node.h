///
//
// CLASS: Node.h
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is a generic Node.
//
//-----------------------------------------

#ifndef NODE_H
#define NODE_H
using namespace std;
#include "Item.h"

class Node {

    private:
    //private variables holding an Item , Link and its priority.

        Item *theItem;
        Node* link;
        int priority;

    public:
        //Constructors.
        Node(Item *initItem, Node *initLink);
        Node(Item *initItem, Node *initLink,int priority);

        //returns the Link
        Node * getLink();

        //returns the Item
        Item * getItem();

        //returns the priority
        int getPriority();

        //Sets the link
        void setLink(Node * setNext);

        //Prints the content in the node and everything connected to it.
        void print();

};


#endif //ASSIGNMENT2_NODE_H
