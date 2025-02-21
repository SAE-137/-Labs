#pragma once

#include "binaryTree.h"

class binarySearchTree : public binaryTree
{
public:
	binarySearchTree();


	void insert(int key) override;

	int getMin() const;
	int getMax() const;



	node* insertRec(node* node, int key);
private:
	node* m_root;
};