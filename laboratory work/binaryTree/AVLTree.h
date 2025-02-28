#pragma once

#include "binarySearchTree.h"
class AVLTree : public binarySearchTree
{
public:
   
	int height(node* newNode);
    int balanceFactor(node* newNode);
   
   
    void updateHeight(node* newNode);
    bool deleteNode(int key) override;

    node* rightRotate(node* y);
    node* leftRotate(node* x);
    node* balance(node* newNode);
    node* insert(node* newNode, int key) override;
    node* remove(node* newNode, int key);

private:
   

};

