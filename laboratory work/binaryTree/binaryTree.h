#pragma once
#include "node.h"
#include<vector>

class binaryTree {
public:
    binaryTree();
    ~binaryTree();

    int getAmountOfNodes(node* newNode);
    int getNodeLvl(int key); 
    int getDepth(node* newNode);
    int findNodeLevel(node* root, int key, int level);
    int findNodeLevel(int key);
    int getMin();
    int getMax();

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

    node* copy(node* currentNode);
    binaryTree* copy(binaryTree* newTree);
    bool isEmpty();
    bool deleteNode(int key);
    bool isBalanced(node* root);
    bool isBalanced();

    std::vector<int> getSortedKeys();

private:
    node* m_root;
    node* deleteNodeRec(node* root, int key);
    node* findMin(node* root);
};


/*- конструкторы (по умолчанию, копирования);




- копирование поддерева узла (возвращает новый объект класса);








- получение вектора (std::vector<int>), содержащего все ключи дерева по возрастанию (обход вершин производить любым способом);

- оператор присваивания.*/