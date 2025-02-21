#pragma once
#include"boolVector.h"
#include<string>

class Node
{
public:

	node();
	~node();
	void setFrequensy(int frequency);
	void setBoolVector(boolVector vector);
	void setNext(node* otherNode);
	void getSimbol();
	node* getNext();

	int getFrequency();



private:
	int m_frequency = 1;
	boolVector m_simbols;
	Node* left = nullptr;
	Node* right = nullptr;
	Node* next = nullptr;
};

class huffmanTree
{
public:
	
	huffmanTree();
	huffmanTree(std::string text);
	~huffmanTree();

	Node* getHead();

	void testShow();
	void build(const std::string txt);
	void insert(Node* node);
private:
	
	Node* root = nullptr;
	Node* head = nullptr;
	
};

