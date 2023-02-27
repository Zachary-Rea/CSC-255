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
treeCount=0;

}

//******************************************************************************
//de-constructor
//Written by Parker

    void clear() {
        int n = 0;
    }

//******************************************************************************
//Private Members
//Swap
//******************************************************************************

void swap (int *x, int *y){

}

//******************************************************************************
//Bubble Up
//******************************************************************************
//written by Parker

void bubbleUp (int index){
    if (index){
        int par = parent(index);
        if(a[index] < a [par]){
            swap(a[index],a[par])
            bubbleUp (par);
        }
    }
}
 
//******************************************************************************
//heapify
//******************************************************************************

void heapify (int index){

}

//******************************************************************************
//Public Members
//******************************************************************************
//Enques value into iPQ; returns true for success; false if full
//Written by Parker

bool enq(text){
    bool rc = false;
    if(treeCount < treeCap){
        a[tc] = text;
        bubbleUp (tc);
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

bool deq(String & text){
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



