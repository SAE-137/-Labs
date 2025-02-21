#include<iostream>
#include "binarySearchTree.h"

binarySearchTree::binarySearchTree()
{

}

int binarySearchTree::getMax() const {
    if (m_root == nullptr) {
        throw std::runtime_error("The tree is empty");
    }

    node* current = m_root;
    while (current->getLeft()) {
        current = current->getLeft();
    }
    return current->getKey();

}

int binarySearchTree::getMin() const {

    if (m_root == nullptr) {
        throw std::runtime_error("The tree is empty");
    }

    node* current = m_root;
    while (current->getRight()) {
        current = current->getRight();
    }
    return current->getKey();
}

node* binarySearchTree::insertRec(node* newNode, int key) {
    if (newNode == nullptr) return new node(key);
    if (key < newNode->getKey()) {
        newNode->m_left = insertRec(newNode->m_left, key);
    }
    else if (key > newNode->m_key) {
        newNode->m_right = insertRec(newNode->m_right, key);
    }
    return newNode;
}

void binarySearchTree::insert(int key) {
    m_root = insertRec(m_root, key);
}
