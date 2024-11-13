#include <iostream>
#include "binaryTree.h"
#include "node.h"





binaryTree::binaryTree()
{
    m_root = new node;
    m_root = nullptr;
}

binaryTree::~binaryTree()
{
    if(m_root) deleteTree();

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

void binaryTree::deleteTree()
{
    deleteSubTree(m_root);
    m_root = nullptr;
}

void binaryTree::deleteSubTree(node* newNode)
{
    if (!newNode) return;
    
        deleteSubTree(newNode->getLeft());
        deleteSubTree(newNode->getRight());

        delete newNode;
    
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
    if(m_root) m_root = insertRec(m_root, key);
}


node* binaryTree::search(node* root, int key)
{
    if (root == nullptr)
    {
        return nullptr; 
    }

    if (root->getKey() == key)
    {
        return root; 
    }

   
    node* leftResult = search(root->getLeft(), key);
    if (leftResult != nullptr)
    {
        return leftResult; 
    }

    return search(root->getRight(), key);
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

int binaryTree::getAmountOfNodes(node* newNode)
{
    if (newNode == nullptr) return 0;

        return getAmountOfNodes(newNode->getLeft()) + getAmountOfNodes(newNode->getRight()) + 1; 

}

int binaryTree::getNodeLvl(int key)
{
    return 0;
}



binaryTree* binaryTree::copy(node* newNode)
{
    if (newNode == nullptr) return nullptr;

    if(this->getRoot() == nullptr)
        this->getRoot()->setKey(newNode->getKey());



    return this;



    
}

int binaryTree::getDepth(node* newNode)
{
    if (newNode)
    {
        int l = getDepth(newNode->getLeft());
        int r = getDepth(newNode->getRight());

        if (l < r) {
            return r + 1;

        }
        else
        {
            return l + 1;
        }

    }
    return 0;
}