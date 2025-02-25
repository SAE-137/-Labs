
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
	
	void generateCodes(node* root, BitVector& code, std::unordered_map<char, BitVector>& codes);
	BitVector encode(const std::string& str);
	void printTree(node* root, int depth = 0);

	node* getHead();

	void printLists();
	void printCodes();


private:
	void insert(int frequency, const char ch);
	node* m_head;
};
