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
        //function fo returning parent's index for given index
        int left(int index) const;
        //function for returning index of left child
        int right(int index) const;
        //function for returning index of right child
        void printIt(int ind, int count) const;
        //function for printing by level in tree
        void swap(int *x, int *y);
        // functino for swapping two integers
        void bubbleUp(int index);
        void heapify(int index) ;

    public:
        //constructor
        iPQ(int n = 100);
        //De-constructor
        ~iPQ(); 
        bool enq(int v);
        //function for Enqueueing v into iPQ
        bool deq(int &v);
        //function for removing & returning max value in PQ
        void printIt() const;
        //function for removing all entries from iPQ
        void clear();
        //function for returning number of entries
        int count() const;
};
#endif