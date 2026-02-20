#include <iostream>
#include<random>
#include<vector>




#include "binaryTreeTester.h"



int randomValue(int min = 0, int max = 100)
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


void printVector(const std::vector<int>& array) {
	for (int value : array) {
		std::cout << value << " ";
	}
	std::cout << std::endl;
}



void error()
{
	std::cout << "ERROR " << std::endl;
}



int main()
{	
	
	binaryTree bt;
	int amount = 50;
	std::vector<int> keys;
	int iteration = 0;
	while (iteration != 1)
	{
		iteration++;
		for (int i = 0; i < amount; ++i)
		{
			keys.push_back(randomValue(0, 1000));
			bt.insert(keys[i]);
		}
		std::sort(keys.begin(), keys.end());
		//printVector(keys);
		//

		//	for (int i = 0; i < amount; ++i)
		//		std::cout << bt.getSortedKeys().operator[](i) << " ";
		//	space(1);

		//std::cout << "min : " << bt.getMin() << std::endl;
		
		//std::cout << "min node : " << bt.findMin(bt.getRoot())->getKey();

		printVector(keys);
		space(2);
		bt.show();
		space(2);
		bt.printLeafs();
		space(2);
		


		keys.clear();
		bt.~binaryTree();
		//std::cout << "iteration - > " << iteration << std::endl;
	}
	return 0;
}



