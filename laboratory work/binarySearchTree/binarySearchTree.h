

#include "C:\Users\admin\Desktop\Algorithms\-Labs\laboratory work\binaryTree\binaryTree.h"

class binarySearchTree : public binaryTree
{
public:
	binarySearchTree() : binaryTree() {}

protected:
	void insert(int key) override;

	int getMin() const override;
	int getMax() const override;

	void insert(int key) override;

	node* insertRec(node* node, int key);
private:
	node* m_root;
};

