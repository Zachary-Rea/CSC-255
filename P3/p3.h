/*
Filename: p3.h
Author(s): Zachary Rea and Parker Ross
Date: 5 February 2023
Description: The header file for p3
*/
#ifndef __P1_H
#define __P1_H

#include <string>
//******************************************************************************
class cStringList {
    private:
        std::string *a;
        int listCapacity;
        int listCount;
        int first;
        int last;\
        void incVal(int &value);
        void decVal(int &value);
    public:
        cStringList(int capacity = 100);
        ~cStringList();
        bool insert(std::string text);
        bool add(std::string text);
        bool insertAt(int index, std::string text);
        bool deleteAt(int index, std::string &text);
        bool readAt(int index, std::string &text);
        bool deleteFirst(std::string &text);
        bool deletelast(std::string &text);
        void clear();
        int count() const;
        int getIndex(std::string text);
};
#endif