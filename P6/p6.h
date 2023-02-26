/*
Filename: p6.h
Author(s): Zachary Rea and Parker Ross
Date: 26 February 2023
Description: The header file for p4
*/
#ifndef __P6_H
#define __P6_H

#include <string>
//******************************************************************************

class iPQ {
    private:
        int *values;
        int qCount;
        int qCapacity;

        int parent(int index) const;
        int left(int index) const;
        int right(int index) const;
        void swap(int *x, int *y);
        void bubbleUp(int index);
        void heapify(int index) ;
        void printIt(int ind, int count) const;

    public:
        //constructor
        iPQ(int n = 100);
        //De-constructor
        ~iPQ(); 
        bool enq(int v);
        bool deq(int &v);
        void printIt() const;
        void clear();
        int count() const;
};
#endif