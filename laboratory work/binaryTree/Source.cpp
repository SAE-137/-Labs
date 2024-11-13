#include <iostream>

#include "binaryTree.h"
#include "node.h"



void space(int amount)
{
	for (int i = 0; i < amount; ++i)
	{
		std::cout << std::endl;
	}
}

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
		while (true)
		{
			space(3);
			std::cin >> n;
			testTree.search(testTree.getRoot(), n)->setKey(137);
			testTree.show(testTree.getRoot());
			if (n == -1) break;
		}
	
	
	
	
	return 0;
}