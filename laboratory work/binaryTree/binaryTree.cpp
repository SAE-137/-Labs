#include <iostream>
#include "binaryTree.h"
#include "node.h"





binaryTree::binaryTree()
{
	m_root = nullptr;
}

binaryTree::~binaryTree()
{

    deleteTree(m_root);

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
    if (newNode)
    {
        deleteTree(newNode->getLeft());
        deleteTree(newNode->getRight());

        delete newNode;
    }

    newNode = nullptr;
    
}

node* binaryTree::insertRec(node* newNode, int key) {
    if (newNode == nullptr) {
        return new node(key);
    }

    if (key <= newNode->getKey()) 
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


node* binaryTree::search(node* root, int key)
{
    if (root)
    {
        if (root->getKey() == key) return root;
        search(root->getLeft(), key);
        search(root->getRight(), key);
    }
    return nullptr;
}

void binaryTree::deleteNode(int key)
{
    node* newNode = new node;
    newNode = search(m_root, key);


}

void binaryTree::printLeafs(node* newNode)
{
    if (newNode != nullptr)
    {
        if (newNode->getLeft() == nullptr && newNode->getRight() == nullptr) {
            std::cout << newNode->getKey() << " ";
            return;
        }
        printLeafs(newNode->getLeft());
        printLeafs(newNode->getRight());
    }
}

int binaryTree::getAmountOfNodes(node* newNode, int static value = 0)
{

    if (newNode)
    {

        getAmountOfNodes(newNode->getLeft(),value++);
        
        getAmountOfNodes(newNode->getRight(),value++);

    }
}