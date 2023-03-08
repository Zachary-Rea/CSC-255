/*
Filename: p8.h
Author(s): Zachary Rea and Parker Ross
Date: 8 March 2023
Description: The header file for p8
*/
#ifndef __P8_H
#define __P8_H

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
    int capacity() const;//Zach
    //Sorting Functions
    void bubbleSort();
    void selectionSort();
    void insertionSort();
    //Sorting Check
    bool isSorted() const;
    //Swap Function 

    int intList::left(int index) const;
    int intList::right(int index) const;
    int intList::swap(int &x, int &y);
    void intList::heapify(int index);
};

#endif