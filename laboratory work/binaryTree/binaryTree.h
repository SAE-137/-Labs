#pragma once
#include "node.h"

class binaryTree
{
public:
	binaryTree();


	void setMas(int* mas, int amountOfValues);
	void setRoot(node* newRoot);
	void show(node* root, int space = 0, int indentv = 4);
	void insertNode(node* root, int value);

	node* getRoot();

private:
	node* m_root;
};

