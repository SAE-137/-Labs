
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
	void generateCodes(node* root, BitVector& code, std::unordered_map<char, BitVector>& codes);
	void encodeToFile(const std::string& inputFile, const std::string& outputFile);
	void decodeFromFile(const std::string& encodedFile, const std::string& outputFile);
	void printTree(node* root, int depth = 0) const;
	void printLists() const;
	void printCodes();
	void printTree() const;

	std::string decode(BitVector& encodedBits);

	BitVector encode(const std::string& str);

	node* getHead() const;


private:
	void clear(node* root);
	void insert(int frequency, const char ch);
	node* m_head;
};
