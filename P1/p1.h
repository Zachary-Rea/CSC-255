/*
Filename: p1.h
Author(s): Zachary Rea and Parker Ross
Date: 22 January 2023
Description: The header file for p1
*/
#ifndef __P1_H
#define __P1_H

#include <string>

class stringList {
private:
    std::string *a;//creates array a of string type
    int listCapacity;//total capacity of the array 
    int listSize;//current filled elements of the array
public:
    stringList (int listCapacity = 100);//(Zach)Constructor for the string list object
    ~stringList ();//(Zach)Destructor for the string list object 
    bool insert (std::string text);//(Parker)Inserts the given string at the top of the list
    bool add (std::string text);//(Parker)Adds the given string to the bottom of the list
    bool insertAt (int index,std::string text);//(Parker)Inserts the given string at the given index
    bool deleteAt (int index,std::string &text);//(Parker)Deletes the string at the given index
    void clear();//(Zach)Sets the current size of the list to 0 removing all entries 
    void printIt() const;//(Zach)Prints the entire contents of the array 
    int getIndex(std::string text) const;//(Zach)Returns the first index of the given string in the list
    bool readAt(int index, std::string &text) const;//(Parker)Reads the string at the given index
    int count() const;//(Zach)Returns the current count of items in the list
};

#endif