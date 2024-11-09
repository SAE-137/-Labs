#pragma once
#include "node.h"

class binaryTree
{
public:
	binaryTree();


	void setMas(int* mas, int amountOfValues);
	void setRoot(node* newRoot);
	void show();
	node* getRoot();

private:
	node* m_root;
};

