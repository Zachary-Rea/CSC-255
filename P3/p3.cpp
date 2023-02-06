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
//Written by Zach

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
//Function for inserting a string at the given index 
//Written by Zach

bool cStringList::insertAt(int index, string text) {
    bool rc = false;
    if ((index < listCount) && (listCount < listCapacity) && (index >= 0)) {
        incVal(last);
        if (index == 0) {
            decVal(first);
            for (int i = last;i != first;) {
                int temp = i;
                decVal(temp);
                a[i] = a[temp];
                decVal(i);
            }
        } else {
            for (int i = last;i >= index;) {
                int temp = i;
                decVal(temp);
                a[i] = a[temp];
                decVal(i);
            }
        }
        a[index] = text;
        listCount++;
        rc = true;
    }
    return rc;
}

//******************************************************************************



bool cStringList::deleteAt(int index, string &text) {
    bool rc = false;
    if ((index >= 0) && (index < listCount) && (listCount > 0)) {
        text = a[index];
        int ind = index;
        while (ind != last) {
            int move = ind;
            incVal(move);
            a[ind] = a[move];
            incVal(ind);
        }
        decVal(last);
        listCount--;
        rc = true;
    }
    return rc;
}

//******************************************************************************
//Function for reading the value at given index
//written by Parker

bool cStringList::readAt(int index, string &text) {
    bool rc = false; 
    int read = first;
    int temp = last;
    incVal(temp);
    int i = 0;
    while (read != temp){
    if (index < listCapacity && index > 0){
        text = a[index];
        }
    }
    return rc;
}

//******************************************************************************
//Function for deleting the first entry
//Written by Zach

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
//Function for deleting the last entry 
//Written by Zach

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
//Fucntion for clearing list
//written by Parker
void cStringList::clear() {
    listCount = 0;
    first = last = 0;
}

//******************************************************************************
//function for returning size of list
//written by Parker
int cStringList::count() const{
    return listCount;
}

//******************************************************************************
//Function for returning the index of the given string
//Written by Zach

int cStringList::getIndex(string text) {
    int rc = -1;
    int i = first;
    while ((a[i] != text) && (i != last)) {
        incVal(i);
    }
    if (a[i] == text) {
        rc = i;
    }
    return rc;
}

//******************************************************************************
//Function for printing values in circular list
//Written by Parker
void cStringList::printIt() {
    if (listCount) {
        int print = first;
        int temp = last;
        incVal(temp);
        int i = 0;  
        while (print != temp){
            cout << "At pos " << i << " there is " << a[print] << "\n"; 
            incVal(print);
            i++;
        }  
    }
}