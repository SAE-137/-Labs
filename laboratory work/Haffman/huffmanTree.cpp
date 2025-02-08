#include "huffmanTree.h"
#include<iostream>

node::node()
{

}

int node::getFrequency()
{
	return m_frequency;
}

void node::setFrequensy(int frequency)
{
	m_frequency = frequency;
}

void node::getSimbol()
{
     m_simbols.show();
}

void node::setBoolVector(boolVector simbols)
{
	m_simbols = simbols;
}

void node::setNext(node* otherNode)
{
	next = otherNode;
}

node* node::getNext()
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


void huffmanTree::insert(boolVector vector, int frequency) {
    node* newNode = new node;

   
    
    newNode->setBoolVector(vector);
    newNode->setFrequensy(frequency);

   
    if (this->getHead() == nullptr) {
        head = newNode;
        return;
    }

   
    if (newNode->getFrequency() < head->getFrequency()) {
        newNode->setNext(head);
        head = newNode;
        return;
    }

    node* otherNode = head;
    while (otherNode->getNext() != nullptr && otherNode->getNext()->getFrequency() <= newNode->getFrequency()) {
        otherNode = otherNode->getNext();
    }

   
    newNode->setNext(otherNode->getNext());
    otherNode->setNext(newNode);
}

void huffmanTree::build(const std::string txt)
{

    for (uint8_t ch : txt) {
		insert(ch, 1);
        
	}
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

