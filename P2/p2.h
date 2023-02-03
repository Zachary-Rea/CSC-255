/*
Filename: p2.h
Author(s): Zachary Rea and Parker Ross
Date: 27 January 2023
Description: The header file for p2
*/
#ifndef __P2_H
#define __P2_H

#include <string>
//******************************************************************************
class stringLinkedList;
class node {
    private:
        std::string text;
        node *next;
        //Private constructor for the node
        node(std::string text = "", node *pn = NULL);
        friend stringLinkedList;
};
class stringLinkedList {
    private:
        node *first, *last;
        int listCount;
        //Function to help with recursion
        int getIndex(std::string text,node *pn, int &index) const;
        //Function to help with recursion
        void printIt(node *pn,int index) const;
        //Function to help with recursion
        void clear(node *pn);
    public:
        //Constructors and De-constructors
        //Constructor for stringLinkedList
        stringLinkedList();
        //De-constructor for stringLinkedList
        ~stringLinkedList();
        //Modifiers
        //Function to insert a string node at the beginning of the list
        bool insert(std::string text);
        //Function for adding a string node to the end of the list
        bool add(std::string text);
        //Function for inserting a string node at a given index
        bool insertAt(int index,std::string text);
        //Function for deleting a node at a given index
        bool deleteAt (int index,std::string &text);
        //Function for reading the contents of a given node
        bool readAt (int index,std::string &text);
        //Function for emptying the contents of the list 
        void clear ();
        //Non-modifiers
        //Function to return the first index of a given string
        int getIndex (std::string text) const;
        //Function to print the full contents of the list
        void printIt () const;
        //Function to return the current size of the list 
        int count () const;
};
#endif