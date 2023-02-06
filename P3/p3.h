/*
Filename: p3.h
Author(s): Zachary Rea and Parker Ross
Date: 5 February 2023
Description: The header file for p3
*/
#ifndef __P1_H
#define __P1_H

#include <string>
//******************************************************************************
class cStringList {
    private:
        std::string *a;
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
        cStringList(int capacity = 100);
        //De-constructor
        ~cStringList();
        //Function for inserting at beginning of list
        bool insert(std::string text);
        //Function for adding to end of list
        bool add(std::string text);
        //Function for inserting at given index
        bool insertAt(int index, std::string text);
        //Function for deleting at given index
        bool deleteAt(int index, std::string &text);
        //Function for reading at given index
        bool readAt(int index, std::string &text);
        //Function for deleting the first element
        bool deleteFirst(std::string &text);
        //Function for deleting the last element
        bool deleteLast(std::string &text);
        //Function for emptying the list
        void clear();
        //Function for returning the size of the list
        int count() const;
        //Function for returning the first index of a given string
        int getIndex(std::string text);
        //Function for printing the contents of the list
        void printIt();
};
#endif