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

void cStringList::decVal(int &value){
    if (value > 0) {
        value = value - 1;
    } else {
        value = listCapacity - 1;
    }
}

//******************************************************************************
//Function for Incrementing passed value
//Written by Parker
void cStringList::incVal(int &value){
    if (value < listCapacity) {
        value = value + 1;
    } else {
        value = 0;
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
        if (listCount == 0) {
            last = first;
        } else {
            decVal(first);
        }
        a[first] = text;
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



bool cStringList::insertAt(int index, string text) {
    bool rc = false;
    return rc;
}

//******************************************************************************



bool cStringList::deleteAt(int index, string &text) {
    bool rc = false;
    return rc;
}

//******************************************************************************



bool cStringList::readAt(int index, string &text) {
    bool rc = false;
    return rc;
}

//******************************************************************************



bool cStringList::deleteFirst(string &text) {
    bool rc = false;
    if (listCount > 0) {
        text = a[first];
        incVal(first);
        listCount--;
        rc = true;
    }
    return rc;
}

//******************************************************************************



bool cStringList::deleteLast(string &text) {
    bool rc = false;
    if (listCount > 0) {
        text = a[last];
        decVal(last);
        listCount--;
        rc = true;
    }
    return rc;
}

//******************************************************************************



void cStringList::clear() {
    listCount = 0;
    first = last = 0;
}

//******************************************************************************



int cStringList::count() const{
    return listCount;
}

//******************************************************************************



int cStringList::getIndex(string text) {
    int rc = 0;
    return rc;
}

//******************************************************************************



void cStringList::printIt() const{

}