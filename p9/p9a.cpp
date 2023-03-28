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
//Written by Zach
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
//Written by Zach
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
//Written by Parker
void Graph::clear() {
//causes the graph to be reset to its original state, with no vertices or edges
int ecount = 0;
int vcount = 0;
    for (int i = 0; i < n*n ; i++){
        a [i] = 0;
    }
    labels->clear ();
}
//******************************************************************************
//Function to check if there is an edge between two vertices
//Written by Parker
bool Graph::isEdge(int uLabel, int vLabel) const{
    bool rc = false;
    int uVid = labelToVid(uLabel);
    int vVid = labelToVid(vLabel);
    if ((uVid & vVid >=0)){
        if (a[ind(uVid,vVid)] != 0){ //???
            rc = true;
        }
    }  
    return rc;
}
//******************************************************************************
//Function to check if there is a vertex at a given location
//Written by 
bool Graph::isV(int label) const{
    return false;
}
//******************************************************************************
//Function to return the in degree of a given label
//Written by Parker
int Graph::inDegree(int label) const{
    int inD = 0;
    int vVid = labelToVid(label); //??
    for(int i = 0; i <vCount; i++){
        if (a[ind(i, vVid)] != 0){ //??
            inD++;
        }
    }
    if (!inD){
        inD = -1;
    }
    return inD;
}
//******************************************************************************
//Function to return the out degree of a given label
//Written by Parker
int Graph::outDegree(int label) const{
    int outD = 0;
    int uVid = labelToVid(label); //??
    for (int i = 0; i < n; i++){ 
        if (a[ind(uVid, i)] != 0){  //??
            outD++;
        }
         }
    if (!outD){
        outD = -1;
    }
    return outD;
}
   
//******************************************************************************
//Function to return the number of vertices possible
//Written by Parker
int Graph::sizeV() const{
    return n;
}
//******************************************************************************
//Function to return the number of vertices
//Written by Parker
int Graph::sizeUsedV() const{
    return vCount;
}
//******************************************************************************
//Function to return the number of edges
//Written by Parker
int Graph::sizeE() const{
    return eCount;
}
//******************************************************************************
//Function to print the contents of the graph 
//Written by Zach
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
//Written by Zach
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
//Written by Zach
int max(int x, int y) {
    int rc = 0;
    if (x > y) {
        rc = x;
    } else {
        rc = y;
    }
    return rc;
}