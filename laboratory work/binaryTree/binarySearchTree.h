#pragma once

#include "binaryTree.h"

class binarySearchTree : public binaryTree
{
public:
	binarySearchTree();
	~binarySearchTree() = default;

	virtual void insert(int key) override;

	int getMin() const override;
	int getMax() const override;
	
	node* deleteNode(node* root, node* currentNode) override;
	node* deleteNode(node* currentNode) override;
	node* insert(node* newNode, int key) override;
	node* search(node* root, int key) const override;
	node* search(int key) const;
	
		//TODO вровуень ноды, вернуть вектор 
	virtual bool deleteNode(int key) override;
	virtual node* _traverseToReplacement(node* replacementParent);
	

	
private:

};

