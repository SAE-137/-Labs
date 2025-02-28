#include <iostream>
#include <fstream>
#include "huffmanTree.h"

huffman::huffman()
{
   
}

huffman::~huffman() {
    clear(m_head);
}

void huffman::clear(node* root) {
    if (root == nullptr) return;
    clear(root->getLeft());
    clear(root->getRight());
    delete root;
}

void huffman::insert(int frequency, char ch)
{
    node* newNode = new node;
    newNode->setFrequency(frequency);
    newNode->setChar(ch);
    newNode->setNext(nullptr);
    newNode->setLeft(nullptr);
    newNode->setRight(nullptr);

    if (m_head == nullptr || frequency < m_head->getFrequency())
    {
        newNode->setNext(m_head);
        m_head = newNode;
        return;
    }

    node* current = m_head;
    while (current->getNext() != nullptr && current->getNext()->getFrequency() < frequency)
    {
        current = current->getNext();
    }

    newNode->setNext(current->getNext());
    current->setNext(newNode);
}


void huffman::buildHuffmanTree()
{
    while (m_head != nullptr && m_head->getNext() != nullptr)
    {
       
        node* left = m_head;
        node* right = m_head->getNext();
        m_head = right->getNext(); 

        
        node* newNode = new node;
        newNode->setFrequency(left->getFrequency() + right->getFrequency());
        newNode->setLeft(left);
        newNode->setRight(right);
        newNode->setChar('\0'); 

        
        if (m_head == nullptr || m_head->getFrequency() >= newNode->getFrequency())
        {
            newNode->setNext(m_head);
            m_head = newNode;
        }
        else
        {
            node* current = m_head;
            while (current->getNext() != nullptr && current->getNext()->getFrequency() < newNode->getFrequency())
            {
                current = current->getNext();
            }
            newNode->setNext(current->getNext());
            current->setNext(newNode);
        }
    }
}

void huffman::printLists()
{
    node* current = m_head;
    while (current != nullptr) 
    {
        std::cout << current->getChar() << "(" << current->getFrequency() << ")" << std::endl;
        current = current->getNext();
    }
}



void huffman::build(std::string str)
{
    std::unordered_map<char, int> frequencyMap;
    for (char ch : str)
    {
        frequencyMap[ch]++;
    }

    for (const auto& pair : frequencyMap)
    {
        insert(pair.second, pair.first); 
       
    }

    buildHuffmanTree();
}

void huffman::printCodes() {
    std::unordered_map<char, BitVector> codes;
    BitVector code;
    generateCodes(m_head, code, codes);

    std::cout << "Huffman Codes:\n";
    for (const auto& pair : codes) {
        std::cout << "'" << pair.first << "' -> ";
        pair.second.print();
    }
}


void huffman::generateCodes(node* root, BitVector& code, std::unordered_map<char, BitVector>& codes) {
    if (root == nullptr) return;

    if (root->getLeft() == nullptr && root->getRight() == nullptr) {
        codes[root->getChar()] = code;
        return;
    }

    code.append(0);
    generateCodes(root->getLeft(), code, codes);
    code.pop();

    code.append(1);
    generateCodes(root->getRight(), code, codes);
    code.pop();
}

BitVector huffman::encode(const std::string& str) {
    std::unordered_map<char, BitVector> codes;
    BitVector code;

    node* root = m_head;
    while (root->getNext() != nullptr)
        root = root->getNext();

    generateCodes(root, code, codes);

    BitVector encodedBits;
    for (char ch : str) {
        for (int i = 0; i < codes[ch].size(); i++) {
            encodedBits.append(codes[ch][i]);
        }
    }

    return encodedBits;
}

void huffman::encodeToFile(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream in(inputFile);
    if (!in) {
        std::cerr << "ERROR " << inputFile << std::endl;
        return;
    }

    std::string text((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    in.close();

    
    build(text);
    BitVector encodedBits = encode(text);

   
    std::ofstream out(outputFile, std::ios::binary);
    if (!out) {
        std::cerr << "ERROR " << outputFile << std::endl;
        return;
    }

    
    int bitCount = encodedBits.size();
    out.write(reinterpret_cast<const char*>(&bitCount), sizeof(bitCount));

    
    for (size_t i = 0; i < encodedBits.size(); ++i) {
        uint8_t bit = encodedBits[i];
        out.write(reinterpret_cast<const char*>(&bit), sizeof(bit));
    }

    out.close();
    std::cout << "Endoded and wro " << outputFile << std::endl;
}

void huffman::decodeFromFile(const std::string& encodedFile, const std::string& outputFile) {
    std::ifstream in(encodedFile, std::ios::binary);
    if (!in) {
        std::cerr << "ERROR " << encodedFile << std::endl;
        return;
    }

    
    int bitCount;
    in.read(reinterpret_cast<char*>(&bitCount), sizeof(bitCount));

    BitVector encodedBits;
    for (int i = 0; i < bitCount; ++i) {
        uint8_t bit;
        in.read(reinterpret_cast<char*>(&bit), sizeof(bit));
        encodedBits.append(bit);
    }
    in.close();

    
    std::string decodedText = decode(encodedBits);

   
    std::ofstream out(outputFile);
    if (!out) {
        std::cerr << "ERROR " << outputFile << std::endl;
        return;
    }

    out << decodedText;
    out.close();
    std::cout << "Decoded and has been wroyen in file output.txt " << outputFile << std::endl;
}

node* huffman::getHead()
{
    return m_head;
}

void huffman::printTree(node* root, int depth )
{
    if (root == nullptr)
        return;

    
    printTree(root->getRight(), depth + 1);

    
    for (int i = 0; i < depth; i++)
        std::cout << "    "; 

    if (root->getChar() != '\0')
        std::cout << root->getChar() << " (" << root->getFrequency() << ")" << std::endl;
    else
        std::cout << "* (" << root->getFrequency() << ")" << std::endl; 

   
    printTree(root->getLeft(), depth + 1);
}

void huffman::printTree()
{
    printTree(getHead(), 0);
}

std::string huffman::decode(BitVector& encodedBits) {
    std::string result;
    node* current = m_head;

    for (size_t i = 0; i < encodedBits.size(); i++) {
        current = encodedBits[i] ? current->getRight() : current->getLeft();

        if (!current->getLeft() && !current->getRight()) {
            result += current->getChar();
            current = m_head;
        }
    }
    return result;
}
