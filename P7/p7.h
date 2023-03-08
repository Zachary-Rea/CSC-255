/*
Filename: p7.h
Author(s): Zachary Rea and Parker Ross
Date: 7 March 2023
Description: The header file for p7
*/
#ifndef __P7_H
#define __P7_H

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
    int getIndex(int key) const;
    int readAt(int index, int &key) const; //parker
    int count() const;//Zach
    //Sorting Functions
    void bubbleSort();
    void selectionSort();
    void insertionSort();
    //Sorting Check
    bool isSorted() const;
};

#endif