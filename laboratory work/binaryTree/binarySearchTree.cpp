#include<iostream>
#include "binarySearchTree.h"



binarySearchTree::~binarySearchTree() {
   
}

int binarySearchTree::getMin() const{
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
        current = current->getLeft();
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
    node* replacement = nullptr;

    if (!currentNode) {
        replacement = nullptr;
    }
    else if (!currentNode->getLeft()) {
        replacement = currentNode->getRight();
    }
    else if (!currentNode->getRight()) {
        replacement = currentNode->getLeft();
    }
    else {
        replacement = currentNode->getLeft();
        node* replacementParent = _traverseToReplacement(replacement);
        if (replacement != replacementParent) {
            replacement = replacementParent->getRight();

            replacementParent->setRight(replacement->getLeft());
            replacement->setLeft(currentNode->getLeft());
        }

        replacement->setRight(currentNode->getRight());
    }

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