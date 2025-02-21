#include<iostream>
#include "binarySearchTree.h"



int binarySearchTree::getMin() {
    if (getRoot() == nullptr) {
        throw std::runtime_error("The tree is empty");
    }

    node* current = getRoot();
    while (current->getLeft()) {
        current = current->getLeft();
    }
    return current->getKey();
}

int binarySearchTree::getMax()  {
    if (getRoot() == nullptr) {
        throw std::runtime_error("The tree is empty");
    }

    node* current = getRoot();
    while (current->getRight()) {
        current = current->getRight();
    }
    return current->getKey();
}

node* binarySearchTree::insertRec(node* newNode, int key) {
    if (newNode == nullptr) {
        return new node(key);
    }

    if (key <= newNode->getKey()) {
        newNode->setLeft(insertRec(newNode->getLeft(), key));
    }
    else {
        newNode->setRight(insertRec(newNode->getRight(), key));
    }

    return newNode;
}

void binarySearchTree::insert(int key) {
    setRoot(insertRec(getRoot(), key)); 
}

node* binarySearchTree::search(node* root, int key) {
    if (root == nullptr || root->getKey() == key) {
        return root;
    }

    if (key < root->getKey()) {
        return search(root->getLeft(), key);
    }

    return search(root->getRight(), key);
}

node* binarySearchTree::search(int key)  {
    return search(getRoot(), key); 
}

bool binarySearchTree::deleteNode(int key) {
    node* parent = nullptr;
    node* current = getRoot();

    while (current != nullptr && current->getKey() != key) {
        parent = current;
        if (key < current->getKey()) {
            current = current->getLeft();
        }
        else {
            current = current->getRight();
        }
    }

    if (current == nullptr) {
        return false;
    }

    if (current->getLeft() == nullptr && current->getRight() == nullptr) {
        if (current != getRoot()) {
            if (parent->getLeft() == current) {
                parent->setLeft(nullptr);
            }
            else {
                parent->setRight(nullptr);
            }
        }
        else {
            setRoot(nullptr); 
        }
        delete current;
    }
   
    else if (current->getLeft() == nullptr || current->getRight() == nullptr) {
        node* child = (current->getLeft() != nullptr) ? current->getLeft() : current->getRight();

        if (current != getRoot()) {
            if (parent->getLeft() == current) {
                parent->setLeft(child);
            }
            else {
                parent->setRight(child);
            }
        }
        else {
            setRoot(child); 
        }
        delete current;
    }
  
    else {
       
        node* successor = findMin(current->getRight());

        
        current->setKey(successor->getKey());

        
        deleteNodeRec(current->getRight(), successor->getKey());
    }

    return true; 
}