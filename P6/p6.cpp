/*
Filename: p6.cpp
Author(s): Zachary Rea and Parker Ross
Date: 26 February 2023
Description: The cpp for Binary Search Tree
*/
#include <iostream>  //allows for usage of cin, cout, and cerr

#include "p6.h"

using namespace std;
#include <cmath>
//******************************************************************************
//Constructors and De-constructors
//******************************************************************************
//Constructor
//Written by Parker

iPQ::iPQ(int n) {
    qCount = 0;
    qCapacity = n;
    values = new int[n];
}

//******************************************************************************
//de-constructor
//Written by Parker

iPQ::~iPQ() {
    delete[] values;
}

//******************************************************************************
//Private Members
//Written by Zach

int iPQ::parent(int index) const{
    int rc;
    if (index) {
        rc = (index-1)/2;
    } else {
        rc = 0;
    }
    return rc;
}

//******************************************************************************
//Function for finding left child
//Written by Zach

int iPQ::left(int index) const{
    return (2*index)+1;
}

//******************************************************************************
//Function for finding right child
//Written by Zach

int iPQ::right(int index) const{
    return (left(index)+1);
}
//******************************************************************************
//function to print tree by level
//written by Parker

void iPQ::printIt(int ind, int count) const{
    int start, stop;
    count = 1 << ind;
    start = count - 1;
    stop = start + count;
    if(start < qCount){
        if(stop > qCount){
            stop = qCount;
        }
        cout << "Level[" << ind << "]-> ";
        for(int i = start; i < stop; i++){
            cout << values[i] << " ";
        }
        cout << endl;
        printIt(ind + 1,count);
        ind++;
    }
}

//******************************************************************************
//Function to swap two integers with each other
//Written by Zach

void iPQ::swap(int x, int y) {
    values[qCount] = values[x];
    values[x] = values[y];
    values[y] = values[qCount];
}

//******************************************************************************
//Function to perform heap Bubble-Up operation
//written by Parker

void iPQ::bubbleUp(int index) {
    if (index) {
        int par = parent(index);
        if(values[index] > values[par]) {
            swap(index,par);
            bubbleUp(par);
        }
    }
}

//******************************************************************************
//Function to perform heapify operation
//Written by Zach

void iPQ::heapify(int index) {
    if (index) {
        int larger = index;
        int l = left(index);
        if (l < qCount) {
            //check if left is larger
            if (values[l] > values[larger]) {
                larger = l;
            }
            int r = right(index);
            if (r < qCount) {
                //check if right is larger
                if (values[r] > values[larger]) {
                    larger = r;
                }
            }
        }
        //swap if needed
        if (index != larger) {
            swap(index,larger);
            heapify(larger);
        }
    }
}

//******************************************************************************
//Public Members
//******************************************************************************
//Enques value into iPQ; returns true for success; false if full
//Written by Parker

bool iPQ::enq(int v) {
    bool rc = false;
    if(qCount < qCapacity){
        values[qCount] = v;
        qCount++;
        bubbleUp(qCount);
        rc = true;
    }
    return rc;
}

//******************************************************************************
//returns true if IPQ is not empty; removes & returns max value, false if empty
//Written by Parker

bool iPQ::deq(int &v) {
    bool rc = qCount > 0;
    if (rc){
        v = values[0];
        qCount--;
        values[0] = values[qCount];
        heapify(0);
    }
    return rc;
}

//******************************************************************************
//Function for printing the array 
//Written by Zach

void iPQ::printIt() const{
    printIt(0,0);
}

//******************************************************************************
//Function for clearing the contents of the array
//Written by Zach

void iPQ::clear() {
    qCount = 0;
}

//******************************************************************************
//Function for returning the size of the array
//Written by Zach

int iPQ::count() const{
    return qCount;
}