#pragma once
#include "bit_array.h"
class node
{
public:

	node();
	~node();

	void setNext(node* newNode);
	void setFrequency(int frequency);
	void setSimbols(const char* ch);
	void setLeft(node* left);
	void setRight(node* right);

	int getFrequency();

	node* getLeft();
	node* getRight();
	node* getNext();



private:

	BitArray* m_simbols;
	node* m_next;
	int m_frequency;
	node* m_left;  
	node* m_right;
};

