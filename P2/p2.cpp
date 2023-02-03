/*
Filename: p2.cpp
Author(s): Zachary Rea and Parker Ross
Date: 27 January 2023
Description: 
*/
#include <iostream>  //allows for usage of cin, cout, and cerr

#include "p2.h"

using namespace std;

//******************************************************************************
//Constructors and de-constructors
//******************************************************************************
//Constructor
//Written by Zach

stringLinkedList::stringLinkedList() {
    first = last = NULL;
    listCount = 0;
}

//******************************************************************************
//Constructor
//Written by Parker

node::node(string text, node *pn) {
    this->text = text;
    this->next = pn;
}

//******************************************************************************
//Deconstructor
//Written by Zach

stringLinkedList::~stringLinkedList() {
    clear(first);
}

//******************************************************************************
//Private functions
//******************************************************************************
//Function for help with recursion 
//Written by Zach

int stringLinkedList::getIndex(string text,node *pn, int &index) const{
    if (pn) {
        string search;
        search = pn->text;
        if (search != text) {
            index++;
            getIndex(text,pn->next,index);
        }
    } else {
        index = -1;
    }
    return index;
}

//******************************************************************************
//Function for help with recursion
//Written by Parker

void stringLinkedList::printIt(node *pn, int index) const{
    if (pn) {
        string text = pn->text;
        cout << "At pos " << index << " there is " <<  text << "\n";
        printIt(pn->next,++index);
    }
}

//******************************************************************************
//Function for help with recursion
//Written by Parker

void stringLinkedList::clear(node *pn) {
    if (pn) {
        clear (pn->next);
        delete pn;
    }
}

//******************************************************************************
//Public functions
//******************************************************************************
//Modifiers
//******************************************************************************
//Function for inserting a string at the front of the list
//Written by Zach

bool stringLinkedList::insert(string text) {
    node *p = new node(text,first);
    first = p;
    if (!listCount) {
        last = p;
    }
    listCount++;
    return true;
}

//******************************************************************************
//Function for adding a string to last position of the list
//Written by Parker

bool stringLinkedList::add(string text) {
    node *p = new node(text);
    if (last) {
        last->next = p;
    } else {
        first = p;
    }
    last = p;
    listCount++;
    return true;
}

//******************************************************************************
//Function for inserting a string at a given position on the list
//Written by Zach

bool stringLinkedList::insertAt(int index, string text) {
    bool rc = false;
    if ((index <= listCount) && (index >= 0)) {
        node *f = first;
        if (index == 0) {
            node *p = new node (text,first);
            first = p;
            if (!listCount) {
                last = p;
            }
        } else if (index <= listCount) {
            int ind;
            ind = 0;
            while (ind < index - 1) {
                f = f->next;
                ind++;
            }
            node *p = new node(text,f->next);
            f->next = p;
        } else {
            node *p = new node (text);
            last->next = p;
            last = p;
        }
        listCount++;
        rc = true;
    }
    return rc;
}

//******************************************************************************
//Function for deleting a node at a given index 
//Written by Zach

bool stringLinkedList::deleteAt(int index, string &text) {
    bool rc = false;
    if ((index >= 0) && (index < listCount) && (listCount)) {
        node *f;
        if (index == 0) { 
            f = first;
            if (listCount == 1) {
                first = last = NULL;
            } else {
                first = f->next;
            }
        } else if (index < listCount - 1) {
            int ind;
            f = first;
            ind = 0;
            while (ind < index) {
                f = f->next;
                ind++;
            }
            node *p = first;
            ind = 0;
            while (ind < index - 1) {
                p = p->next;
                ind++;
            }
            p->next = f->next;
        } else {
            int ind;
            f = last;
            node *p = first;
            ind = 0;
            while (ind < index - 1) {
                p = p->next;
                ind++;
            }
            last = p;
            last->next = NULL;
        }
        text = f->text;
        delete f;
        listCount--;
        rc = true;
    }
    return rc;
}

//******************************************************************************
//Function for reading a string at a given index
//Written by Zach

bool stringLinkedList::readAt(int index, string &text) {
    bool rc = false;
    if ((listCount) && (index < listCount) && (index > 0)) {
        node *f;
        int ind;
        ind = 0;
        f = first;
        while (index > ind) {
            f = f->next;
            ind++;
        }
        text = f->text;
        rc = true;
    }
    return rc;
}

//******************************************************************************
//Function for removing all members of the list 
// Written by Parker

void stringLinkedList::clear() {
    clear (first);
    last = NULL;
    first = NULL;
    listCount = 0;
}

//******************************************************************************
//Non-modifiers
//******************************************************************************
//Function for returning the index of a given string
//Written by Zach

int stringLinkedList::getIndex(string text) const{
    int index = 0;
    getIndex (text, first, index);
    return index;
}

//******************************************************************************
//Function for printing the contents of the list 
//Written by Parker

void stringLinkedList::printIt() const{
    printIt(first,0);
}

//******************************************************************************
//Function for returning the current size of the list 
// Writen by Parker

int stringLinkedList::count() const{
    return listCount;
}