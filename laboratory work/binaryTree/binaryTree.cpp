#include <iostream>
#include "binaryTree.h"
#include "node.h"



binaryTree::~binaryTree()
{
    if (this->getRoot() != nullptr) {
        deleteTree(this->getRoot());
    }
    
    return;
}

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
 




void binaryTree::show(node* root, int space, int indent)
{
	if (root == nullptr) {
		return;
	}

	space += indent;

	
	show(root->getRight(), space);

	
	std::cout << std::endl;
	for (int i = indent; i < space; i++) {
		std::cout << " ";
	}
	std::cout << root->getKey() << "\n";

	
	show(root->getLeft(), space);

}



bool binaryTree::isEmpty()
{
    if (m_root == nullptr)
    {
        return true;
    }
    return false;
}

void binaryTree::deleteTree(node* newNode)
{
    if (newNode == nullptr)
    {
        return;
    }

    deleteTree(newNode->getLeft());
    deleteTree(newNode->getRight());

    delete newNode;
    
}

void binaryTree::addNode(node* newNode, int key)
{
    node* Node;
    newNode->setKey(key);
    if (newNode == nullptr)
    {
        node* node;

        m_root = newNode;
        m_root->setKey(key);
        return;
    }
    if (newNode->getKey() > key)
    {
        addNode(newNode->getLeft(), key);
    }
    else 
    {
        addNode(newNode->getRight(), key);
    }
    

}

node* binaryTree::insertRec(node* newNode, int key) {
    if (newNode == nullptr) {
        return new node(key);
    }

    if (key < newNode->getKey()) 
    {
        newNode->setLeft(insertRec(newNode->getLeft(), key));
    }
    else if (key > newNode->getKey()) {
        newNode->setRight(insertRec(newNode->getRight(), key));
    }

    return newNode;
}

void binaryTree::insert(int key) {
    m_root = insertRec(m_root, key);
}