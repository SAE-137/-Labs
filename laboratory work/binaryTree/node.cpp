#include "node.h"



node::node()
{
	m_left = nullptr;
	m_right = nullptr;

	m_key = 0;
}

node::node(int newKey)
{
	m_key = newKey;
}

int node::get()
{
	return m_key;
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







