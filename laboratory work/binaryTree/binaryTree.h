#pragma once
#include "node.h"
#include<vector>

class binaryTree {
public:
    binaryTree();
    binaryTree(const binaryTree& other);
    ~binaryTree();



    int getAmountOfNodes(node* newNode) const;
    int getNodeLvl(int key) const;
    int getDepth(node* newNode) const;
    int getDepth() const;
    int findNodeLevel(node* root, int key, int level) const;
    int findNodeLevel(int key) const;

    virtual int getMin() const;
    virtual int getMax() const;

    void test();

    void setRoot(node* newRoot);
    void show(node* root, int space = 0, int indent = 4) const;
    void printLeafs(node* newNode) const;
    void printLeafs() const;

   
    void deleteTree(node* newNode);
    void deleteTree();

    virtual void insert(int key);
    void insertRandom(int key);
    void printCurrentLevel(node* root, int level);
    void printByLevels();
    void inOrderTraversal(node* root, std::vector<int>& keys);

    virtual node* search(node* root, int key);
    node* insertRec(node* newNode, int value);

    
    node* getRoot() const;
    
    node* insertRandomRec(node* newNode, int key);
    node* findParent(node* root, node* currentNode) const;
    node* findParent(node* currentNode) const;
   
    bool isEmpty() const;
    virtual bool deleteNode(int key);
    bool isBalanced(node* root) const;
    bool isBalanced() const;

    std::vector<int> getSortedKeys();


    virtual binaryTree* copySubTree(int key);
    
    node* deleteNodeRec(node* root, int key);
    node* findMin(node* root);

    virtual binaryTree& operator=(const binaryTree& other);

    binaryTree clone() const; //TODO
    binaryTree clone(node* root) const; //TODO

protected:
    binaryTree* newTree();

    node* copy(node* currentNode) const;
    node* copy() const; //TODO

protected:
    node* m_root;

    
};


