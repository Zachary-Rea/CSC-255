/*
Filename: p1.h
Author(s): Zachary Rea and Parker Ross
Date: 22 January 2023
Description: The header file for p1
*/
class stringList {
private:
    string *a;
    int listCapacity;
    int listSize;
public:
    stringList (int listCapacity = 100);//Zach
    ~stringList ();//Zach
    bool insert (string text); //parker
    bool add (string text); //parker 
    bool insertAt (int index,string text); //parker
    bool deleteAt (int index,string text);
    void clear();//Zach
    void printIt() const;//Zach
    int getIndex(string text) const;
    int readAt(int index, string text) const; //parker
    int count() const;//Zach
};