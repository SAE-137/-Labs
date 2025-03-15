#pragma once

#include "C:\Users\admin\Desktop\Algorithms\-Labs\laboratory work\binarySearchTree\binarySearchTree.h"
class AVLTree : public binarySearchTree
{
public:
    AVLTree() : binarySearchTree(){}
    ~AVLTree() = default;

   
	int height(node* newNode);
    int balanceFactor(node* newNode);
   
    void insert(int key);
    void updateHeight(node* newNode);
    bool deleteNode(int key);

    node* rightRotate(node* y);
    node* leftRotate(node* x);
    node* balance(node* newNode);
    node* insert(node* root, int key) override;
    node* remove(node* newNode, int key);

private:
   

};

