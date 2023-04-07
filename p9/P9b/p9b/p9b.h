/*
Filename: p9b.h
Author(s): Zachary Rea and Parker Ross
Date: 4 April 2023
Description: The header file for p9
*/
#ifndef __P9_H
#define __P9_H
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
        //Functions
        int ind(int x, int y) const;
        int labelToVid(int label) const;
        int vidToLabel(int vid) const;
    public:
        //functions
        Graph(int n = 100, bool directed = true);
        ~Graph();
        bool createV(int label);
        bool addEdge(int uLabel, int vLabel, int weight);
        bool deleteEdge(int uLabel, int vLabel);
        void clear();
        bool isEdge(int uLabel, int vLabel) const;
        bool isV(int Label) const;
        int inDegree(int label) const;
        int outDegree(int label) const;
        int sizeV() const;
        int sizeUsedV() const;
        int sizeE() const;
        void printIt() const;
        void bfPrint(int label) const;
        bool isPath(int ulabel, int vlabel) const;
        void printPaths() const;
};
#endif