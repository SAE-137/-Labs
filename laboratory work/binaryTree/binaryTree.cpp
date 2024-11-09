#include <iostream>
#include "binaryTree.h"
#include "node.h"



binaryTree::binaryTree()
{
	m_root = nullptr;
}

void binaryTree::setRoot(node* newRoot)
{
	m_root = newRoot;
}

node* binaryTree::getRoot()
{
	return m_root;
}
 
void binaryTree::setMas(int* mas, int amountOfValues)
{
	node* root = new node;
	this->setRoot(root);
	int value = mas[0];
	this->getRoot()->setKey(value);

	for (int i = 1; i < amountOfValues; ++i)
	{
		if (mas[i] < value) {
			node* newNode = new node;
			newNode->setKey(mas[i]);
			root->setLeft(newNode);
			root = newNode;
		}
		else
		{
			node* newNode = new node;
			newNode->setKey(mas[i]);
			root->setRight(newNode);
			root = newNode;
		}
		
	}
}

void binaryTree::show()
{
	std::cout << this->getRoot()->get();

}

int main()
{
	int n;
	std::cin >> n;

	int* mas = new int [n];
	for (int i = 0; i < n; ++i)
	{
		mas[i] = std::rand() % 100;
	}

	for (int i = 0; i < n; ++i)
	{
		std::cout << mas[i] << " ";
	}

	binaryTree testTree;

	testTree.setMas(mas, n);

	testTree.show();

	return 0;
}
