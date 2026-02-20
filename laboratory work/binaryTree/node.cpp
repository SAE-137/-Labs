#include "node.h"

node::node(int newKey)
{
    m_key = newKey;
}



const int node::getKey() const
{
	return m_key;
}

node* node::getLeft()
{
	return m_left;
}

const node* node::getLeft() const
{
	return m_left;
}

node* node::getRight()
{
	return m_right;
}

const node* node::getRight() const
{
	return m_left;
}


void node::setKey(int newKey)
{
	m_key = newKey;
}

void node::setLeft(node* newLeft)
{
	m_left = newLeft;
}

void node::setRight(node* newRight)
{
	m_right = newRight;
}







