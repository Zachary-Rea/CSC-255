/*
Author: Zachary Rea
Professor Wheat
January 21st 2023
Program 1
*/
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class stringList {
private:
    string *a;
    int count;
    int listCapacity;
    int listSize;
public:
    stringList (int listCapacity = 100);
    ~stringList ();
    bool insert (string text);
    bool add (string text);
    bool insertAt (int index,string text);
    void clear();
    void printIt() const;
    int readAt(int index) const;
    int count() const;
};