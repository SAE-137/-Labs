#pragma once
#include "node.h"
#include<vector>

class binaryTree {
public:
    binaryTree();
    binaryTree(const binaryTree& other);
    virtual ~binaryTree();

    int getAmountOfNodes(node* newNode) const;
    int getAmountOfNodes() const;
    virtual int getNodeLvl(int key) const;
    int getDepth(node* newNode) const;
    int getDepth() const;
    int findNodeLevel(node* root, int key, int level) const;
    int findNodeLevel(int key) const;
    virtual int getMin() const; 
    virtual int getMax() const; 
    int getMin(node* root) const;
    int getMax(node* root) const;

    void test();

    void setRoot(node* newRoot);
    void show(node* root, int space = 0, int indent = 4) const;
    void show();
    void printLeafs() const;
    void deleteTree();
    void printCurrentLevel(node* root, int level) const;
    void printByLevels() const;
    void inOrderTraversal(node* root, std::vector<int>& keys) const;
    virtual void insert(int key);
    
    node* search(int key) const;
    node* getRoot() const; 
    node* findParent(node* root, node* currentNode) const;
    node* findParent(node* currentNode) const;
    node* deleteNodeRec(node* root, int key);
    virtual node* deleteNode(node* root, node* currentNode);
    virtual node* deleteNode(node* currentNode);
    node* findMin(node* root); //TODO
    node* find(node* root, int key) const;
    node* find(int key) const;
   
    bool isEmpty() const;
    bool isBalanced(node* root) const;
    bool isBalanced() const;
    virtual bool deleteNode(int key) ;

    virtual std::vector<int> getSortedKeys() const;


    
    virtual binaryTree& operator=(const binaryTree& other);

    binaryTree copy() const; 
    binaryTree copy(node* root) const; 

protected:
    binaryTree* newTree();

    virtual node* insert(node* newNode, int key);
    node* _copy(node* currentNode) const;
    node* _copy() const; 
    virtual node* search(node* root, int key) const;

    void deleteTree(node* newNode);
    void printLeafs(node* newNode) const;

protected:
    node* m_root;

    
};


