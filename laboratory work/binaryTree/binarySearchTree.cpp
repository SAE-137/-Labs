//#include<iostream>
//#include "binarySearchTree.h"
//
//
//
//binarySearchTree::~binarySearchTree() {
//    deleteTree(); 
//}
//
//
//binarySearchTree::binarySearchTree(const binarySearchTree& other) {
//    m_root = copyTree(other.m_root); 
//}
//
//node* binarySearchTree::copyTree(const node* root)  {
//    if (root == nullptr) {
//        return nullptr; 
//    }
//
//   
//    node* newNode = new node(getRoot()->getKey());
//
//   
//    newNode->setLeft(copyTree(getRoot()->getLeft()));
//    newNode->setRight(copyTree(getRoot()->getRight()));
//
//    return newNode;
//}
//
//int binarySearchTree::getMin() {
//    if (getRoot() == nullptr) {
//        throw std::runtime_error("The tree is empty");
//    }
//
//    node* current = getRoot();
//    while (current->getLeft()) {
//        current = current->getLeft();
//    }
//    return current->getKey();
//}
//
//int binarySearchTree::getMax()  {
//    if (getRoot() == nullptr) {
//        throw std::runtime_error("The tree is empty");
//    }
//
//    node* current = getRoot();
//    while (current->getRight()) {
//        current = current->getRight();
//    }
//    return current->getKey();
//}
//
//node* binarySearchTree::insertRec(node* newNode, int key) {
//    if (newNode == nullptr) {
//        return new node(key);
//    }
//
//    if (key <= newNode->getKey()) {
//        newNode->setLeft(insertRec(newNode->getLeft(), key));
//    }
//    else {
//        newNode->setRight(insertRec(newNode->getRight(), key));
//    }
//
//    return newNode;
//}
//
//void binarySearchTree::insert(int key) {
//    setRoot(insertRec(getRoot(), key)); 
//}
//
//node* binarySearchTree::search(node* root, int key) {
//    if (root == nullptr || root->getKey() == key) {
//        return root;
//    }
//
//    if (key < root->getKey()) {
//        return search(root->getLeft(), key);
//    }
//
//    return search(root->getRight(), key);
//}
//
//bool binarySearchTree::deleteNode(int key) {
//    node* parent = nullptr;
//    node* current = getRoot();
//
//    while (current != nullptr && current->getKey() != key) {
//        parent = current;
//        if (key < current->getKey()) {
//            current = current->getLeft();
//        }
//        else {
//            current = current->getRight();
//        }
//    }
//
//    if (current == nullptr) {
//        return false;
//    }
//
//    if (current->getLeft() == nullptr && current->getRight() == nullptr) {
//        if (current != getRoot()) {
//            if (parent->getLeft() == current) {
//                parent->setLeft(nullptr);
//            }
//            else {
//                parent->setRight(nullptr);
//            }
//        }
//        else {
//            setRoot(nullptr); 
//        }
//        delete current;
//    }
//   
//    else if (current->getLeft() == nullptr || current->getRight() == nullptr) {
//        node* child = (current->getLeft() != nullptr) ? current->getLeft() : current->getRight();
//
//        if (current != getRoot()) {
//            if (parent->getLeft() == current) {
//                parent->setLeft(child);
//            }
//            else {
//                parent->setRight(child);
//            }
//        }
//        else {
//            setRoot(child); 
//        }
//        delete current;
//    }
//  
//    else {
//       
//        node* successor = findMin(current->getRight());
//
//        
//        current->setKey(successor->getKey());
//
//        
//        deleteNodeRec(current->getRight(), successor->getKey());
//    }
//
//    return true; 
//}
//
//int binarySearchTree::getNodeLevel(int key)  {
//    return findNodeLevel(getRoot(), key, 0); 
//}
//
//int binarySearchTree::findNodeLevel(node* root, int key, int level)  {
//    if (root == nullptr) {
//        return -1;
//    }
//
//    if (root->getKey() == key) {
//        return level; 
//    }
//
//    
//    int leftLevel = findNodeLevel(root->getLeft(), key, level + 1);
//    if (leftLevel != -1) {
//        return leftLevel; 
//    }
//
//   
//    return findNodeLevel(root->getRight(), key, level + 1);
//}
//
//
//binarySearchTree& binarySearchTree::operator=(const binarySearchTree& other) {
//    if (this != &other) { 
//        deleteTree(); 
//        m_root = copyTree(other.m_root); 
//    }
//    return *this;
//}
//
//
//binarySearchTree* binarySearchTree::copySubTree(int key) {
//    node* subRoot = search(m_root, key);
//
//    if (subRoot == nullptr) {
//        std::cerr << "Error: node with key " << key << " not found" << std::endl;
//        return new binarySearchTree(); 
//    }
//
//    binarySearchTree* newTree = new binarySearchTree();
//    newTree->setRoot(copy(subRoot)); 
//    return newTree;
//}