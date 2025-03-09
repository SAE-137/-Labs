#include <iostream>
#include<random>
#include<vector>



#include "searchTreeTester.h"
#include "binaryTreeTester.h"
#include "binarySearchTree.h"


int randomValue(int min = 0, int max = 10000)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(min, max);

	
		return dist(gen);
	
}

void vectorShow(std::vector<int> sortedKeys)
{
	for (int key : sortedKeys)
		std::cout << key << " ";
}

void space(int amount)
{
	for (int i = 0; i < amount; ++i)
	{
		std::cout << std::endl;
	}
}

#include <iostream>
#include "SearchTreeTester.h"

#include <iostream>
#include "SearchTreeTester.h"

int main()
{
	int amount = 20;
	binaryTree tree;
	for (int i = 1; i <= amount; ++i)
	{
		tree.insert(i);
	}

	tree.show();
}



