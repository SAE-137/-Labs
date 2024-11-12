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
    if (amountOfValues <= 0) return;

   
    node* root = new node;
    root->setKey(mas[0]);
    this->setRoot(root);

   
    for (int i = 1; i < amountOfValues; ++i)
    {
        insertNode(this->getRoot(), mas[i]);
    }
}


void binaryTree::insertNode(node* root, int value)
{
    if (value < root->getKey())
    {
        if (root->getLeft() == nullptr)
        {
            node* newNode = new node;
            newNode->setKey(value);
            root->setLeft(newNode);
        }
        else
        {
            insertNode(root->getLeft(), value);
        }
    }
    else
    {
        if (root->getRight() == nullptr)
        {
            node* newNode = new node;
            newNode->setKey(value);
            root->setRight(newNode);
        }
        else
        {
            insertNode(root->getRight(), value);
        }
    }
}

void binaryTree::show(node* root, int space, int indent)
{
	if (root == nullptr) {
		return;
	}

	space += indent;

	
	show(root->m_right, space);

	
	std::cout << std::endl;
	for (int i = indent; i < space; i++) {
		std::cout << " ";
	}
	std::cout << root->getKey() << "\n";

	
	show(root->m_left, space);

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
	std::cout << std::endl;
	testTree.show(testTree.getRoot());

	return 0;
}


bool binaryTree::isEmpty()
{
    if (this->getRoot() == nullptr)
    {
        return false;
    }
    return true;
}