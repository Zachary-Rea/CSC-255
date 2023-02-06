/*
Filename: p3.cpp
Author(s): Zachary Rea and Parker Ross
Date: 27 January 2023
Description: 
*/
#include <iostream>  //allows for usage of cin, cout, and cerr

#include "p3.h"

using namespace std;

//******************************************************************************
//Constructors and De-constructors
//******************************************************************************
//Constructor
//Written by Zach

cStringList::cStringList(int capacity) {
    this->listCapacity = listCapacity;
    a = new string[listCapacity];
    listCount = 0;
    first = 0;
    last = 0;
}

//******************************************************************************
//De-constructor

cStringList::~cStringList() {
    delete [] a;
}

//******************************************************************************
//Private functions
//******************************************************************************
//Function for decrementing passed value
//Written by Parker

void decVal(int &value){
    dec(ind){
        ind = ind -1;
        if(ind < 0){
            ind = cap -1;
        }
    }
}

//Function for Incrementing passed value
//Written by Parker
void incVal(int &value){
    dec(ind){
        ind = ind +1;
        if(ind < 0){
            ind = ind % cap; // = 0 ??
    }
}

   


//******************************************************************************
//Public functions
//******************************************************************************
//Function for inserting a string at first position
//Written by Zach

bool cStringList::insert(string text) {
    bool rc = false;
    if (listCount < listCapacity) {
        decVal(first);
        a[first] = text;
        if (listCount == 0) {
            last = first;
        }
        listCount++;
        rc = true;
    }
    return rc;
}

//******************************************************************************
//Function for adding a string to the last position
//Written by Zach

bool cStringList::add(string text) {
    bool rc = false;
    if (listCount < listCapacity) {
        incVal(last);
        a[last] = text;
        if (listCount == 0) {
            first = last;
        }
        listCount++;
        rc = true;
    }
    return rc;
}

//******************************************************************************