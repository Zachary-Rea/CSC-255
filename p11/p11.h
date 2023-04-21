/*
Filename: p11.h
Author(s): Zachary Rea and Parker Ross
Date: 19 April 2023
Description: The header file for p11
*/
#ifndef __P11_H 
#define __P11_H
#include "p1.h"
#include "iq.h"

//******************************************************************************
class Graph {
    private:
        //Variables
        int *a;
        intList *labels;
        iQ *q;
        int n;
        int vCount;
        int eCount;
        bool directed;
        int *lambda;
        int *set;
        int const INFINITE = 1000000;
        int const X = 0;
        int const Y = 1;
        //Functions
        int ind(int x, int y) const;
        int labelToVid(int label) const;
        int vidToLabel(int vid) const;
        void dijkstra(int s);
        bool minLambdaY(int &minV);
        //New for P11
        bool isCyclicDirected();
        bool isCyclicUndirected();
    public:
        //Functions
        Graph(int n = 100, bool directed = true);
        ~Graph();
        bool createV(int label);
        bool addEdge(int uLabel, int vLabel, int weight);
        bool deleteEdge(int uLabel, int vLabel, int &weight);
        void clear();
        bool isEdge(int uLabel, int vLabel) const;
        bool isV(int Label) const;
        int inDegree(int label) const;
        int outDegree(int label) const;
        int sizeV() const;
        int sizeUsedV() const;
        int sizeE() const;
        void printIt();
        void bfPrint(int label) const;
        bool isPath(int ulabel, int vlabel) const;
        void printPaths() const;
        bool dijkstra(int sLabel, int dLabel, int &distance);
        //New for P11
        int degree(int label);
        bool isCyclic();
};
#endif