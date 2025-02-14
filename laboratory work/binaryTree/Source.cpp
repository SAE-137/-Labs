#include <iostream>
#include<random>
#include "binaryTree.h"
#include "node.h"

int randomValue(int min = 0, int max = 1000)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(min, max);

	
		return dist(gen);
	
}

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
			testTree.insert(randomValue());
		}
		testTree.show(testTree.getRoot());

		
		space(5);

		std::cout << "max ->" << testTree.getMax();
	
	
	return 0;
}

