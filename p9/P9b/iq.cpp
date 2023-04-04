/*
Filename: iq.cpp
Author(s): Zachary Rea and Parker Ross
Date: 4 April 2023
Description: The cpp for iq
*/
#include "iq.h"
#include <iostream>

using namespace std;

//******************************************************************************
//Constructors and Destructors
//******************************************************************************
//Constructor 
//Written by Zach
iQ::iQ(int n) {
    theList = new cIntList(n);
}
//******************************************************************************
//Deconstructor
//Written by Zach
iQ::~iQ() {
    theList->~cIntList();
}
//******************************************************************************
//Function to enque the given value
//Written by Zach
bool iQ::enq(int v) {
    bool rc = theList->add(v);
    return rc;
}
//******************************************************************************
//Function to deque the first value 
//Written by Zach
bool iQ::deq(int &v) {
    bool rc = theList->deleteFirst(v);
    return rc;
}
//******************************************************************************
//Function to clear the iQ
//Written by Zach
void iQ::clear() {
    theList->clear();
}
//******************************************************************************
//Function to return number of items
//Written by Zach
int iQ::count() const{
    return theList->count();
}
//******************************************************************************
//Function to print the contents of the iQ
//Written by Zach
void iQ::printIt() const{
    theList->printIt();
}