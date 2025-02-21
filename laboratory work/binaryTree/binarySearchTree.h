#pragma once

#include "binaryTree.h"

class binarySearchTree : public binaryTree
{
public:
	binarySearchTree() : binaryTree() { }


	void insert(int key) override;

	int getMin()  override;
	int getMax()  override;

	node* search(node* root, int key) override;
	node* search(int key);
		
	bool deleteNode(int key) override;


	node* insertRec(node* node, int key);
private:

};