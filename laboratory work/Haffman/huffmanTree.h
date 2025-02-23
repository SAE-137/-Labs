
#include"Node.h"
#include"bit_array.h"
#include<iostream>

class huffman
{
public:

	huffman();

	void build(std::string str);


private:
	void insert(int frequency, const char* ch);
	node* m_head;
};
