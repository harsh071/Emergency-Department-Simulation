///
//
// CLASS: Item.h
//
// Author: Harsh Patel , 7846258
//
// REMARKS: This is a generic Item.
//
//-----------------------------------------


#ifndef ITEM_H
#define ITEM_H


class Item {  //abstract item class

public:
    virtual void print()=0;   // abstract print method.
    ~Item();

};


#endif //ASSIGNMENT2_ITEM_H
