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

huffmanTree::~huffmanTree()
{

}


void huffmanTree::insert(std::string simbol, int frequency)
{
	if (this->getHead() == nullptr)
	{
		node* newNode = new node;
		boolVector vector(simbol);
		newNode->setBoolVector(vector);
		newNode->setFrequensy(frequency);
		head = newNode;
		return;
	}
	node* newNode = new node;
	boolVector vector(simbol); // 2 7 5
	newNode->setBoolVector(vector);
	newNode->setFrequensy(frequency);
	if (newNode->getFrequency() < head->getFrequency())
	{
		
		newNode->setNext(head);
		head = newNode;
		return;
	}
	node* otherNode = head;
	while (otherNode->getNext()->getFrequency() > newNode->getFrequency())
	{
		if (newNode->getFrequency() <= otherNode->getFrequency())
		{
			newNode->setNext(otherNode->getNext());
			otherNode->setNext(newNode);
			return;
		}
		if (otherNode->getNext() == nullptr)
		{
			otherNode->setNext(newNode);
			return;
		}

		otherNode = otherNode->getNext();
	}

}

void huffmanTree::build(const std::string& txt)
{
	for (int i = 0; i < txt.size(); i++)
	{

	}
}

node* huffmanTree::getHead()
{
	return head;
}

