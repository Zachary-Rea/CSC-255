/*
Filename: p9.cpp
Author(s): Zachary Rea and Parker Ross
Date: March 26 2023
Description: The cpp for p9
*/
#include "P9.h"
#include <iostream>

using namespace std;

//intList class
//******************************************************************************
//Constructors and Destructors
//******************************************************************************
//Constructor
//Written by Zach
intList::intList (int listCapacity) {
    this->listCapacity = listCapacity;
    a = new int[listCapacity];
    listSize = 0;
}
//******************************************************************************
//Destructor
//Written by Zach
intList::~intList() {
    delete[] a;
}
//******************************************************************************
//Public Functions 
//******************************************************************************
//Function to insert a value at the start of the list
//Written by Parker modified by Zach
bool intList::insert(int key) {
    bool rc = listCapacity > listSize;
    if (rc) {
        for (int i = listSize; i > 0; i--) {
            a[i] = a[i-1];
        }
        a[0] = key;
        listSize++;
    }
    return rc;
}
//******************************************************************************
//Fucntion to add an int to the end of the list
//Written by Parker modified by Zach
bool intList::add(int key) {
    bool rc;
    if (listSize < listCapacity) { 
        a[listSize] = key;
        listSize++;
        rc = true;
    }
    return rc;
}
//******************************************************************************
//Function to insert a value at a given index of the list
//Written by Parker modified by Zach
bool intList::insertAt(int index, int key) {
    bool rc = listCapacity > listSize && index < listSize && index >= 0; 
    if (rc) {
        for (int i = listSize; i > index; i--) {
            a [i] = a[i-1];
        }
        a[index] = key;
        listSize++; 
    } 
    return rc;
}
//******************************************************************************
//Function to delete a value at a given index of the list
//Written by Parker modified by Zach
bool intList::deleteAt(int index, int &key) {
    bool rc = listSize > index && index >= 0;
        if (rc) {
            key = a[index];
            for (int i = index; i < listSize; i++) {
                a[i] = a[i+1];
            }
        listSize--; 
    }
    return rc;
}
//******************************************************************************
//Function to set the size to 0
//Written and modified by Zach
void intList::clear() {
    listSize = 0;
}
//******************************************************************************
//Function to print n of the list
//Written and modified by Zach
void intList::printIt(int n) const{
    cout << "printIt with list size: " << listSize << " capacity = ";
    cout << listCapacity << "\n";
    if (n < listSize) {
        for (int i = 0; i < n; i++) {
            cout << "At pos " << i << " there is " << a[i] << "\n";
        }
        cout << "At pos " << listSize - 1 << " there is " << a[listSize - 1];
        cout << "\n";
    } else {
        for (int i = 0; i < listSize; i++) {
            cout << "At pos " << i << " there is " << a[i] << "\n";
        }
    }
}
//******************************************************************************
//Function to return the index of a given value
//Written and modified by Zach
int intList::getIndex(int key) const{
    int rc = -1;
    for (int i = 0;i < listSize - 1;i++) {
        if (a[i] == key) {
            rc = i;
            break;
        }
    }
    return rc;
}
//******************************************************************************
//Function to read the value at a given index
//Written by Parker modified by Zach
int intList::readAt(int index, int &key) const{
    int rc = -1;
    if (index < listSize && index >= 0) {
        rc = index;
        key = a[index];
    }
    return rc;
}
//******************************************************************************
//Function to return the current size of the list
//Written and modiefied by Zach
int intList::capacity() const{
    return listCapacity;
}
//******************************************************************************
//Graph class
//******************************************************************************
//Constructors and Destructors
//******************************************************************************
//Constructor 
//Written by 
Graph::Graph(int n, bool directed) {

}
//******************************************************************************
//Destructor
//Written by 
Graph::~Graph() {

}
//******************************************************************************
//Private Functions
//******************************************************************************
//Function to return the mapping of x,y
//Written by 
int Graph::ind(int x, int y) const{

}
//******************************************************************************
//Function to return the vertex index of a given label
//Written by 
int Graph::labelToVid(int label) const{

}
//******************************************************************************
//Public Functions
//******************************************************************************
//Function to create a vertex
//Written by 
bool Graph::createV(int label) {

}
//******************************************************************************
//Function to add an edge between two vertices
//Written by 
bool Graph::addEdge(int uLabel, int vLabel, int weight) {

}
//******************************************************************************
//Function to delete an edge between two vertices
//Written by 
bool Graph::deleteEdge(int uLabel, int vLabel) {

}
//******************************************************************************
//Function to clear the graph 
//Written by 
void Graph::clear() {

}
//******************************************************************************
//Function to check if there is an edge between two vertices
//Written by 
bool Graph::isEdge(int uLabel, int vLabel) const{

}
//******************************************************************************
//Function to check if there is a vertex at a given location
//Written by 
bool Graph::isV(int label) const{

}
//******************************************************************************
//Function to return the in degree of a given label
//Written by
int Graph::inDegree(int label) const{

}
//******************************************************************************
//Function to return the out degree of a given label
//Written by 
int Graph::outDegree(int label) const{

}
//******************************************************************************
//Function to return the number of vertices possible
//Written by 
int Graph::sizeV() const{

}
//******************************************************************************
//Function to return the number of vertices
//Written by 
int Graph::sizeUsedV() const{

}
//******************************************************************************
//Function to return the number of edges
//Written by 
int Graph::sizeE() const{

}
//******************************************************************************
//Function to print the contents of the graph 
//Written by 
void Graph::printIt() const{

}
//******************************************************************************
//Non-Member Functions
//******************************************************************************
//Function to return the min of two values
//Written by 
int min(int x, int y) {

}
//******************************************************************************
//Function to return the max of two values
//Written by 
int max(int x, int y) {

}