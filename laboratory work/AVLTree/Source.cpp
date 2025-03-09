#include<iostream>
#include "AVLTree.h"



int main()
{

	AVLTree tree;
	
	for (int i = 0; i < 10; ++i)
		tree.insert(5);
	tree.show();
	std::cout << tree.getAmountOfNodes();


	return 0;
}