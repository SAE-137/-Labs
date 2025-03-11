#include <iostream>
#include<random>
#include<vector>




#include "binaryTreeTester.h"



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





int main()
{
	binaryTree bt;
	for (int i = 0; i < 10; ++i)
		bt.insert(randomValue(0, 100));
	for (int i = 0; i < 10; ++i)
		std::cout << bt.getSortedKeys().operator[](i) << " ";
	std::cout << "min : " << bt.getMin() << std::endl;
	std::cout << "max : " << bt.getMax() << std::endl;
	std::cout << "min node : " << bt.findMin(bt.getRoot())->getKey();

	return 0;
}



