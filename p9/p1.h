/*
Filename: p1.h
Author(s): Zachary Rea and Parker Ross
Date: 26 March 2023
Description: The header file for p1
*/
#ifndef __P1_H
#define __P1_H

//******************************************************************************
class intList {
private:
    int *a;
    int listCapacity;
    int listSize;
public:
    //Constructors and Destructors
    intList (int listCapacity = 100);//Zach
    ~intList ();//Zach
    //Public Functions 
    bool insert (int key); //parker
    bool add (int key); //parker 
    bool insertAt (int index,int key); //parker
    bool deleteAt (int index,int &key);
    void clear();//Zach
    void printIt(int n) const;//Zach
    int getIndex(int key) const; //zach
    int readAt(int index, int &key) const; //parker
    int count(); //zach
};
#endif