/*
Filename: p9.cpp
Author(s): Zachary Rea and Parker Ross
Date: March 26 2023
Description: The cpp for p9
*/
#include "P9.h"
#include <iostream>

using namespace std;

//******************************************************************************
//Public Methods
//******************************************************************************
Graph(int n =100, bool directed = true)
//sets up the empty graph
//Allocates “a”, an n*n sized array, and labels, an n-sized array.  
//Sets all values of a to zero.  Allocates the labels intList.  
//Sets vCount and eCount to 0. And more.

~Graph(); // deletes the array “a”


//******************************************************************************
bool createV(int label);
//creates the node labeled by the parameter; 
//returns true if label not already used and there is a label table entry left to be allocated to the label; 
//returns false otherwise.  I.e., this requires vCount < n to allocate a node to a label.

//If all went well, then labels[latestIndex] gets set to “label”, where latestIndex is the new vCount - 1.


//******************************************************************************
bool deleteEdge(int uLabel, int vLabel); 
//deletes the edge, if the edge had been set and decrements eCount;
//returns true if it deletes it; 
//returns false if the edge was already deleted; returns false if the labels didn’t match existing nodes.


//******************************************************************************
void clear(); 
//causes the graph to be reset to its original state, with no vertices or edges


//******************************************************************************
bool isEdge (int uLabel, int vLabel) const;
//returns true if the edge exists;
//returns false if the node labels are not both assigned to a node or if the edge does not exist (weight == 0).

//******************************************************************************
bool isV(int label) const; 
//return true if there is a node labeled by label


//******************************************************************************
int inDegree(int label) const; 
//return inD of the node; -1 if the node does not existint outDegree(int label) const 
//return outD of the node; -1 if the node does not exist


//******************************************************************************
int sizeV() const; 
//returns the largest size the graph could be (n).


//******************************************************************************
int sizeUsedV() const; 
//returns the number of nodes actually used, vCount


//******************************************************************************
int sizeE() const; 
//returns the number of edges in the graph, eCount


//******************************************************************************
printIt() const; 
// prints the graph; see sample output for proper format

//******************************************************************************
//Private Methods
//******************************************************************************
int ind(int x, int y) const; 
//returns the mapping of x,y to index; uses least vertex id first for undirected graphs



//******************************************************************************
int labelToVid(int label) const; 
//returns the vertex index for the given label
//returns -1 if no node has that label


//******************************************************************************
//Private Variables
//******************************************************************************
int *a; // the array for the graph; size will be n*n
intList *labels; // stores the labels of the edge; size will be n
int n; // memorializes the dimensions of the graph matrix
int vCount; // tracks the number of nodes in the graph
int eCount; // tracks the number of edges in the graph
bool directed; // remembers whether the graph is directed or not

