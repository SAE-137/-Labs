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


	void setChar(char ch) { character = ch; }
	char getChar() const { return character; }
private:

	
	node* m_next;
	int m_frequency;

	char character;
	node* m_left;  
	node* m_right;
};

