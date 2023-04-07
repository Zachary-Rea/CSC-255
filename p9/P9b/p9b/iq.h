/*
Filename: iq.h
Author(s): Zachary Rea and Parker Ross
Date: 4 April 2023
Description: The header file for iq
*/
#ifndef __IQ_H
#define __IQ_H

#include "cil.h"
//******************************************************************************
class iQ {
    private:
        cIntList *theList;
    public:
        //Constructor
        iQ(int n = 100);
        //Deconstructor
        ~iQ();
        //Enque value v
        bool enq(int v);
        //Deque first value 
        bool deq(int &v);
        //Clear the iQ
        void clear();
        //Return number of items in iQ
        int count() const;
        //Print contents of iQ
        void printIt() const;
};
#endif