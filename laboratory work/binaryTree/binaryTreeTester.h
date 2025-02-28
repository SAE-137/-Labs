#pragma once
#include<vector>
#include"binaryTree.h"


#include <vector>
#include "BinaryTree.h"

class BinaryTreeTester
{
public:
    BinaryTreeTester(const bool useConsoleOutput, const bool enableAllTests = true);
    virtual ~BinaryTreeTester() = default;

    void test(const int size);

    bool useConsoleOutput() const;
    bool addAndCountCheckEnabled() const;
    bool destructorCheckEnabled() const;
    bool removeCheckEnabled() const;
    bool clearCheckEnabled() const;
    bool assignCheckEnabled() const;
    bool heightCheckEnabled() const;

    void setUseConsoleOutput(const bool enabled);
    void setAddAndCountCheckEnabled(const bool enabled);
    void setDestructorCheckEnabled(const bool enabled);
    void setRemoveCheckEnabled(const bool enabled);
    void setClearCheckEnabled(const bool enabled);
    void setAssignCheckEnabled(const bool enabled);
    void setHeightCheckEnabled(const bool enabled);

protected:
    using TreeNodes = std::vector<node*>;

protected:
    int invalidKey() const;

    virtual binaryTree* allocateTree();
    virtual void check_addAndCount(const binaryTree* tree, const int size);
    virtual void check_remove(binaryTree* tree, const int key,
        const bool result, const int size);
    virtual void check_clear(const binaryTree* tree, const int size);
    virtual void check_assign(const binaryTree* first,
        const binaryTree* second);
    virtual void check_height(const binaryTree& tree, const int size);

protected:
    virtual void assign();
    std::vector<int> generateKeys();
    int m_maxSize;

private:
    void deallocateTree(binaryTree* tree);
    void addAndCount();
    void destructor();
    void remove();
    void clear(); //ToDo: реализовать
    void height();
    void height_trivialCases();
    void height_longOnlyLeftSubtree();
    void height_longOnlyRightSubtree();
    void height_longOnlyLeftAndRightSubtrees();
    void height_longRandomZigzagSubtrees();
    TreeNodes treeNodes(const binaryTree* tree);

private:
    bool m_useConsoleOutput;
    bool m_addAndCountCheckEnabled;
    bool m_destructorCheckEnabled;
    bool m_removeCheckEnabled;
    bool m_clearCheckEnabled;
    bool m_assignCheckEnabled;
    bool m_heightCheckEnabled;
};