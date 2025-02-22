#pragma once

#include "binarySearchTree.h"
class AVLTree : public binarySearchTree
{
public:
    AVLTree() : binarySearchTree() {}
    AVLTree(const AVLTree& other);
    ~AVLTree();

	int height(node* newNode);
    int balanceFactor(node* newNode);
   
    void insert(int key) override;
    void updateHeight(node* newNode);
    bool deleteNode(int key) override;

    node* rightRotate(node* y);
    node* leftRotate(node* x);
    node* balance(node* newNode);
    node* insertRec(node* newNode, int key) override;
    node* remove(node* newNode, int key);

private:
   

};

