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
    int listsize;
public:
    stringList (int listCapacity = 100);
    ~stringList ();
    bool insert (string text); //parker
    bool add (string text); //parker 
    bool insertAt (int index,string text); //parker
    void clear();
    void printIt() const;
    int readAt(int index) const; //parker
    int count() const;
};