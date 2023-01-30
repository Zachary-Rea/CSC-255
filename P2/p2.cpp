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
stringLinkedList::stringLinkedList () {
    first = last = NULL;
    listCount = 0;
}
//******************************************************************************
//Constructor
node::node (string text, node *pn) {
    this -> text = text;
    this -> next = pn;
}
//******************************************************************************
//Deconstructor
stringLinkedList::~stringLinkedList () {
    node *p = first;
    node *f = p -> next;
    while (listCount > 0) {
        delete p;
        listCount--;
        p = f -> next;
        delete f;
        listCount--;
        f = p -> next;
    }
}
//******************************************************************************
//Private functions
//******************************************************************************
//Function for help with recursion 
int stringLinkedList::getIndex (string text,node *pn, int index) const{
    node *p = pn;
    string search;
    index = 0;
    search = p -> text;
    p = p -> next;
    index++;
    while (!(search == text)) {
        getIndex (text, p, index);
    }
    return index;
}
//******************************************************************************
//Function for help with recursion
void stringLinkedList::printIt (node *pn, int index) const{
    node *p = pn;
    string text = p->text;
    cout << "At pos " << index << " there is " << text << "\n";
    index++;
    p = p -> next;
    if (p) {
        printIt(p, index);
    }
}
//******************************************************************************
//Function for help with recursion
void stringLinkedList::clear (node *pn) {
    node *p = pn;
    node *f = p -> next;
    delete p;
    listCount--;
    p = f -> next;
    delete f;
    listCount--;
    while (listCount > 0) {
        clear (p);
    }
}
//******************************************************************************
//Public functions
//******************************************************************************
//Modifiers
//******************************************************************************
//Function for inserting a string at the front of the list
bool stringLinkedList::insert (string text) {
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
bool stringLinkedList::add (string text) {
    node *p = new node(text);
    if (last) {
        last -> next = p;
    } else {
        first = p;
    }
    last = p;
    listCount++;
    return true;
}
//******************************************************************************
//Function for inserting a string at a given position on the list
bool stringLinkedList::insertAt (int index, string text) {
    bool rc;
    node *f = first;
    int ind;
    ind = 0;
    while (f) {
        f = f -> next;
        ind++;
    }
    if ((index > ind) || (index < 0)) {
        rc = false;
    } else {
        if (index = 0) {
            node *p = new node (text,first);
            first = p;
            if (!listCount) {
                last = p;
            }
        } else if ((index > 0) && (index <= ind)) {
            f = first;
            ind = 0;
            while (ind < index - 1) {
                f = f -> next;
                ind++;
            }
            node *p = new node(text,p -> next);
            f -> next = p;
        } else {
            node *p = new node (text);
            last -> next = p;
            last = p;
        }
        listCount++;
        rc = true;
    }
    return rc;
}
//******************************************************************************
//Function for deleting a node at a given index 
bool stringLinkedList::deleteAt (int index, string &text) {
    bool rc;
    node *f = first;
    int ind;
    ind = 0;
    while (f) {
        f = f -> next;
        ind++;
    }
    if ((index > ind) || (!listCount) || (index < 0)) {
        rc = false;
    } else {
        if (index = 0) {
            f = first;
            first = f -> next;
        } else if (listCount = 1) {
            f = first;
            first = last = NULL;
        } else if ((index > 0) && (index <= ind)) {
            f = first;
            ind = 0;
            while (ind < index) {
                f = f -> next;
                ind++;
            }
            node *p = first;
            ind = 0;
            while (ind < index - 1) {
                p = p -> next;
                ind++;
            }
            p -> next = f -> next;
        } else {
            f = last;
            node *p = first;
            ind = 0;
            while (ind < index - 1) {
                p = p -> next;
                ind++;
            }
            last = p;
            last -> next = NULL;
        }
        delete f;
        listCount--;
        rc = true;
    }
    return rc;
}
//******************************************************************************
//Function for reading a string at a given index
bool stringLinkedList::readAt (int index, string &text) {
    bool rc;
    node *f = first;
    int ind;
    ind = 0;
    while (f) {
        f = f -> next;
        ind++;
    }
    if ((index > ind + 1) || (!listCount) || (index < 0)) {
        rc = false;
    } else {
        f = first;
        ind = 0;
        while (index > ind) {
            f = f -> next;
            ind++;
        }
        text = f->text;
        rc = true;
    }
    return rc;
}
//******************************************************************************
//Function for removing all members of the list 
void stringLinkedList::clear () {
    clear (first);
    last = NULL;
    first = NULL;
    listCount = 0;
}
//******************************************************************************
//Non-modifiers
//******************************************************************************
//Function for returning the index of a given string
int stringLinkedList::getIndex (string text) const{
    node *pn = first;
    int index;
    index = -1;
    getIndex (text, pn, index);
    return index;
}
//******************************************************************************
//Function for printing the contents of the list 
void stringLinkedList::printIt () const{
    printIt(first,0);
}
//******************************************************************************
//Function for returning the current size of the list 
int stringLinkedList::count () const{
    return listCount;
}

/*
Professor, we are aware that the program is currently seg faulting on every run, 
but we have been unable to discover the reason that is causing it. I (Zachary)
was going to come in to see you today to talk about it, but the snow day made that
more difficult. I will be coming in to see you the next time that the school is open.
I would have emailed you regarding this issue, but I am unsure of what question to 
ask you regarding this. I have checked the program for writing over NULL pointers 
and made sure that we are keeping track of the size of the object, but it continues 
to fail.
*/