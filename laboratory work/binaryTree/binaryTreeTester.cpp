#include <assert.h>
#include <iostream>
#include <stdlib.h>

#include "binaryTreeTester.h"



BinaryTreeTester::BinaryTreeTester(const bool useConsoleOutput,
    const bool enableAllTests)
    : m_useConsoleOutput(useConsoleOutput)
    , m_addAndCountCheckEnabled(enableAllTests)
    , m_destructorCheckEnabled(enableAllTests)
    , m_removeCheckEnabled(enableAllTests)
    , m_clearCheckEnabled(enableAllTests)
    , m_assignCheckEnabled(enableAllTests)
    , m_heightCheckEnabled(enableAllTests)
{}

void BinaryTreeTester::test(const int size)
{
    m_maxSize = size;

    addAndCount();
    destructor();
    remove();
    clear();
    assign();
    height();
}

bool BinaryTreeTester::useConsoleOutput() const
{
    return m_useConsoleOutput;
}

bool BinaryTreeTester::addAndCountCheckEnabled() const
{
    return m_addAndCountCheckEnabled;
}

bool BinaryTreeTester::destructorCheckEnabled() const
{
    return m_destructorCheckEnabled;
}

bool BinaryTreeTester::removeCheckEnabled() const
{
    return m_removeCheckEnabled;
}

bool BinaryTreeTester::clearCheckEnabled() const
{
    return m_clearCheckEnabled;
}

bool BinaryTreeTester::assignCheckEnabled() const
{
    return m_assignCheckEnabled;
}

bool BinaryTreeTester::heightCheckEnabled() const
{
    return m_heightCheckEnabled;
}

void BinaryTreeTester::setUseConsoleOutput(const bool enabled)
{
    m_useConsoleOutput = enabled;
}

void BinaryTreeTester::setAddAndCountCheckEnabled(const bool enabled)
{
    m_addAndCountCheckEnabled = enabled;
}

void BinaryTreeTester::setDestructorCheckEnabled(const bool enabled)
{
    m_destructorCheckEnabled = enabled;
}

void BinaryTreeTester::setRemoveCheckEnabled(const bool enabled)
{
    m_removeCheckEnabled = enabled;
}

void BinaryTreeTester::setClearCheckEnabled(const bool enabled)
{
    m_clearCheckEnabled = enabled;
}

void BinaryTreeTester::setAssignCheckEnabled(const bool enabled)
{
    m_assignCheckEnabled = enabled;
}

void BinaryTreeTester::setHeightCheckEnabled(const bool enabled)
{
    m_heightCheckEnabled = enabled;
}

int BinaryTreeTester::invalidKey() const
{
    return -(rand() % m_maxSize + 1);
}

binaryTree* BinaryTreeTester::allocateTree()
{
    return new binaryTree;
}

void BinaryTreeTester::deallocateTree(binaryTree* tree)
{
    delete tree;
}

void BinaryTreeTester::addAndCount()
{
    if (!m_addAndCountCheckEnabled) {
        return;
    }

    binaryTree* tree = allocateTree();
    check_addAndCount(tree, 0);

    std::vector<int> nodeKeys = generateKeys();
    for (int i = 0; i < m_maxSize; ++i) {
        tree->insert(nodeKeys[i]);
        check_addAndCount(tree, i + 1);
    }

    deallocateTree(tree);
}

void BinaryTreeTester::check_addAndCount(const binaryTree* tree, const int size)
{
    assert(tree->getAmountOfNodes() == size);
}

void BinaryTreeTester::destructor()
{
    if (!m_destructorCheckEnabled) {
        return;
    }

    const int runsCount = 200;
    for (int i = 0; i < runsCount; i++)
    {
        binaryTree* tree = allocateTree();
        std::vector<int> nodeKeys = generateKeys();
        for (int i = 0; i < m_maxSize; ++i) {
            tree->insert(nodeKeys[i]);
        }
        deallocateTree(tree);
    }
    std::cout << "BinaryTreeTester::destructor ended. Press any key to continue..." << std::endl;
    getchar(); // что это?

}

/*
 * [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
 * removedNodeIndex = 3
 * nodeKeys[removedNodeIndex] = 3
 *
 * [0, 1, 2, 4, 5, 6, 7, 8, 9]
 * removedNodeIndex = 4
 * nodeKeys[removedNodeIndex] = 5
 *
 * [0, 1, 2, 4, 6, 7, 8, 9]
 *
 */

void BinaryTreeTester::remove()
{
    if (!m_removeCheckEnabled) {
        return;
    }

    binaryTree* tree = allocateTree();
    check_remove(tree, invalidKey(), false, 0);

    std::vector<int> nodeKeys = generateKeys();
    for (int i = 0; i < m_maxSize; ++i) {
        tree->insert(nodeKeys[i]);
    }

    while (!nodeKeys.empty()) {
        int removedNodeIndex = rand() % nodeKeys.size();

        check_remove(tree, invalidKey(), false, nodeKeys.size());
        check_remove(tree, nodeKeys[removedNodeIndex], true, nodeKeys.size() - 1);
        nodeKeys.erase(nodeKeys.begin() + removedNodeIndex);

        if (m_useConsoleOutput) {
            tree->printByLevels();
        }
    }

    if (m_useConsoleOutput) {
        tree->printByLevels();
    }

    check_remove(tree, invalidKey(), false, nodeKeys.size());
    deallocateTree(tree);
}

void BinaryTreeTester::check_remove(binaryTree* tree, const int key,
    const bool result, const int size)
{
    assert(tree->deleteNode(key) == result);
    assert(tree->getAmountOfNodes() == size);
}

void BinaryTreeTester::clear()
{
    if (!m_clearCheckEnabled) {
        return;
    }

    binaryTree* tree = allocateTree();
    for (int i = 0; i < 200; i++)
    {
        std::vector<int> nodeKeys = generateKeys();
        for (int i = 0; i < m_maxSize; ++i) {
            tree->insert(nodeKeys[i]);
        }
        tree->deleteTree();
        check_clear(tree, 0);
    }
    deallocateTree(tree);
    std::cout << "BinaryTreeTester::clear ended. Press any key to continue..." << std::endl;
    getchar();
}

void BinaryTreeTester::check_clear(const binaryTree* tree, const int size)
{
    assert(tree->getAmountOfNodes() == size);
}

void BinaryTreeTester::assign()
{
    if (!m_assignCheckEnabled) {
        return;
    }

    binaryTree tree1;

    std::vector<int> nodeKeys = generateKeys();
    for (int i = 0; i < m_maxSize; ++i) {
        tree1.insert(nodeKeys[i]);
    }

    binaryTree tree2 = tree1; //Конструктор копирования
    check_assign(&tree1, &tree2);

    tree1 = tree1; //Присваивание самому себе
    check_assign(&tree1, &tree2); //Проверяем, что tree1 не сломалось

    tree1 = tree2; //Присваивание одинаковых по размеру деревьев
    check_assign(&tree1, &tree2);

    binaryTree tree3;
    tree1 = tree3; //Присваивание дерева меньшего размера
    check_assign(&tree1, &tree3);

    tree3 = tree2; //Присваивание дерева большего размера
    check_assign(&tree2, &tree3);
}

void BinaryTreeTester::check_assign(const binaryTree* first,
    const binaryTree* second)
{
    const int size = first->getAmountOfNodes();
    assert(size == second->getAmountOfNodes());

    TreeNodes firstTreeNodes = treeNodes(first);
    TreeNodes secondTreeNodes = treeNodes(second);

    for (int i = 0; i < size; ++i) {
        assert(firstTreeNodes[i] != secondTreeNodes[i]);
        assert(firstTreeNodes[i]->getKey() == secondTreeNodes[i]->getKey());
    }
}

BinaryTreeTester::TreeNodes BinaryTreeTester::treeNodes(const binaryTree* tree)
{
    TreeNodes nodes;

    TreeNodes nodesToProcess;
    nodesToProcess.push_back(tree->getRoot());
    while (!nodesToProcess.empty()) {
        node* newNode = nodesToProcess.front();
        if (newNode != nullptr) {
            nodesToProcess.push_back(newNode->getLeft());
            nodesToProcess.push_back(newNode->getRight());
            nodes.push_back(newNode);
        }
        nodesToProcess.erase(nodesToProcess.begin());
    }

    return nodes;
}

std::vector<int> BinaryTreeTester::generateKeys()
{
    std::vector<int> orderedKeys;
    for (int i = 0; i < m_maxSize; ++i) {
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

void BinaryTreeTester::height()
{
    if (!m_heightCheckEnabled) {
        return;
    }

    height_trivialCases();
    height_longOnlyLeftSubtree();
    height_longOnlyRightSubtree();
    height_longOnlyLeftAndRightSubtrees();
    height_longRandomZigzagSubtrees();
}

void BinaryTreeTester::check_height(const binaryTree& tree, const int height)
{
    assert(tree.getDepth() == height);
}

void BinaryTreeTester::height_trivialCases()
{
    binaryTree tree;
    check_height(tree, 0);
    tree.insert(0);
    check_height(tree, 1);
}

void BinaryTreeTester::height_longOnlyLeftSubtree()
{
    binaryTree longTree;
    longTree.insert(0);
    node* runner = longTree.getRoot();
    for (int i = 1; i < m_maxSize; ++i) {
        runner->setLeft(new node(i));
        runner = runner->getLeft();
        check_height(longTree, i + 1);
    }
}

void BinaryTreeTester::height_longOnlyRightSubtree()
{
    binaryTree longTree;
    longTree.insert(0);
    node* runner = longTree.getRoot();
    for (int i = 1; i < m_maxSize; ++i) {
        runner->setRight(new node(i));
        runner = runner->getRight();
        check_height(longTree, i + 1);
    }
}

void BinaryTreeTester::height_longOnlyLeftAndRightSubtrees()
{
    binaryTree longTree;
    longTree.insert(0);
    node* leftRunner = longTree.getRoot();
    node* rightRunner = longTree.getRoot();
    for (int i = 1; i < m_maxSize / 2; ++i) {
        leftRunner->setLeft(new node(i));
        leftRunner = leftRunner->getLeft();
        check_height(longTree, i + 1);

        rightRunner->setRight(new node(i));
        rightRunner = rightRunner->getRight();
        check_height(longTree, i + 1);
    }
}

void BinaryTreeTester::height_longRandomZigzagSubtrees()
{
    binaryTree longTree;
    longTree.insert(0);
    node* leftRunner = longTree.getRoot();
    node* rightRunner = longTree.getRoot();

    leftRunner->setLeft(new node(1));
    leftRunner = leftRunner->getLeft();
    rightRunner->setRight(new node(1));
    rightRunner = rightRunner->getRight();

    for (int i = 2; i < m_maxSize / 2; ++i) {
        if (rand() % 2 == 0)
        {
            leftRunner->setLeft(new node(i));
            leftRunner = leftRunner->getLeft();
        }
        else
        {
            leftRunner->setRight(new node(i));
            leftRunner = leftRunner->getRight();
        }
        check_height(longTree, i + 1);

        if (rand() % 2 == 0)
        {
            rightRunner->setLeft(new node(i));
            rightRunner = rightRunner->getLeft();
        }
        else
        {
            rightRunner->setRight(new node(i));
            rightRunner = rightRunner->getRight();
        }
        check_height(longTree, i + 1);
    }
}
