#pragma once

#include "binarySearchTree.h"
class AVLTree : public binarySearchTree
{
public:

	int height(node* newNode);
    int balanceFactor(node* newNode);
   
    void insert(int key) override;
    void updateHeight(node* newNode);

    node* rightRotate(node* y);
    node* leftRotate(node* x);
    node* balance(node* newNode);
    node* insertRec(node* newNode, int key) override;

};

