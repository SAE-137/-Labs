#pragma once

#include "binaryTree.h"

class binarySearchTree : public binaryTree
{
public:
	binarySearchTree() : binaryTree() { }


	void insert(int key) override;

	int getMin()  override;
	int getMax()  override;



	node* insertRec(node* node, int key);
private:

};