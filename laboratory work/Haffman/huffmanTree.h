
#include"Node.h"
#include"bit_array.h"
#include<iostream>
#include <unordered_map>
#include <string>

class huffman
{
public:

	huffman();

	void build(std::string str);
	void buildHuffmanTree();
	
	void generateCodes(node* root, BitArray& code, std::unordered_map<char, BitArray>& codes);
	BitArray encode(const std::string& str);
	void printTree(node* root, int depth = 0);

	node* getHead();

	void printLists();


private:
	void insert(int frequency, const char ch);
	node* m_head;
};
