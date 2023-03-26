/*
Filename: p9.h
Author(s): Zachary Rea and Parker Ross
Date: 26 March 2023
Description: The header file for p9
*/
#ifndef __P9_H
#define __P9_H

//******************************************************************************
class intList {
private:
    int *a;
    int listCapacity;
    int listSize;
public:
    //Constructors and Destructors
    intList (int listCapacity = 100);//Zach
    ~intList ();//Zach
    //Public Functions 
    bool insert (int key); //parker
    bool add (int key); //parker 
    bool insertAt (int index,int key); //parker
    bool deleteAt (int index,int &key);
    void clear();//Zach
    void printIt(int n) const;//Zach
    int getIndex(int key) const;
    int readAt(int index, int &key) const; //parker
    int capacity() const;//Zach
};
class Graph {
    private:
        //Variables
        int *a;
        intList *labels;
        int n;
        int vCount;
        int eCount;
        bool directed;
        //Functions
        int ind(int x, int y) const;
        int labelToVid(int label) const;
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
};
#endif