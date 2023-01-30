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
        node(std::string text = "", node *pn = NULL);//Private constructor for the node
        friend stringLinkedList;
};
class stringLinkedList {
    private:
        node *first, *last;
        int listCount;
        int getIndex(std::string text,node *pn, int index) const;//Function to help with recursion
        void printIt(node *pn,int index) const;//Function to help with recursion
        void clear(node *pn);//Function to help with recursion
    public:
        //Constructors and De-constructors
        stringLinkedList();//Constructor for stringLinkedList
        ~stringLinkedList();//De-constructor for stringLinkedList
        //Modifiers
        bool insert(std::string text);//Function to insert a string node at the beginning of the list
        bool add(std::string text);//Function for adding a string node to the end of the list
        bool insertAt(int index,std::string text);//Function for inserting a string node at a given index
        bool deleteAt (int index,std::string &text);//Function for deleting a node at a given index
        bool readAt (int index,std::string &text);//Function for reading the contents of a given node
        void clear ();//Function for emptying the contents of the list 
        //Non-modifiers
        int getIndex (std::string text) const;//Function to return the first index of a given string
        void printIt () const;//Function to print the full contents of the list
        int count () const;//Function to return the current size of the list 
};
#endif