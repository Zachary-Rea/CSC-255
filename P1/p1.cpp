/*
Filename: p1.cpp
Author(s): Zachary Rea and Parker Ross
Date: 22 January 2023
Description: Program for creation and modification of stringList array
*/
#include <iostream>
#include <fstream>
#include <string.h>

#include "p1.h"

using namespace std;

//******************************************************************************

stringList::stringList (int lSize) { //Zach
    listCapacity = lSize;
    a = new string[listCapacity];
    listSize = 0;
}

stringList::~stringList () { //Zach
    delete[] a; //delete the array "a"
}

bool insert(string text){ // parker

}

bool add(string text){ // parker

}

bool insertAt(int index, string text){ // parker

}

bool stringList::deleteAt(int index, string text) {
    return true;
}

void stringList::clear(){ //Zach
    listSize = 0; //set variable size to 0
}

void stringList::printIt() const{ //Zach
for (int i = 0;i < listSize; i++) { //iterate through the array 
    cout << "at pos " << i << " there is " << a[i] << "\n"; 
    //print out the index and contents of the array 
}
}

int stringList::getIndex(string text) const{
    int index = 1;
    return index;
}

bool readAt(int index){ // parker

}

int stringList::count() const{ //Zach
    return listSize; //returns the size of the array
}