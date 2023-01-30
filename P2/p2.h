/*
Filename: p2.h
Author(s): Zachary Rea and Parker Ross
Date: 27 January 2023
Description: The header file for p2
*/
#ifndef __P2_H
#define __P2_H

#include <string>

class stringLinkedList;
class node {
    private:
        std::string text;
        node *next;
        node(std::string text = "",node *next = NULL);
        friend stringLinkedList;
};
class stringLinkedList {
    private:
        node *first, *last;
        int listCount;
        int getIndex(std::string text,node *pn, int index) const;
        void printIt(node *pn,int index) const;
        void clear(node *pn);
    public:
        //Constructors and De-constructors
        stringLinkedList();
        ~stringLinkedList();
        //Modifiers
        bool insert(std::string text);
        bool add(std::string text);
        bool insertAt(int index,std::string text);
        bool deleteAt (int index,std::string &text);
        bool readAt (int index,std::string &text);
        void clear ();
        //Non-modifiers
        int getIndex (std::string text) const;
        void printIt () const;
        int count () const;
};
#endif