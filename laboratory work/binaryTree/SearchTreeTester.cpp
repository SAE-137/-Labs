//#include <algorithm>
//#include <assert.h>
//#include <iostream>
//
//#include "binarySearchTree.h"
//
//#include "SearchTreeTester.h"
//
//SearchTreeTester::SearchTreeTester(const bool useConsoleOutput,
//    const bool enableAllTests)
//    : BinaryTreeTester(useConsoleOutput, enableAllTests)
//{}
//
//binaryTree* SearchTreeTester::allocateTree()
//{
//    return new binarySearchTree;
//}
//
//void SearchTreeTester::check_addAndCount(const binaryTree* tree, const int size)
//{
//    BinaryTreeTester::check_addAndCount(tree, size);
//    assert(isSearchTree(tree));
//}
//
//void SearchTreeTester::check_remove(binaryTree* tree, const int key,
//    const bool result, const int size)
//{
//    BinaryTreeTester::check_remove(tree, key, result, size);
//    assert(isSearchTree(tree));
//}
//
//void SearchTreeTester::check_clear(const binaryTree* tree, const int size)
//{
//    BinaryTreeTester::check_clear(tree, size);
//    assert(isSearchTree(tree));
//}
//
//void SearchTreeTester::check_assign(const binaryTree* first,
//    const binaryTree* second)
//{
//    BinaryTreeTester::check_assign(first, second);
//    assert(isSearchTree(first));
//    assert(isSearchTree(second));
//}
//
//
//void SearchTreeTester::assign()
//{
//    if (!assignCheckEnabled()) {
//        return;
//    }
//
//    binarySearchTree tree1;
//
//    std::vector<int> nodeKeys = generateKeys();
//    for (int i = 0; i < m_maxSize; ++i) {
//        tree1.insert(nodeKeys[i]);
//    }
//
//    binarySearchTree tree2 = tree1; //Конструктор копирования
//    check_assign(&tree1, &tree2);
//
//    tree1 = tree1; //Присваивание самому себе
//    check_assign(&tree1, &tree2); //Проверяем, что tree1 не сломалось
//
//    tree1 = tree2; //Присваивание одинаковых по размеру деревьев
//    check_assign(&tree1, &tree2);
//
//    binarySearchTree tree3;
//    tree1 = tree3; //Присваивание дерева меньшего размера
//    check_assign(&tree1, &tree3);
//
//    tree3 = tree2; //Присваивание дерева большего размера
//    check_assign(&tree2, &tree3);
//}
//
//bool SearchTreeTester::isSearchTree(const binaryTree* tree)
//{
//    if (useConsoleOutput()) {
//        tree->printByLevels();
//        std::cout << "======\n";
//    }
//    std::vector<int> keys;
//    treeKeysLnr(tree->getRoot(), keys);
//    return std::is_sorted(keys.begin(), keys.end());
//}
//
//void SearchTreeTester::treeKeysLnr(node* root, std::vector<int>& keys)
//{
//    if (!root) {
//        return;
//    }
//
//    treeKeysLnr(root->getLeft(), keys);
//    keys.push_back(root->getKey());
//    treeKeysLnr(root->getRight(), keys);
//}
