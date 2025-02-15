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
    int findNodeLevel(node* root, int key, int level) const;
    int findNodeLevel(int key) const;
    int getMin() const;
    int getMax() const;

    void setRoot(node* newRoot);
    void show(node* root, int space = 0, int indent = 4);
    void printLeafs(node* newNode);
    void deleteTree();
    void deleteSubTree(node* newNode);
    void insert(int key);
    void insertRandom(int key);
    void printCurrentLevel(node* root, int level);
    void printByLevels();
    void inOrderTraversal(node* root, std::vector<int>& keys);

    node* search(node* root, int key);
    node* insertRec(node* newNode, int value);
    node* getRoot();
    node* insertRandomRec(node* newNode, int key);

   
    bool isEmpty() ;
    bool deleteNode(int key);
    bool isBalanced(node* root) ;
    bool isBalanced() ;

    std::vector<int> getSortedKeys();


    binaryTree* copySubTree(int key);
    node* copy(node* currentNode);

    binaryTree& operator=(const binaryTree& other);
private:
    node* m_root;
    node* deleteNodeRec(node* root, int key);
    node* findMin(node* root);
};


