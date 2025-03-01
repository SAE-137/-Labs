#pragma once

#include "BinaryTreeTester.h"

class SearchTreeTester : public BinaryTreeTester
{
public:
    SearchTreeTester(const bool useConsoleOutput, const bool enableAllTests = true);
    ~SearchTreeTester() override = default;


    binaryTree* allocateTree() override;
    void check_addAndCount(const binaryTree* tree, const int size) override;
    void check_remove(binaryTree* tree, const int key,
        const bool result, const int size) override;
    void check_clear(const binaryTree* tree, const int size) override;
    void check_assign(const binaryTree* first,
        const binaryTree* second) override;

    void assign() override;
private:
    bool isSearchTree(const binaryTree* tree);
    void treeKeysLnr(node* root, std::vector<int>& keys);
};