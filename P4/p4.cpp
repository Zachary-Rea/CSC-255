/*
Filename: p4.cpp
Author(s): Zachary Rea and Parker Ross
Date: 12 February 2023
Description: The cpp for Binary Search Tree
*/
#include <iostream>  //allows for usage of cin, cout, and cerr

#include "p4.h"

using namespace std;

//******************************************************************************
//Constructors and De-constructors
//******************************************************************************
//Constructor
//Written by Zach edited by Parker

sNode::sNode(string text) {
    this->text = text;
    left = right = NULL;
    h = 0;
}

//******************************************************************************
//Constructor
//Written by Zach 

sBST::sBST() {
    treeCount = 0;
    root = NULL;
}

//******************************************************************************
//De-constructor
//Written by Zach

sBST::~sBST() {
    clear();
}

//******************************************************************************
//Private Functions
//******************************************************************************
//Function to find the minimum value of the subtree
//Written by Parker

string sBST::findMin(sNode *ptr) {
string rc = ptr->text; // storing text in rc
while (ptr->left){ //while a smaller value exists
    ptr = ptr->left;
    }
    return ptr->text;//returns the node with the minimum value
}

//******************************************************************************
//Function for help with recursion
//Written by Zach edited by Parker

bool sBST::insert(sNode *p, string text) {
    bool rc = false;
    if (p) {
        if (text > p->text) {
            rc = insert(p->right, text);
        } else if (text < p->text) {
            rc = insert(p->left, text);
        }
    } else {
        p = new sNode (text);
        if (treeCount == 0) {
            root = p;
        }
        treeCount++;
        rc = true;
    }
    return rc;
}

//******************************************************************************
//Function for help with recursion
//Written by Zach edited by Parker

bool sBST::remove(sNode *p, string text) {
    bool rc = false;
    if (p) {
        if (text == p->text) {
            if (p->right) {
                p->text = findMin(p->right);
                rc = remove(p->right,p->text);
            } else if (p->left) {   
                sNode *t = p;                
                p = p->left;                            
                delete t;      
                treeCount--;
                rc = true; 
            }
            else{
                delete p;
                treeCount--;
            }
        } else if (text < p->text) {
            rc = remove(p->left,text);
        } else if (text > p->text) {
            rc = remove(p->right,text);
        }
    }
    return rc;
}

//******************************************************************************
//Function for help with recursion
//Written by Parker
bool sBST::isIn(sNode *p, string text) const {
    bool rc = false;
    if (p){
        if (text < p->text) {
            isIn(p->left,text);
        } else if (text > p->text) {
            rc = isIn (p-> right,text);
        } else {
        rc = true;
        }
    }
    return rc;
}

//******************************************************************************
//Function for help with recursion
//Written by Parker

void sBST::printIt(sNode *p) const{
    if (p){ //making sure function has a printable node 
    // prints left subtree, root then right subtree for ascending order
        printIt(p->left); //prints Left subtree
        cout << p->text << endl; //print root
        printIt(p->right); //prints right subtree
    }
}

//******************************************************************************
//Function for help with recursion
//Written by Zach

void sBST::clear(sNode *p) {
    if (p) {
        clear(p->left);
        clear(p->right);
        delete p;
    }
}

//******************************************************************************
//Public Functions
//******************************************************************************
//Function to insert the text into the tree 
//Written by Zach

bool sBST::insert(string text) {
    return (insert(root, text));
}

//******************************************************************************
//Function to remove the node with the given text
//Written by Zach edited by Parker

bool sBST::remove(string text) {
    return (remove(root,text));
}

//******************************************************************************
//Function to tell if the tree co`ntains the given text
//Written by Parker

bool sBST::isIn(string text) const {
return (isIn(root,text));
}

//******************************************************************************
//Function to print the BST values in ascending order
//Written by Parker

void sBST::printIt() const{
    printIt(root);
}

//******************************************************************************
//Function to show the number of nodes in the tree
//Written by Zach

int sBST::count() const{
    return treeCount;
}

//******************************************************************************
//Function to remove all of the nodes in the tree
//Written by Zach

void sBST::clear() {
    clear(root);
    treeCount = 0;
    root = NULL;
}