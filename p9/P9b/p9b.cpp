/*
Filename: p9.cpp
Author(s): Zachary Rea and Parker Ross
Date: March 26 2023
Description: The cpp for p9
*/
#include "P1.h"
#include "P9b.h"
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
    iQ *q = new iQ(vCount);
    clear();
}
//******************************************************************************
//Destructor
//Written by Zach modified by Parker
Graph::~Graph() {
    delete[] a;
    delete labels;
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
//Written by Zach modified by Parker
int Graph::labelToVid(int label) const{
    int rc = -1;
    if (isV(label)) {
        rc = labels->getIndex(label);
    }
    return rc;
}
//******************************************************************************
//Function to return the label of a given vid
//Written by Zach
int Graph::vidToLabel(int vid) const{
    int rc = -1;
    labels->readAt(vid, rc);
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
        rc = true;
    }
    return rc;
}
//******************************************************************************
//Function to add an edge between two vertices
//Written by Zach modified by Parker
bool Graph::addEdge(int uLabel, int vLabel, int weight) {
    bool rc = false;
    bool checku = isV(uLabel);
    bool checkv = isV(vLabel);
    bool checkw = isEdge(uLabel,vLabel);
    if ((!checkw) && (weight > 0)) {
        bool createu = false;
        bool createv = false;
        if (!checku) {
            createu = createV(uLabel);
        } else {
            createu = true; 
        }
        if (!checkv) {
            createv =  createV(vLabel);
        } else {
            createv = true; 
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
    if ((uVid >= 0) && (vVid >= 0)){
        rc = a[ind(uVid,vVid)] > 0;
    }  
    return rc;
}
//******************************************************************************
//Function to check if there is a vertex at a given location
//Written by Zach modified by Parker 
bool Graph::isV(int label) const {
    return (labels->getIndex(label) != -1);
}
//******************************************************************************
//Function to return the in degree of a given label
//Written by Parker
int Graph::inDegree(int label) const{
    int inDeg = labelToVid(label);
    int rc = -1;
    if (inDeg >= 0) {
        rc = 0;
        for (int i = 0; i < vCount; i++) {
            if (a[ind(i, inDeg)]) {
                rc++;
            }
        }
    }
    return rc;
}
//******************************************************************************
//Function to return the out degree of a given label
//Written by Parker
int Graph::outDegree(int label) const{
    int outDeg = labelToVid(label);
    int rc = -1;
    if (outDeg >= 0) {
        rc = 0;
        for (int i = 0; i < vCount; i++) {
            if (a[ind(outDeg, i)]) {
                rc++;
            }
        }
    }
    return rc;
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
        int key;
        labels->readAt(r,key);
	cout << "  Node(" << r << "," << key << "):";
	for (c = 0; c < vCount; c++) {
	    cout << " " << a[ind(r,c)];
	}
	cout << endl;
    }

    cout << "Degree table (in, out)\n";

    for (r = 0; r < vCount; r++) {
        int key;
        labels->readAt(r,key);
	cout << "  Node(" << r << "," << key << "):";
	cout << " " << inDegree(key) << ", " << outDegree(key) << endl;
    }
}
//******************************************************************************
//Function to do a breadth first print
//Written by Zach
void Graph::bfPrint(int label) const {
    q->clear();
    int *traversal = new int[vCount];
    int *mark = new int[vCount];
    for (int i = 0; i < vCount; i++) {
        traversal[i] = 0;
        mark[i] = 0;
    }
    for (int i = 0; i < vCount; i++) {
        if (traversal == 0) {
            int vid = labelToVid(label);
            q->enq(vid);
            int j = 0;
            int current = 0;
            while (q->count() > 0) {
                q->deq(current);
                int lab = vidToLabel(current);
                cout << "Item " << x << " is (" << current << "," << 
                lab << ")\n";
                x++;
                for (int i = 0; i < vCount; i++) {
                    if (isEdge((lab), vidToLabel(i))) {
                        if (mark[i] == 0) {
                            mark[i] = 1;
                            q->enq(i);
                        }
                    }
                }
            }
            for (int j = 0; j < vCount; j++) {
                if (mark[j] == 1) {
                    traversal[j] = 1; 
                }
            }
        }
    }
    q->clear();
}
//******************************************************************************
//Function to tell if there is a path between two nodes
//Written by 
bool Graph::isPath(int ulabel, int vlabel) const{
    q->clear();
    bool rc = false;
    bool check1 = isV(ulabel);
    bool check2 = isV(vlabel);
    if (check1 && check2) {
        int vid = labelToVid(ulabel);
        int *mark = new int[n];
        for (int i = 0; i < n; i++) {
            mark[i] = 0;
        }
        q->enq(vid);
        mark[vid] = 1;
        int x = 0;
        int current = 0;
        while (q->count() > 0) {
            q->deq(current);
            if (vidToLabel(current) == vlabel) {
                rc = true;
                break;
            }
            for (int i = 0; i < n; i++) {
                lab = vidToLabel(current);
                if (isEdge(lab, vidToLabel(i))) {
                    if (mark[i] == 0) {
                        mark[i] = 1;
                        q->enq(i);
                    }
                }
            }
        }
    }
    return rc;
}
//******************************************************************************
//Function to print the paths of the graph
//Written by Parker
void Graph::printPaths() const{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (isPath(vidToLabel[i], vidToLabel[j])) {
                cout << label[i] << " does have a path to " << label[j] << endl;
            } else {
                cout << label[i] << " does not have a path to " << label[j] << endl;
            }
        }
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

