#include <iostream>

#include "binaryTree.h"
#include "node.h"





int main()
{
	
	int n;
	int newn;

	

		std::cin >> n;

		binaryTree testTree;

		for (int i = 0; i < n; ++i)
		{
			testTree.insert(rand() % 1000);
		}
		testTree.show(testTree.getRoot());

		for (int i = 0; i < 4; ++i)
		{
			std::cout << std::endl;
		}
		
		std::cout << "--> " <<testTree.getAmountOfNodes(testTree.getRoot());
	
	
	
	
	return 0;
}