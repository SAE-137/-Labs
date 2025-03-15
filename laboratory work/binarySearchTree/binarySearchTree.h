#pragma once

#include "C:\Users\admin\Desktop\Algorithms\-Labs\laboratory work\binaryTree\binaryTree.h"

class binarySearchTree : public binaryTree
{
public:
	binarySearchTree() : binaryTree() {}
	~binarySearchTree() = default;

	virtual void insert(int key) override;

	int getMin() const override;
	int getMax() const override;
	int getNodeLvl(int key) const override;

	node* deleteNode(node* root, node* currentNode) override;
	node* deleteNode(node* currentNode) override;
	virtual node* insert(node* newNode, int key) override;
	node* search(node* root, int key) const override;
	node* search(int key) const;

	bool deleteNode(int key) override;

	node* findMin(node* root) override;
	virtual node* _traverseToReplacement(node* replacementParent);

	std::vector<int> getSortedKeys() const override;

private:

};

