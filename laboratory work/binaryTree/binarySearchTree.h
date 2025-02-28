//#pragma once
//
//#include "binaryTree.h"
//
//class binarySearchTree : public binaryTree
//{
//public:
//	binarySearchTree() : binaryTree() { }
//	~binarySearchTree();
//
//	binarySearchTree(const binarySearchTree& other);
//	
//
//	virtual void insert(int key) override;
//
//	int getMin()  override;
//	int getMax()  override;
//
//	node* search(node* root, int key) override;
//	node* search(int key);
//	node* copyTree(const node* root) ;
//		
//	virtual bool deleteNode(int key) override;
//
//	int getNodeLevel(int key) ;
//	int findNodeLevel(node* root, int key, int level) ;
//
//
//	virtual node* insertRec(node* node, int key);
//
//	binarySearchTree& operator=(const binaryTree& other) override;
//
//	binarySearchTree* copySubTree(int key) override;
//private:
//
//};
//
