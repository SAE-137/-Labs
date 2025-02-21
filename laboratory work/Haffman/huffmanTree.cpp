#include "huffmanTree.h"
#include<iostream>

Node::Node()
{

}

int Node::getFrequency()
{
	return m_frequency;
}

void Node::setFrequensy(int frequency)
{
	m_frequency = frequency;
}

void Node::getSimbol()
{
     m_simbols.show();
}

void Node::setBoolVector(boolVector simbols)
{
	m_simbols = simbols;
}

void Node::setNext(Node* otherNode)
{
	next = otherNode;
}

Node* Node::getNext()
{
	return next;
}

huffmanTree::huffmanTree(std::string txt)
{

}

huffmanTree::huffmanTree()
{
    root = nullptr;
    head = nullptr;
}

huffmanTree::~huffmanTree()
{

}


void huffmanTree::insert(Node* node) {
    Node** p = &front_;

    while (*p != nullptr && (*p)->frequency < node->frequency)
    {
        p = &(*p)->next;
    }

    node->next = *p;

    *p = node;
}


void huffmanTree::build(const std::string text) {
   
    deleteTree(root);
    root = nullptr;
    codes.clear();

   
    std::unordered_map<char, int> frequencies;
    for (char ch : text) {
        frequencies[ch]++;
    }

    
    root = buildTree(frequencies);

   
    buildCodes(root, "");
}





void huffmanTree::testShow()
{
    head->getSimbol();
    node* newNode = new node;
    newNode = head;
    while (newNode->getNext())
    {
        newNode->getSimbol();
        newNode = newNode->getNext();
    }
    return;
}

node* huffmanTree::getHead()
{
	return head;
}

