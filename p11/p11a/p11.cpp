/*
Filename: p11.cpp
Author(s): Zachary Rea and Parker Ross
Date:20 April 2023
Description: The cpp for p11
*/
#include "P11.h"
#include <iostream>
#include <iomanip>

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
    lambda = new int[n];
    set = new int[n];
    clear();
}
//******************************************************************************
//Destructor
//Written by Zach modified by Parker
Graph::~Graph() {
    delete[] a;
    delete labels;
    delete q;
}
//******************************************************************************
//Private Functions
//******************************************************************************
//Function to return the mapping of x,y
//Written by Zach
int Graph::ind(int x, int y) const{
    int rc = 0;
    if (directed) {
        rc = x * n + y;
    } else {
        rc = x<y?x*n+y:y*n+x;
    }
    return rc;
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
//Function to populate lambda with the distances to all other nodes
//Written by Parker and Zach, modified by Parker
void Graph::dijkstra(int s) {
        for (int i = 0; i < vCount; i++) {
            lambda[i] = INFINITE;
            set[i] = Y;
        }
        lambda[s] = 0;
        set[s] = X;
        for (int i = 0; i < vCount; i++) {
            int key = vidToLabel(s);
            if (isEdge(vidToLabel(s),key)) {
                lambda[i] = a[ind(s,labelToVid(key))];
            }
        }
        lambda[s] != 0;
        int minV;
        while(minLambdaY(minV)) {
            set[minV] = X;
            for (int i = 0; i < vCount; i++) {
                int key  = vidToLabel(s);
                if (isEdge(vidToLabel(minV),key)) {
                    lambda[i] = min(a[ind(minV,i)]+lambda[minV],lambda[i]);
                }
            }
        }
    
}
//******************************************************************************
//Function to return the minimum value of Y in lambda
//Written by Zach modified by Parker
bool Graph::minLambdaY(int &minV) {
    bool rc = false;
    minV = -1;
    int minVal = INFINITE;
        for (int i = 0; i < vCount; i++) {
            if ((set[i] == Y) && (lambda[i] <= minVal)) {
                minV = i;
                minVal = lambda[i];
                rc = true;
            }
        }
    return rc;
}
//******************************************************************************
//Function to check if directed graph is cyclic
//Written by Zach
bool Graph::isCyclicDirected() {
    bool rc = false;
    for (int i = 1; i < vCount; i++) {
        if (isPath(vidToLabel(i),vidToLabel(i))) {
            rc = true;
        }
    }
    return rc;
}
//******************************************************************************
//Function to check if undirected graph is cyclic
//Written by Zach
bool Graph::isCyclicUndirected() {
    bool rc = false;
    for (int i = 1; i < vCount; i++) {
        if (isPath(vidToLabel(i),vidToLabel(i))) {
            rc = true;
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
bool Graph::deleteEdge(int uLabel, int vLabel, int &weight) {
    bool rc = false;
    bool checkw = isEdge(uLabel,vLabel);
    if (checkw) {
        weight = a[ind(labelToVid(uLabel),labelToVid(vLabel))];
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
//Written by Zach
int Graph::inDegree(int label) const{
    int inDeg = labelToVid(label);
    int rc = -1;
    if ((inDeg >= 0) && (directed)) {
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
    if ((outDeg >= 0) && (directed)) {
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
void Graph::printIt() {
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
        if (c > r) {
            cout << "  " << a[ind(r,c)];
        } else {
            cout << "  0";
        }
	}
	cout << endl;
    }

    cout << "Degree table (normal, in, out)\n";

    for (r = 0; r < vCount; r++) {
        int key;
        labels->readAt(r,key);
	cout << "  Node(" << r << "," << key << "):";
	cout << "     " << degree(key) << ", " << inDegree(key) << ", " << outDegree(key) << endl;
    }
}
//******************************************************************************
//Function to do a breadth first print
//Written by Zach modified by Parker 
void Graph::bfPrint(int label) const {
    iQ *q = new iQ(vCount);
    bool *mark = new bool [vCount];
    for (int i = 0; i < vCount; i++) {
        mark[i] = false;
    }
            int vid = labelToVid(label);
            q->enq(vid);
            int j = 0;
            int current;
            while (q->count() > 0) {
                q->deq(current);
                int lab = vidToLabel(current);
                cout << "\t\t\t Item " << j << " is (" << current << "," << 
                lab << ")\n";
                j++;
                for (int i = 0; i < vCount; i++) {
                    if (isEdge((lab), vidToLabel(i))) {
                        if (mark[i] == false) {
                            mark[i] = true;
                            q->enq(i);
                        }
                    }
                }
            }
        }
//******************************************************************************
//Function to tell if there is a path between two nodes
//Written by Zach modified by Parker
bool Graph::isPath(int ulabel, int vlabel) const{
    iQ *q = new iQ(vCount);
    bool rc = false;
    if (directed) {
        if ((isEdge(ulabel,vlabel)) && (ulabel == vlabel)) {
            rc = true;
        }
    }
    bool check1 = isV(ulabel);
    bool check2 = isV(vlabel);
    if ((check1 && check2) && (ulabel != vlabel)) {
        int vid = labelToVid(ulabel);
        bool *mark = new bool [vCount];
        for (int i = 0; i < vCount; i++) {
            mark[i] = false;
        }
        q->enq(vid);
        mark[vid] = true;
        int current;
        while (q->count() > 0) {
            q->deq(current);
            if (vidToLabel(current) == vlabel) {
                rc = true;
                break;
            }
            for (int i = 0; i < vCount; i++) {
                int lab = vidToLabel(current);
                if (isEdge(lab, vidToLabel(i))) {
                    if (mark[i] == false) {
                        mark[i] = true;
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
    for (int i = 0; i < vCount; i++) {
        for (int j = 0; j < vCount; j++) {
            if (isPath(vidToLabel(i), vidToLabel(j))) {
                int key = vidToLabel(i);
                cout << key << " does have a path to ";
                key = vidToLabel(j);
                cout << key << endl;
            } else {
                int key = vidToLabel(i);
                cout << key << " does not have a path to ";
                key = vidToLabel(j);
                cout << key << endl;
            }
        }
    }
}
//******************************************************************************
//Function to return the distance between two nodes
//Written by Zach
bool Graph::dijkstra(int sLabel, int dLabel, int &distance) {
    bool rc = false;
    distance = -1;
    if ((isV(sLabel) && isV(dLabel))) {
        dijkstra(labelToVid(sLabel));
        distance = lambda[(labelToVid(dLabel))];
        rc = true;
    }
    return rc;
}
//******************************************************************************
//Function to return the degree of a vertex in undirected graph
//Written by Zach
int Graph::degree(int label) {
    int rc = -1;
    if ((!directed) && (isV(label))) {
        rc = 0;
        for (int i = 0; i < vCount; i++) {
            if ((i != labelToVid(label)) && (isEdge(label,vidToLabel(i)))) {
                rc++;
            }
        }
    }
    return rc;
}
//******************************************************************************
//Function to call the cyclic checkers respectively
//Written by Zach
bool Graph::isCyclic() {
    return (directed?isCyclicDirected():isCyclicUndirected());
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