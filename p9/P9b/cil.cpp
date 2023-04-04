/*
Filename: p3.cpp
Author(s): Zachary Rea and Parker Ross
Date: 5 February 2023
Description: The cpp for circular lists
*/
#include <iostream>  //allows for usage of cin, cout, and cerr

#include "cil.h"

using namespace std;

//******************************************************************************
//Constructors and De-constructors
//******************************************************************************
//Constructor
//Written by Zach
cIntList::cIntList(int listCapacity) {
    this->listCapacity = listCapacity;
    a = new int[listCapacity];
    listCount = 0;
    first = 0;
    last = 0;
}
//******************************************************************************
//De-constructor
//Written by Zach
cIntList::~cIntList() {
    delete [] a;
}
//******************************************************************************
//Private functions
//******************************************************************************
//Function for decrementing passed value
//Written by Parker
void cIntList::decVal(int &value){
    //prevents decVal from going beyond list capacity
    if (value > 0) {
        value = value - 1;
    } else {
        value = listCapacity - 1;
    }
}
//******************************************************************************
//Function for Incrementing passed value
//Written by Parker
void cIntList::incVal(int &value){
    //prevents incVal from going beyond list capacity
    if (value < listCapacity - 1) {
        value = value + 1;
    } else {
        value = 0;
    }
}
//******************************************************************************
//Function for adding a string to the last position
//Written by Zach
bool cIntList::add(int val) {
    bool rc = false;
    if (listCount < listCapacity) {
        //move the last place 
        incVal(last);
        a[last] = val;
        if (listCount == 0) {
            first = last;
        }
        listCount++;
        rc = true;
    }
    return rc;
}
//******************************************************************************
//Function for deleting the first entry
//Written by Zach
bool cIntList::deleteFirst(int &val) {
    bool rc = false;
    if (listCount > 0) {
        //copy the text that is being removed
        val = a[first];
        //move the first indicator 
        incVal(first);
        if (listCount == 1) {
            last = first = 0;
        }
        listCount--;
        rc = true;
    }
    return rc;
}
//******************************************************************************
//Fucntion for clearing list
//written by Parker
void cIntList::clear() {
    //empties list
    listCount = 0;
    first = last = 0;
}
//******************************************************************************
//function for returning size of list
//written by Parker
int cIntList::count() const{
    //returns number of list entries
    return listCount;
}
//******************************************************************************
//Function for printing values in circular list
//Written by Parker
void cIntList::printIt() {
    if (listCount) {
        for (int i = 0; i < listCount; i++) {
            for 
        }
    }
}