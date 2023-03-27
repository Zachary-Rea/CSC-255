/*
Filename: p9.cpp
Author(s): Zachary Rea and Parker Ross
Date: March 26 2023
Description: The cpp for p9
*/
#include "P1.h"
#include "P9a.h"
#include <iostream>

using namespace std;

//Graph class
//******************************************************************************
//Constructors and Destructors
//******************************************************************************
//Constructor 
//Written by Zach
Graph::Graph(int n, bool directed) {
    this->n = n;
    this->directed = directed;
    labels = new intList(n);
    a = new int[n*n];
    clear();
}
//******************************************************************************
//Destructor
//Written by Zach
Graph::~Graph() {
    delete[] a;
}
//******************************************************************************
//Private Functions
//******************************************************************************
//Function to return the mapping of x,y
//Written by Zach
int Graph::ind(int x, int y) const{
    return x * n + y;
}
//******************************************************************************
//Function to return the vertex id of a given label
//Written by 
int Graph::labelToVid(int label) const{
    int rc = -1;
    bool check = isV(label);
    if (check) {
        for (int i = 0; i < vCount; i++) {
            int key;
            labels->readAt(i, key);
            if (key == label) {
                rc = i;
            }
        }
    }
    return rc;
}
//******************************************************************************
//Public Functions
//******************************************************************************
//Function to create a vertex
//Written by Zach
bool Graph::createV(int label) {
    bool rc = false;
    bool check = isV(label);
    if ((vCount < n) && (!check)) {
        labels->add(label);
        vCount++;
    }
    return rc;
}
//******************************************************************************
//Function to add an edge between two vertices
//Written by Zach
bool Graph::addEdge(int uLabel, int vLabel, int weight) {
    bool rc = false;
    bool checku = isV(uLabel);
    bool checkv = isV(vLabel);
    bool checkw = isEdge(uLabel,vLabel);
    if ((!checkw) && (weight > 0)) {
        bool createu = true;
        bool createv = true;
        if (!checku) {
            createu = createV(uLabel);
        }
        if (!checkv) {
            createv =  createV(vLabel);
        }
        if ((createu) && (createv)) {
            a[ind(labelToVid(uLabel),labelToVid(vLabel))] = weight;
            eCount++;
            rc = true;
        }
    }
    return rc;
}
//******************************************************************************
//Function to delete an edge between two vertices
//Written by 
bool Graph::deleteEdge(int uLabel, int vLabel) {
    bool rc = false;
    bool checkw = isEdge(uLabel,vLabel);
    if (checkw) {
        a[ind(labelToVid(uLabel),labelToVid(vLabel))] = 0;
        eCount--;
        rc = true;
    }
    return rc;
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
    return false;
}
//******************************************************************************
//Function to check if there is a vertex at a given location
//Written by 
bool Graph::isV(int label) const{
    return false;
}
//******************************************************************************
//Function to return the in degree of a given label
//Written by
int Graph::inDegree(int label) const{
    return 0;
}
//******************************************************************************
//Function to return the out degree of a given label
//Written by 
int Graph::outDegree(int label) const{
    return 0;
}
//******************************************************************************
//Function to return the number of vertices possible
//Written by 
int Graph::sizeV() const{
    return 0;
}
//******************************************************************************
//Function to return the number of vertices
//Written by 
int Graph::sizeUsedV() const{
    return 0;
}
//******************************************************************************
//Function to return the number of edges
//Written by 
int Graph::sizeE() const{
    return 0;
}
//******************************************************************************
//Function to print the contents of the graph 
//Written by 
void Graph::printIt() const{
    int r, c;

    cout << "Graph info:\n";
    cout << "  Graph size = " << n << endl;
    cout << "  vCount = " << vCount << endl;
    cout << "  eCount = " << eCount << endl;
    cout << "\nGraph contents:\n";
    for (r = 0; r < vCount; r++) {
	cout << "  Node(" << r << "," << a[r] << "):";
	for (c = 0; c < vCount; c++) {
	    cout << " " << a[ind(r,c)];
	}
	cout << endl;
    }

    cout << "Degree table (in, out)\n";

    for (r = 0; r < vCount; r++) {
	cout << "  Node(" << r << "," << a[r] << "):";
	cout << " " << inDegree(a[r]) << ", " << outDegree(a[r]) << endl;
    }
}
//******************************************************************************
//Non-Member Functions
//******************************************************************************
//Function to return the min of two values
//Written by 
int min(int x, int y) {
    int rc = 0;
    if (x < y) {
        rc = x;
    } else {
        rc = y;
    }
    return rc;
}
//******************************************************************************
//Function to return the max of two values
//Written by 
int max(int x, int y) {
    int rc = 0;
    if (x > y) {
        rc = x;
    } else {
        rc = y;
    }
    return rc;
}