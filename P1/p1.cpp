/*
Filename: p1.cpp
Author(s): Zachary Rea and Parker Ross
Date: 22 January 2023
Description: Program for creation and modification of stringList array
*/
#include <iostream>  //allows for usage of cin, cout, and cerr
#include <string.h> //allows for usage of the string type in namespace std

using namespace std;

#include "p1.h"


//******************************************************************************

stringList::stringList (int listCapacity) { //Zach
    this->listCapacity = listCapacity;  //set the capacity of the list to the passed in value 
    a = new string[listCapacity];  //create a new string array of the given capacity
    listSize = 0;  //set the current used space in the array to 0
}

stringList::~stringList () { //Zach
    delete[] a; //delete the array "a"
}

bool stringList::insert(string text) { // Parker
bool rc = listCapacity > listSize; //Making sure we have room to move everything down to insert a new string
if (rc) {  //if rc is true
    for (int i = listSize; i > 0; i--){//runs through the list, starting from the end
        a [i] = a[i-1];//moves each index over by one
    }
    a[0] = text;//inserts the new string at begining
    listSize++;
} 
return rc;
}

bool stringList::add(string text) { // Parker
bool rc = listCapacity > listSize;// checking to make sure we have room at the end to add a new string
if (rc) { // if rc is true 
    a [listSize] = text; // using list size to place the string at the end
    listSize++; //increasing list size to be accurate when string is added
}
return rc;
}

bool stringList::insertAt(int index, string text) { // Parker
bool rc = listCapacity > listSize && index < listSize && index >= 0; 
//Making sure we have room to insert a new string and **zach's idea** making sure we have a valid index
if (rc) {  //if rc is true
    for (int i = listSize; i > index; i--){//runs through the list starting from the end up to index
        a [i] = a[i-1];//moves each index to the right
    }
    a[index] = text;//insert the new string at the begining
    listSize++; //increasing list size to be accurate when string is added
} 
return rc;
}

bool stringList::deleteAt(int index, string &text) { //Parker
bool rc = listSize > index && index >= 0; // **Zach's idea** prevents user from deleting anything outside of the list
    if (rc){// if rc is true
        text = a[index];// sets text to the value of the item deleted
         for (int i = index; i < listSize; i++){ //runs through the list starting from the index
            a[i] = a[i+1]; //moves the each index to the left
    }
    listSize--; //decreasing list size to be accurate when string is removed
}
return rc;
}

void stringList::clear() { //Zach
    listSize = 0; //set variable size to 0
}

void stringList::printIt() const{ //Zach
for (int i = 0;i < listSize; i++) { //iterate through the array 
    cout << "At pos " << i << " there is " << a[i] << "\n"; 
    //print out the index and contents of the array 
}
}

int stringList::getIndex(string text) const{ //Zach
    int rc = -1; //set the default return to -1
    int count = 0; //set a counter for the times the string is found
    for (int i = 0;i < listSize - 1;i++) { //iterate through the array at least once
        if (a[i] == text && count == 0) {
            rc = i;
            count++;
        }
    }
    return rc;
}

int stringList::readAt(int index, string &text) const{ // Parker
    int rc = -1; // if index is not true -1 will be the default value
    if (index < listSize && index >= 0) { //**Zach's idea** making sure that the index is valid
    rc = index; // setting rc to index if its true
    text = a[index]; // sets text to the string at the given index
}
    return rc;
}

int stringList::count() const{ //Zach
    return listSize; //returns the size of the array
}