#include "AVLTree.h"





int AVLTree::height(node* newNode) {
    return newNode ? newNode->height : 0;
}


int AVLTree::balanceFactor(node* newNode) {
    return newNode ? height(newNode->m_left) - height(newNode->m_right) : 0;
}


void AVLTree::updateHeight(node* newNode) {
    if (newNode) {
        newNode->height = std::max(height(newNode->m_left), height(newNode->m_right)) + 1;
    }
}

node* AVLTree::rightRotate(node* y) {
    node* x = y->m_left;
    node* T2 = x->m_right;

    x->m_right = y;
    y->m_left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}


node* AVLTree::leftRotate(node* x) {
    node* y = x->m_right;
    node* T2 = y->m_left;

    y->m_left = x;
    x->m_right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}


node* AVLTree::balance(node* newNode) {
    updateHeight(newNode);

    if (balanceFactor(newNode) > 1) {
        if (balanceFactor(newNode->m_left) < 0) {
            newNode->m_left = leftRotate(newNode->m_left);
        }
        return rightRotate(newNode);
    }

    if (balanceFactor(newNode) < -1) {
        if (balanceFactor(newNode->m_right) > 0) {
            newNode->m_right = rightRotate(newNode->m_right);
        }
        return leftRotate(newNode);
    }

    return newNode;
}


node* AVLTree::insert(node* newNode, int key) {
    if (!newNode) return new node(key);
   
    if (key < newNode->m_key) {
        newNode->m_left = insert(newNode->m_left, key);
    }
    else if (key > newNode->m_key) {
        newNode->m_right = insert(newNode->m_right, key);
    }
    else {
        return newNode; 
    }

    return balance(newNode);
}

node* AVLTree::remove(node* newNode, int key) {
    if (!newNode) return nullptr;

    if (key < newNode->m_key) {
        newNode->m_left = remove(newNode->m_left, key);
    }
    else if (key > newNode->m_key) {
        newNode->m_right = remove(newNode->m_right, key);
    }
    else {
        if (!newNode->m_left || !newNode->m_right) {
            node* temp = newNode->m_left ? newNode->m_left : newNode->m_right;
            if (!temp) {
                temp = newNode;
                newNode = nullptr;
            }
            else {
                *newNode = *temp;
            }
            delete temp;
        }
        else {
            node* temp = findMin(newNode->m_right);
            newNode->m_key = temp->m_key;
            newNode->m_right = remove(newNode->m_right, temp->m_key);
        }
    }

    if (!newNode) return nullptr;

    return balance(newNode);
}

bool AVLTree::deleteNode(int key)
{
    if (remove(getRoot(), key) == nullptr) return false;
    return true;
}

