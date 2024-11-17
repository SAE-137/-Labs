#pragma once
#include"boolVector.h"
#include<string>

class node
{
public:

	node();
	~node();
	void setFrequensy(int frequency);
	void setBoolVector(boolVector vector);
	void setNext(node* otherNode);
	
	node* getNext();

	int getFrequency();



private:
	int m_frequency = 1;
	boolVector m_simbols;
	node* left = nullptr;
	node* right = nullptr;
	node* next = nullptr;
};

class huffmanTree
{
public:
	

	huffmanTree(std::string txt);
	~huffmanTree();

	node* getHead();

	void build(const std::string &txt);
	void insert(std::string simbol, int frequensy);
private:
	
	node* root = nullptr;
	node* head = nullptr;
	
};

