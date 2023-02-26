/*
Filename: p6.cpp
Author(s): Zachary Rea and Parker Ross
Date: 26 February 2023
Description: The cpp for Binary Search Tree
*/
#include <iostream>  //allows for usage of cin, cout, and cerr

#include "p6.h"

using namespace std;

//******************************************************************************
//Constructors and De-constructors
//******************************************************************************
//Constructor
//Written by Parker

iPQ::iPQ(int n){


}
//******************************************************************************
//destructor
//******************************************************************************
//fucntion to delete the array
//Written by Parker

    void iPQ::clear() {
        tc = 0;
    }

//******************************************************************************
//enq
//******************************************************************************
//Enques value into iPQ; returns true for success; false if full
//Written by Parker

bool iPQ::enq(text){
    if(tc < tCap){
        a[tc] = text;
        bubble up (tc);
        tC++;
        rc = true;
    }
    return rc;
}

//******************************************************************************
//deq
//******************************************************************************
//returns true if IPQ is not empty; removes & returns max value, false if empty
//Written by Parker

bool iPQ::deq(String & text){
    bool rc = tc > 0;
    if (rc){
        text = a [0];
        tC --;
        a[0] = a[tc];
        heipify (0);
    }
    return rc;
}

//******************************************************************************
//clear
//******************************************************************************
//removes all entries from the iPQ
//Written by Parker

