
#include"Node.h"
#include"bit_array.h"
#include<iostream>
#include <unordered_map>
#include <string>

class huffman
{
public:

	huffman();
	~huffman();

	void build(std::string str);
	void buildHuffmanTree();
	std::string decode(BitVector& encodedBits);
	
	void generateCodes(node* root, BitVector& code, std::unordered_map<char, BitVector>& codes);
	void encodeToFile(const std::string& inputFile, const std::string& outputFile);
	void decodeFromFile(const std::string& encodedFile, const std::string& outputFile);
	void printTree(node* root, int depth = 0);
	BitVector encode(const std::string& str);
	node* getHead();

	void printLists();
	void printCodes();

	void printTree();
	std::string decode(const BitVector& encodedBits);

private:
	void clear(node* root);
	void insert(int frequency, const char ch);
	node* m_head;
};
