#include "huffmanTree.h"

huffman::huffman()
{
    m_head = nullptr;
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

