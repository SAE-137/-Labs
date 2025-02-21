#include <iostream>
#include<random>
#include "binaryTree.h"
#include "node.h"
#include<vector>
#include "binarySearchTree.h"
#include "AVLTree.h"


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

int main()
{
	int amount = 20;
	AVLTree at;
	binarySearchTree bst;

	for (int i = 0; i < amount; ++i)
	{
		int value = randomValue(0, 1000);
		bst.insert(value);
		at.insert(value);
	}
	

	if (!bst.isEmpty()) {
		bst.show(bst.getRoot());
	}
	else {
		std::cout << "The tree is empty." << std::endl;
	}

	space(5);

	if (!at.isEmpty()) {
		at.show(at.getRoot());
	}
	else {
		std::cout << "The tree is empty." << std::endl;
	}


}


