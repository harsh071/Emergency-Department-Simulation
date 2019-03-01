//
//
// CLASS: Event.h
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is an Event of a patient. It is a super class of the event.
//
//-----------------------------------------
#ifndef ASSIGNMENT2_EVENT_H
#define ASSIGNMENT2_EVENT_H

#include "Item.h"

class Event: public Item{
public:
    virtual void print()=0;
    ~Event();
};


#endif //ASSIGNMENT2_EVENT_H
