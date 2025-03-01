#include <iostream>
#include "binaryTree.h"
#include "node.h"
#include<assert.h>
#include<limits>
binaryTree::binaryTree() 
{
    m_root = nullptr;
}

binaryTree::~binaryTree() {
    if (m_root) deleteTree();
}

void binaryTree::setRoot(node* newRoot) {
    m_root = newRoot;
}


node* binaryTree::getRoot() const {
    return m_root;
}

void binaryTree::show(node* root, int space, int indent) const {
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

bool binaryTree::isEmpty() const {
    return m_root == nullptr;
}

void binaryTree::deleteTree() {
    deleteTree(m_root);
    m_root = nullptr;
}

void binaryTree::deleteTree(node* newNode) {
    if (!newNode) return;

    deleteTree(newNode->getLeft());
    deleteTree(newNode->getRight());

    delete newNode;
}


node* binaryTree::insert(node* newNode, int key) {
     if (!newNode) {
         newNode = new node(key);
    } else if (rand() % 2) {
        newNode->setLeft(insert(newNode->getLeft(), key));
    } else {
        newNode->setRight(insert(newNode->getRight(), key));
    }

    return newNode;
}

void binaryTree::insert(int key) {
    m_root = insert(m_root, key);
}

node* binaryTree::search(node* root, int key) const
{

    if (root == nullptr) return nullptr;

    if (root->getKey() == key) return root;

    node* rightResult = search(root->getRight(), key);
    if (rightResult != nullptr) return rightResult; 

    node* leftResult = search(root->getLeft(), key);
    if (leftResult != nullptr) return leftResult; 

    return nullptr;
}

node* binaryTree::search(int key) const{
    return search(getRoot(), key);
}

void binaryTree::printLeafs(node* newNode) const {
    if (newNode == nullptr) return;

    if (newNode->getLeft() == nullptr && newNode->getRight() == nullptr) {
        std::cout << newNode->getKey() << " ";
    }

    printLeafs(newNode->getLeft());
    printLeafs(newNode->getRight());
}

void binaryTree::printLeafs() const
{
    printLeafs(getRoot());
}

int binaryTree::getAmountOfNodes(node* newNode) const {
    if (newNode == nullptr) return 0;
    return 1 + getAmountOfNodes(newNode->getLeft()) + getAmountOfNodes(newNode->getRight());
}

int binaryTree::getAmountOfNodes() const
{
    return getAmountOfNodes(getRoot());
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

int binaryTree::getDepth() const
{
    return getDepth(getRoot());
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
    return getMax(getRoot());
}

int binaryTree::getMin() const {
    return getMin(getRoot());
}

int binaryTree::getMin(node* root) const{
    if (root == nullptr) {
        return -1; 
    }

   
    int currentKey = root->getKey();
    int leftMin = getMin(root->getLeft());
    int rightMin = getMin(root->getRight());

    
    return std::min({ currentKey, leftMin, rightMin });
}

int binaryTree::getMax(node* root) const{
    if (root == nullptr) {
        return -1;
    }


    int currentKey = root->getKey();
    int leftMin = getMin(root->getLeft());
    int rightMin = getMin(root->getRight());


    return std::max({ currentKey, leftMin, rightMin });
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






int height(node* root) {
    if (root == nullptr) return 0;
    return std::max(height(root->getLeft()), height(root->getRight())) + 1;
}

bool binaryTree::isBalanced(node* root)  const{
    if (root == nullptr) return true;

    int leftHeight = height(root->getLeft());
    int rightHeight = height(root->getRight());

    if (std::abs(leftHeight - rightHeight) > 1) return false;

    return isBalanced(root->getLeft()) && isBalanced(root->getRight());
}

bool binaryTree::isBalanced() const {
    return isBalanced(m_root);
}

void binaryTree::printCurrentLevel(node* root, int level) const{
    if (root == nullptr) return;
    if (level == 1) {
        std::cout << root->getKey() << " ";
    }
    else if (level > 1) {
        printCurrentLevel(root->getLeft(), level - 1);
        printCurrentLevel(root->getRight(), level - 1);
    }
}

void binaryTree::printByLevels() const{
    int h = getDepth(m_root); 
    for (int i = 1; i <= h; i++) {
        printCurrentLevel(m_root, i);
        std::cout << std::endl;
    }
}

void binaryTree::inOrderTraversal(node* root, std::vector<int>& keys) const{
    if (root == nullptr) return;

    inOrderTraversal(root->getLeft(), keys);  
    keys.push_back(root->getKey());           
    inOrderTraversal(root->getRight(), keys); 
}

std::vector<int> binaryTree::getSortedKeys() const{
    std::vector<int> keys;
    inOrderTraversal(m_root, keys);
    return keys;
}


node* binaryTree::_copy(node* currentNode) const {
    if (currentNode == nullptr) {
        return nullptr;
    }
    
    node* newNode = new node(currentNode->getKey());

    newNode->setLeft(_copy(currentNode->getLeft()));
    newNode->setRight(_copy(currentNode->getRight()));

    return newNode;
}

node* binaryTree::_copy() const
{
    return _copy(getRoot());
}

//binaryTree* binaryTree::copySubTree(int key) {
//    node* subRoot = search(m_root, key);
//
//    if (subRoot == nullptr) {
//        std::cerr << "Error: node with key " << key << " not found" << std::endl;
//        return newTree();
//    }
//
//    binaryTree* newTree = newTree();
//    newTree->setRoot(copy(subRoot)); 
//    return newTree;
//}

binaryTree* binaryTree::newTree() {
    return new binaryTree();
}



binaryTree::binaryTree(const binaryTree& other) {
    if (other.m_root == nullptr) {
        m_root = nullptr;
    }
    else {
        m_root = _copy(other.m_root); 
    }
}

binaryTree& binaryTree::operator=(const binaryTree& other) {
    if (this == &other) return *this; 

    deleteTree();

    if (other.m_root != nullptr) {
        m_root = _copy(other.m_root);
    }
    else {
        m_root = nullptr;
    }

    return *this;
}

void binaryTree::test()
{
    std::cout << "text for testing";
}


binaryTree binaryTree::copy() const
{
    return copy(getRoot());
}

binaryTree binaryTree::copy(node* root) const
{
    binaryTree newTree;
    newTree.setRoot(_copy(root));
    return newTree;

}


node* binaryTree::findParent(node* root, node* currentNode) const
{
    if (!root || root == currentNode) 
        return nullptr;

    if (root->getLeft() == currentNode || root->getRight() == currentNode) 
        return root;

    node* parent = findParent(root->getLeft(), currentNode);
    return parent ? parent : findParent(root->getRight(), currentNode);
}

node* binaryTree::findParent(node* currentNode) const
{
    return findParent(getRoot(), currentNode);
}

node* binaryTree::deleteNode(node* root, node* currentNode)
{
    node* parent = findParent(root, currentNode);
    node* replacement = deleteNode(currentNode);

    if (!parent) {
        return replacement;
    }
    else if (parent->getLeft() == currentNode) {
        parent->setLeft(replacement);
    }
    else if (parent->getRight() == currentNode) {
        parent->setRight(replacement);
    }
    else {
        assert(false && "Invalid parent detection in remove");
    }

    return root;
}

node* binaryTree::deleteNode(node* currentNode)
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
        node* replacementParent = currentNode;
        while (replacement->getLeft() || replacement->getRight()) {
            replacementParent = replacement;
            replacement = (replacement->getLeft() ? replacement->getLeft() : replacement->getRight());
        }

        if (replacement == replacementParent->getLeft()) {
            replacementParent->setLeft(nullptr);
        }
        else {
            replacementParent->setRight(nullptr);
        }

        replacement->setLeft(currentNode->getLeft());
        replacement->setRight(currentNode->getRight());
    }

    delete currentNode;
    return replacement;
}



node* binaryTree::find(node* root, int key) const
{
    if (!root) {
        return nullptr;
    }
    else if (root->getKey() == key) {
        return root;
    }

    node* newNode = find(root->getLeft(), key);
    return newNode ? newNode : find(root->getRight(), key);
}

node* binaryTree::find(int key) const
{
    return find(m_root, key);
}

bool binaryTree::deleteNode(int key)
{
    node* newNode = find(key);
    if (!newNode) {
        return false;
    }

    m_root = deleteNode(getRoot(), newNode);
    return true;
}