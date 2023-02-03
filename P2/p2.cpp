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
stringLinkedList::stringLinkedList() {
    first = last = NULL;
    listCount = 0;
}
//******************************************************************************
//Constructor
node::node(string text, node *pn) {
    this->text = text;
    this->next = pn;
}
//******************************************************************************
//Deconstructor
stringLinkedList::~stringLinkedList() {
    clear(first);
}
//******************************************************************************
//Private functions
//******************************************************************************
//Function for help with recursion 
int stringLinkedList::getIndex(string text,node *pn, int &index) const{
    string search;
    if ((listCount) && (index < listCount) - 1) {
        search = pn->text;
        if (search != text) {
            pn = pn->next;
            index++;
            getIndex (text, pn, index);
        }
    }
    if (index == listCount - 1) {
        index = -1;
    }
    return index;
}
//******************************************************************************
//Function for help with recursion
void stringLinkedList::printIt(node *pn, int index) const{
    if ((listCount) && (index < listCount)) {
        string text = pn->text;
        cout << "At pos " << index << " there is " << text << "\n";
        index++;
        pn = pn->next;
        if (pn) {
            printIt(pn, index);
        }
    }
}
//******************************************************************************
//Function for help with recursion
void stringLinkedList::clear(node *pn) {
    if (listCount > 1) {
        node *f = pn->next;
        delete pn;
        listCount--;
        clear (f);
    } else if (listCount == 1) {
        delete pn;
        listCount--;
    }
}
//******************************************************************************
//Public functions
//******************************************************************************
//Modifiers
//******************************************************************************
//Function for inserting a string at the front of the list
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
            node *p = new node(text,p->next);
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
bool stringLinkedList::deleteAt(int index, string &text) {
    bool rc = false;
    if ((index >= 0) && (index < listCount) && (listCount)) {
        node *f = first;
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
bool stringLinkedList::readAt(int index, string &text) {
    bool rc = false;
    if ((listCount) && (index < listCount) && (index > 0)) {
        node *f = first;
        int ind;
        ind = 0;
        f = first;
        ind = 0;
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
int stringLinkedList::getIndex(string text) const{
    int index;
    getIndex (text, first, index);
    return index;
}
//******************************************************************************
//Function for printing the contents of the list 
void stringLinkedList::printIt() const{
    printIt(first,0);
}
//******************************************************************************
//Function for returning the current size of the list 
int stringLinkedList::count() const{
    return listCount;
}