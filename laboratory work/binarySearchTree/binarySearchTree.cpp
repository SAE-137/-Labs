
#include<iostream>
#include "binarySearchTree.h"





int binarySearchTree::getMin() const {
    if (m_root == nullptr) {
        return -1;
    }

    node* current = m_root;
    while (current->getLeft() != nullptr) {
        current = current->getLeft();
    }
    return current->getKey();
}

int binarySearchTree::getMax() const {
    if (m_root == nullptr) {
        return -1;
    }

    node* current = m_root;
    while (current->getRight() != nullptr) {
        current = current->getRight();
    }
    return current->getKey();
}



void binarySearchTree::insert(int key) {
    setRoot(insert(getRoot(), key));
}

node* binarySearchTree::search(node* root, int key) const {
    if (root == nullptr || root->getKey() == key) {
        return root;
    }

    if (key < root->getKey()) {
        return search(root->getLeft(), key);
    }

    return search(root->getRight(), key);
}

node* binarySearchTree::search(int key) const
{
    return search(getRoot(), key);
}

node* binarySearchTree::_traverseToReplacement(node* replacementParent)
{
    if (!replacementParent->getRight() || !replacementParent->getRight()->getRight()) {
        return replacementParent;
    }

    return _traverseToReplacement(replacementParent->getRight());
}

node* binarySearchTree::deleteNode(node* currentNode)
{
    if (!currentNode) {
        return nullptr;
    }

    if (!currentNode->getLeft()) {
        node* temp = currentNode->getRight();
        delete currentNode;
        return temp;
    }

    if (!currentNode->getRight()) {
        node* temp = currentNode->getLeft();
        delete currentNode;
        return temp;
    }

    node* replacementParent = currentNode;
    node* replacement = currentNode->getRight();

    while (replacement->getLeft()) {
        replacementParent = replacement;
        replacement = replacement->getLeft();
    }

    if (replacementParent != currentNode) {
        replacementParent->setLeft(replacement->getRight());
        replacement->setRight(currentNode->getRight());
    }

    replacement->setLeft(currentNode->getLeft());

    delete currentNode;
    return replacement;
}


node* binarySearchTree::deleteNode(node* root, node* currentNode)
{
    if (!root || !currentNode) {
        return root;
    }

    if (root == currentNode) {
        return deleteNode(currentNode);
    }

    if (currentNode->getKey() < root->getKey()) {
        root->setLeft(deleteNode(root->getLeft(), currentNode));
    }
    else {
        root->setRight(deleteNode(root->getRight(), currentNode));
    }

    return root;
}





std::vector<int> binarySearchTree::getSortedKeys() const {
    std::vector<int> result;
    node* current = m_root;
    std::vector<node*> stack;

    while (!stack.empty() || current) {
        
        while (current) {
            stack.push_back(current);
            current = current->getLeft();
        }

        
        current = stack.back();
        stack.pop_back();
        result.push_back(current->getKey());

       
        current = current->getRight();
    }

    return result;
}

int binarySearchTree::getNodeLvl(int key) const {
    node* current = m_root;
    int level = 0;

    while (current) {
        if (key == current->getKey()) {
            return level;
        }
        else if (key < current->getKey()) {
            current = current->getLeft();
        }
        else {
            current = current->getRight();
        }
        level++;
    }

    return -1;
}


bool binarySearchTree::deleteNode(int key) {
    node* target = search(key);
    if (!target) {
        return false;
    }

    m_root = deleteNode(getRoot(), target);
    return true;
}

node* binarySearchTree::insert(node* root, int key) {
    if (!root) {
        root = new node(key);
    }
    else if (key < root->getKey()) {
        root->setLeft(insert(root->getLeft(), key));
    }
    else {
        root->setRight(insert(root->getRight(), key));
    }

    return root;
}
