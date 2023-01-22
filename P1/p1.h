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
    int count;
    int capacity;
    String *a;
public:
    stringList (int capacity = 100);
    ~stringList ();
    bool insert (String inStr);
};