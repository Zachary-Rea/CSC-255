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
//Written by Zach

sNode::sNode(string text) {
    this->text = text;
    left = right = NULL;
    this->h = 0;
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
//Written by Zach

string sBST::findMin(sNode *ptr) {
    string rc;
    if (ptr->left) {
        findMin(ptr->left);
    } else if (ptr->right) {
        findMin(ptr->right);
    } else {
        rc = ptr->text;
    }
    return rc;
}

//******************************************************************************
//Function for help with recursion
//Written by Zach

bool sBST::insert(sNode *p, string text) {
    bool rc = false;
    if (treeCount == 0) {
        sNode *t = new sNode(text);
        root = t;
        treeCount++;
        rc = true;
        
    } else {
        int check = text.compare(p->text);
        if (check > 0) {
            if (p->right) {
                insert(p->right,text);
            } else {
                sNode *t = new sNode(text);
                p->right = t;
                treeCount++;
                rc = true;
            }
        } else if (check < 0) {
            if (p->left) {
                insert(p->left,text);
            } else {
                sNode *t = new sNode(text);
                p->left = t;
                treeCount++;
                rc = true;
            }
        }
    }
    return rc;
}

//******************************************************************************
//Function for help with recursion
//Written by Zach

bool sBST::remove(sNode *p, string text) {
    bool rc = false;
    if (p) {
        int check = text.compare(p->text);
        if (check == 0) {
            if (p->right) {
                p->text = findMin(p->right);
                delete(p->right);
                treeCount--;
            } else if (p->left) {
                sNode *t = p;
                p = p->left;
                delete t;
                treeCount--;
            } else {
                delete p;
                treeCount--;
            }
            rc = true;
        } else if (check < 0) {
            remove(p->left,text);
        } else if (check > 0) {
            remove(p->right,text);
        }
    }
    return rc;
}

//******************************************************************************
//Function for help with recursion
//Stubbed

bool sBST::isIn() {
    if (p == NULL){

    }
    return false;

}

//******************************************************************************
//Function for help with recursion
//Written by Parker

void sBST::printIt(sNode *p) const{
  if (p != NULL){ //making sure function has a printable node 
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
    bool rc = false;
    rc = insert(root, text);
    return rc;
}

//******************************************************************************
//Function to remove the node with the given text
//Written by Zach

bool sBST::remove(string text) {
    bool rc = false;
    if (treeCount) {
        sNode *p = root;
        rc = remove(p,text);
    }
    return rc;
}

//******************************************************************************
//Function to tell if the tree contains the given text
//Stubbed

bool sBST::isIn(string text) {
    return false;
}

//******************************************************************************
//Function to print the BST values in ascending order
//Written by Parker

void sBST::printIt() const{
    if (treeCount) {
        printIt(root);
    }
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