#include <iostream>
#include <assert.h>
#include <vector>
#include <ctime>  
#include "binarySearchTree.h"
#include "SearchTreeTester.h"

void check_remove(binaryTree* tree, const int key, const bool result, const int size)
{
   
    assert(tree->deleteNode(key) == result);
    assert(tree->getAmountOfNodes() == size);
}

int invalidKey()
{
    return -1000;  
}

std::vector<int> generateKeys()
{
    std::vector<int> orderedKeys;
    for (int i = 0; i < 10; ++i) {
        orderedKeys.push_back(i);
    }

    std::vector<int> keys;
    while (!orderedKeys.empty()) {
        int i = rand() % orderedKeys.size();
        keys.push_back(orderedKeys[i]);
        orderedKeys.erase(orderedKeys.begin() + i);
    }

    return keys;
}

void remove()
{
    binaryTree* tree = new binarySearchTree;  

    std::vector<int> nodeKeys = generateKeys();
    for (int i = 0; i < 10; ++i) {
        tree->insert(nodeKeys[i]);
    }
   
    while (!nodeKeys.empty()) {
        int removedNodeIndex = rand() % nodeKeys.size();
        std::cout << "amount : " << tree->getAmountOfNodes() << std::endl;
        std::cout << "nodeKeys.size() : " << nodeKeys.size() << std::endl;
        std::cout << "removedNodeIndex : " << removedNodeIndex << std::endl;
        tree->show();
        check_remove(tree, invalidKey(), false, nodeKeys.size());
        check_remove(tree, nodeKeys[removedNodeIndex], true, nodeKeys.size() - 1);
        nodeKeys.erase(nodeKeys.begin() + removedNodeIndex);

       
    }

   
    check_remove(tree, invalidKey(), false, nodeKeys.size());

    delete tree;  
}

#include<random>
int randomValue(int min = 0, int max = 10000)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);


    return dist(gen);

}

void space(int amount)
{
    for (int i = 0; i < amount; ++i)
        std::cout << std::endl;
}


int main() {
    binarySearchTree bt;
    int iteration = 0;
    while (iteration < 10)
    {
        iteration++;
        for (int i = 0; i < 40; ++i)
            bt.insert(randomValue(0, 1000));
        for (int i = 0; i < 40; ++i)
            std::cout << bt.getSortedKeys().operator[](i) << " ";
        space(1);
        std::cout << "min node : " << bt.findMin(bt.getRoot())->getKey() << std::endl;
        std::cout << "min : " << bt.getMin() << std::endl;
        std::cout << "max : " << bt.getMax() << std::endl;
       


        bt.deleteTree();
    }

    return 0;
}
