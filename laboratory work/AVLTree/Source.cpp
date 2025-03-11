#include<iostream>
#include "AVLTree.h"
#include<C:\Users\admin\Desktop\Algorithms\-Labs\laboratory work\binaryTree\binaryTreeTester.h>


int main()
{

	AVLTree tree;
	
	for (int i = 0; i < 10; ++i)
		tree.insert(5);
	tree.show();
	std::cout << tree.getAmountOfNodes();


	return 0;
}