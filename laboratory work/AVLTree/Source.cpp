#include<iostream>
#include<vector>
#include "AVLTree.h"
#include<C:\Users\admin\Desktop\Algorithms\-Labs\laboratory work\binaryTree\binaryTreeTester.h>

void space(int amount)
{
	for (int i = 0; i < amount; ++i)
	{
		std::cout << std::endl;
	}
}

int main()
{
	std::vector<int> v = {79 ,56 ,77 ,63 ,19, 76 ,41 ,75 ,28 ,99, 57 ,24 ,78, 37 ,68 ,64 ,18 };
	AVLTree tree;
	
	for (int i = 0; i < 5; ++i)
	{
		tree.insert(v[i]);
	}

	
	//38 28 60 43 99 

	return 0;
}