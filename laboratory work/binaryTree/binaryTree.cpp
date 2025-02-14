#include <iostream>
#include "binaryTree.h"
#include "node.h"

binaryTree::binaryTree() : m_root(nullptr) {}

binaryTree::~binaryTree() {
    if (m_root) deleteTree();
}

void binaryTree::setRoot(node* newRoot) {
    m_root = newRoot;
}

node* binaryTree::getRoot() {
    return m_root;
}

void binaryTree::show(node* root, int space, int indent) {
    if (root == nullptr) return;

    space += indent;
    show(root->getRight(), space);

    std::cout << std::endl;
    for (int i = indent; i < space; i++) {
        std::cout << " ";
    }
    std::cout << root->getKey() << "\n";

    show(root->getLeft(), space);
}

bool binaryTree::isEmpty() {
    return m_root == nullptr;
}

void binaryTree::deleteTree() {
    deleteSubTree(m_root);
    m_root = nullptr;
}

void binaryTree::deleteSubTree(node* newNode) {
    if (!newNode) return;

    deleteSubTree(newNode->getLeft());
    deleteSubTree(newNode->getRight());

    delete newNode;
    newNode = nullptr; // Теперь указатель обнуляется правильно
}


node* binaryTree::insertRec(node* newNode, int key) {
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

void binaryTree::insert(int key) {
    m_root = insertRec(m_root, key);
}

node* binaryTree::search(node* root, int key) {
    if (root == nullptr || root->getKey() == key) {
        return root;
    }

    if (key < root->getKey()) {
        return search(root->getLeft(), key);
    }

    return search(root->getRight(), key);
}

void binaryTree::printLeafs(node* newNode) {
    if (newNode == nullptr) return;

    if (newNode->getLeft() == nullptr && newNode->getRight() == nullptr) {
        std::cout << newNode->getKey() << " ";
    }

    printLeafs(newNode->getLeft());
    printLeafs(newNode->getRight());
}

int binaryTree::getAmountOfNodes(node* newNode) {
    if (newNode == nullptr) return 0;
    return 1 + getAmountOfNodes(newNode->getLeft()) + getAmountOfNodes(newNode->getRight());
}

int binaryTree::getNodeLvl(int key) {
    return findNodeLevel(m_root, key, 0);
}

node* binaryTree::copy(node* currentNode) {
    if (currentNode == nullptr) return nullptr;

    node* newNode = new node(currentNode->getKey());
    newNode->setLeft(copy(currentNode->getLeft()));
    newNode->setRight(copy(currentNode->getRight()));

    return newNode;
}

binaryTree* binaryTree::copy(binaryTree* otherTree) {
    if (otherTree->getRoot() == nullptr) return nullptr;

    binaryTree* newTree = new binaryTree();
    newTree->setRoot(copy(otherTree->getRoot()));
    return newTree;
}

int binaryTree::getDepth(node* newNode) {
    if (newNode == nullptr) return 0;
    int leftDepth = getDepth(newNode->getLeft());
    int rightDepth = getDepth(newNode->getRight());
    return std::max(leftDepth, rightDepth) + 1;
}

int binaryTree::findNodeLevel(node* root, int key, int level) {
    if (root == nullptr) return -1;
    if (root->getKey() == key) return level;

    int leftLevel = findNodeLevel(root->getLeft(), key, level + 1);
    if (leftLevel != -1) return leftLevel;

    return findNodeLevel(root->getRight(), key, level + 1);
}

int binaryTree::findNodeLevel(int key) {
    return findNodeLevel(m_root, key, 0);
}

int binaryTree::getMax() {
    if (m_root == nullptr) {
        throw std::runtime_error("Дерево пустое");
    }

    node* current = m_root;
    while (current->getRight()) {
        current = current->getRight();
    }
    return current->getKey();
}

int binaryTree::getMin() {
    if (m_root == nullptr) {
        throw std::runtime_error("Дерево пустое");
    }

    node* current = m_root;
    while (current->getLeft()) {
        current = current->getLeft();
    }
    return current->getKey();
}

node* binaryTree::findMin(node* root) {
    while (root && root->getLeft()) {
        root = root->getLeft();
    }
    return root;
}

node* binaryTree::deleteNodeRec(node* root, int key) {
    if (root == nullptr) return nullptr;

    if (key < root->getKey()) {
        root->setLeft(deleteNodeRec(root->getLeft(), key));
    }
    else if (key > root->getKey()) {
        root->setRight(deleteNodeRec(root->getRight(), key));
    }
    else {
        
        if (root->getLeft() == nullptr) {
            node* temp = root->getRight();
            delete root;
            return temp;
        }
        else if (root->getRight() == nullptr) {
            node* temp = root->getLeft();
            delete root;
            return temp;
        }

        
        node* temp = root->getRight();
        while (temp->getLeft() != nullptr) {
            temp = temp->getLeft();
        }

      
        root->setKey(temp->getKey());

        
        root->setRight(deleteNodeRec(root->getRight(), temp->getKey()));
    }
    return root;
}

bool binaryTree::deleteNode(int key) {
    m_root = deleteNodeRec(m_root, key);
    return true;
}

node* binaryTree::insertRandomRec(node* newNode, int key) {
    if (newNode == nullptr) {
        return new node(key);
    }

    
    if (rand() % 2 == 0) {
        newNode->setLeft(insertRandomRec(newNode->getLeft(), key));
    }
    else {
        newNode->setRight(insertRandomRec(newNode->getRight(), key));
    }

    return newNode;
}

void binaryTree::insertRandom(int key) {
    m_root = insertRandomRec(m_root, key);
}