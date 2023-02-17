/*
Filename: p4.h
Author(s): Zachary Rea and Parker Ross
Date: 12 February 2023
Description: The header file for p4
*/
#ifndef __P4_H
#define __P4_H

#include <string>
//******************************************************************************
class sBST;
class sNode {
    private:
        //Node key
        std::string text;
        //For future use
        int h;
        //Pointers for left and right children
        sNode *left, *right;
        //Constructor for the node
        sNode(std::string text = "");
        friend sBST;
};
class sBST {
    private:
        //Current size of the tree
        int treeCount;
        //Points to the top of the tree of nodes
        sNode *root;
        //Function to find the minimum value of the subtree
        std::string findMin(sNode *ptr);
        //Function for help with recursion
        bool insert(sNode *p, std::string text);
        //Function for help with recursion
        bool remove(sNode *p, std::string text);
        //Function for help with recursion
        bool isIn(sNode *p, std::string text) const;
        //Function for help with recursion
        void printIt(sNode *p) const;
        //Function for help with recursion
        void clear(sNode *p);
    public:
        //Constructor
        sBST();
        //De-constructor
        ~sBST();
        //Function to insert the text into the tree
        bool insert(std::string text);
        //Function to remove the node with the given text
        bool remove(std::string text);
        //Function to tell if the tree contains the text
        bool isIn(sNode *p, std::string text) const;
        //Function to print the BST values in ascending order
        void printIt() const;
        //Function to show the number of nodes in the tree
        int count() const;
        //Function to remove all nodes from the tree
        void clear();
};
#endif