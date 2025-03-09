#include<iostream>
#include"binarySearchTree.h"



int main()
{
	binarySearchTree tree;

	for (int i = 0; i < 10; ++i)
		tree.insert(9);
	tree.show();
	for (int i = 0; i < 10; ++i)
		tree.deleteNode(9);
	std::cout << "amount : " <<  tree.getAmountOfNodes();
	tree.show();


	return 0;
}