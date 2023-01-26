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
    std::string *a;
    int listCapacity;
    int listSize;
public:
    stringList (int listCapacity = 100);//Zach
    ~stringList ();//Zach
    bool insert (std::string text); //parker
    bool add (std::string text); //parker 
    bool insertAt (int index,std::string text); //parker
    bool deleteAt (int index,std::string &text);
    void clear();//Zach
    void printIt() const;//Zach
    int getIndex(std::string text) const;
    bool readAt(int index, std::string &text) const; //parker
    int count() const;//Zach
};

#endif