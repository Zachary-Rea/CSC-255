/*
Filename: cil.h
Author(s): Zachary Rea and Parker Ross
Date: 4 April 2023
Description: The header file for cil
*/
#ifndef __CIL_H
#define __CIL_H

//******************************************************************************
class cIntList {
    private:
        int *a;
        int listCapacity;
        int listCount;
        int first;
        int last;
        //Function for incrementing value
        void incVal(int &value);
        //Function for decrementing value
        void decVal(int &value);
    public:
        //Constructor
        cIntList(int listCapacity = 100);
        //De-constructor
        ~cIntList();
        //Function for adding to end of list
        bool add(int val);
        //Function for deleting the first element
        bool deleteFirst(int &val);
        //Function for emptying the list
        void clear();
        //Function for returning the size of the list
        int count() const;
        //Function for printing the contents of the list
        void printIt();
};
#endif