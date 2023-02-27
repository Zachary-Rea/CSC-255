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

iPQ::iPQ(int n) {
    qCount = 0;
    qCapacity = n;
    a = new string[n];
}

//******************************************************************************
//de-constructor
//Written by Parker

  iPQ::~iPQ(){
    delete[] a;
  }

//******************************************************************************
//Private Members

int iPQ::parent(int index) const{
    return 0;
}
//******************************************************************************
//function to print tree by level
//written by Parker

void iPQ::printIt(int r){
    int start, count, stop;
    count = 1 << r;
    start = count -1;
    stop = start + count;
    if(start < treeCount){
        if(stop > treeCount){
            stop = treeCount;
        }
        count << "row" << r << ":";
        for(int i = start; i < stop; i++){
            count << a[i];
        }
        count << endl;
        printIt(r + 1);
    }
}

//******************************************************************************
//Function to swap two integers with each other

void swap (int *x, int *y){

}

//******************************************************************************
//Function to perform heap Bubble-Up operation
//written by Parker

void iPQ::bubbleUp (int index){
    if (index){
        int par = (treeCount /2-1)(index);
        if(a[index] < a [par]){
            swap(a[index],a[par])
            bubbleUp (par);
        }
    }
}
 
//******************************************************************************
//Function to perform heapify operation


void heapify (int index){

}

//******************************************************************************
//Public Members
//******************************************************************************
//Enques value into iPQ; returns true for success; false if full
//Written by Parker

bool iPQ::enq(string text){
    bool rc = false;
    if(treeCount < treeCap){
        a[treeCount] = text;
        bubbleUp (treeCount);
        treeCount++;
        rc = true;
    }
    return rc;
}

//******************************************************************************
//returns true if IPQ is not empty; removes & returns max value, false if empty
//Written by Parker

bool iPQ::deq(string &text){
    bool rc = treeCount > 0;
    if (rc){
        text = a[0];
        treeCount --;
        a[0] = a[treeCount];
        heapify (0);
    }
    return rc;
}

//******************************************************************************
//clear




