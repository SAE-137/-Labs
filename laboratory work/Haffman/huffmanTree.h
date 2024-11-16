#pragma once
#include"boolVector.h"
#include<string>

class huffmanTree
{
public:
	class node
	{
	public:

		node(boolVector simbols);
		~node();

	private:
		int frequency = 1;
		boolVector m_simbols;
		node* left = nullptr;
		node* right = nullptr;
	};

	huffmanTree();
	~huffmanTree();

	void build(const std::string &txt);


};

