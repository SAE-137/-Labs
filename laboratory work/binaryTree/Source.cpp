#include <iostream>
#include<random>
#include<vector>



#include "searchTreeTester.h"
#include "binaryTreeTester.h"
#include "binarySearchTree.h"


int randomValue(int min = 0, int max = 1000)
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

	binarySearchTree tree;
	tree.insert(1);
	tree.show();

	return 0;

}



