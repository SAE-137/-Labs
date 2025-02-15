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
    newNode = nullptr; 
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

int binaryTree::getAmountOfNodes(node* newNode) const {
    if (newNode == nullptr) return 0;
    return 1 + getAmountOfNodes(newNode->getLeft()) + getAmountOfNodes(newNode->getRight());
}

int binaryTree::getNodeLvl(int key) const {
    return findNodeLevel(m_root, key, 0);
}



int binaryTree::getDepth(node* newNode) const {
    if (newNode == nullptr) return 0;
    int leftDepth = getDepth(newNode->getLeft());
    int rightDepth = getDepth(newNode->getRight());
    return std::max(leftDepth, rightDepth) + 1;
}

int binaryTree::findNodeLevel(node* root, int key, int level) const {
    if (root == nullptr) return -1;
    if (root->getKey() == key) return level;

    int leftLevel = findNodeLevel(root->getLeft(), key, level + 1);
    if (leftLevel != -1) return leftLevel;

    return findNodeLevel(root->getRight(), key, level + 1);
}

int binaryTree::findNodeLevel(int key) const {
    return findNodeLevel(m_root, key, 0);
}

int binaryTree::getMax() const {
    if (m_root == nullptr) {
        throw std::runtime_error("The tree is empty");
    }

    node* current = m_root;
    while (current->getRight()) {
        current = current->getRight();
    }
    return current->getKey();
}

int binaryTree::getMin() const {
    if (m_root == nullptr) {
        throw std::runtime_error("The tree is empty");
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



int height(node* root) {
    if (root == nullptr) return 0;
    return std::max(height(root->getLeft()), height(root->getRight())) + 1;
}

bool binaryTree::isBalanced(node* root)  {
    if (root == nullptr) return true;

    int leftHeight = height(root->getLeft());
    int rightHeight = height(root->getRight());

    if (std::abs(leftHeight - rightHeight) > 1) return false;

    return isBalanced(root->getLeft()) && isBalanced(root->getRight());
}

bool binaryTree::isBalanced()  {
    return isBalanced(m_root);
}

void binaryTree::printCurrentLevel(node* root, int level) {
    if (root == nullptr) return;
    if (level == 1) {
        std::cout << root->getKey() << " ";
    }
    else if (level > 1) {
        printCurrentLevel(root->getLeft(), level - 1);
        printCurrentLevel(root->getRight(), level - 1);
    }
}

void binaryTree::printByLevels() {
    int h = getDepth(m_root); 
    for (int i = 1; i <= h; i++) {
        printCurrentLevel(m_root, i);
        std::cout << std::endl;
    }
}

void binaryTree::inOrderTraversal(node* root, std::vector<int>& keys) {
    if (root == nullptr) return;

    inOrderTraversal(root->getLeft(), keys);  
    keys.push_back(root->getKey());           
    inOrderTraversal(root->getRight(), keys); 
}

std::vector<int> binaryTree::getSortedKeys() {
    std::vector<int> keys;
    inOrderTraversal(m_root, keys);
    return keys;
}


node* binaryTree::copy(node* currentNode) {
    if (currentNode == nullptr) {
        return nullptr;
    }
    
    node* newNode = new node(currentNode->getKey());

    newNode->setLeft(copy(currentNode->getLeft()));
    newNode->setRight(copy(currentNode->getRight()));

    return newNode;
}

binaryTree* binaryTree::copySubTree(int key) {
    node* subRoot = search(m_root, key);

    if (subRoot == nullptr) {
        std::cerr << "Error: node with key " << key << " not found" << std::endl;
        return new binaryTree(); 
    }

    binaryTree* newTree = new binaryTree();
    newTree->setRoot(copy(subRoot)); 
    return newTree;
}

binaryTree::binaryTree(const binaryTree& other) {
    if (other.m_root == nullptr) {
        m_root = nullptr;
    }
    else {
        m_root = copy(other.m_root); 
    }
}

binaryTree& binaryTree::operator=(const binaryTree& other) {
    if (this == &other) return *this; 

    deleteTree();

    if (other.m_root != nullptr) {
        m_root = copy(other.m_root);
    }
    else {
        m_root = nullptr;
    }

    return *this;
}
