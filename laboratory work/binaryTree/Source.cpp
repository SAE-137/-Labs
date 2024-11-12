#include <iostream>
#include "binaryTree.h"
#include "node.h"





int main()
{
	
	int n;

	

		std::cin >> n;

		binaryTree testTree;

		for (int i = 0; i < n; ++i)
		{
			testTree.insert(rand() % 100);
		}
		testTree.show(testTree.getRoot());

		for (int i = 0; i < 4; ++i)
		{
			std::cout << std::endl;
		}

		testTree.deleteTree(testTree.getRoot()->getLeft());

		std::cout << " 555555";
	
	
	
	return 0;
}