#include "Node.h"


node::node()
{
	m_frequency = 0;
	m_next = nullptr;
	m_simbols = nullptr;
}

node::~node()
{
	delete m_next;
}

node* node::getNext()
{
	return m_next;
}

int node::getFrequency()
{
	return m_frequency;
}

void node::setFrequency(int frequency)
{
	m_frequency = frequency;
}

void node::setNext(node* newNode)
{
	m_next = newNode;
}

void node::setSimbols(const char* ch)
{
	
}

void node::setLeft(node* left)
{
	m_left = left;
	
}

void node::setRight(node* right)
{
	m_right = right;
}

node* node::getLeft()
{
	return m_left;
}

node* node::getRight()
{
	return m_right;
}