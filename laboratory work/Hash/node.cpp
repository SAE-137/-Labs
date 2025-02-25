#include "node.h"

node::node()
{
	m_next = nullptr;
	m_value = "";
}

node::node(int key, std::string value)
{
	m_key = key;
	m_value = value;
}

node::~node()
{

}
std::string node::getValue()
{
	return m_value;
}

const std::string node::getValue() const
{
	return m_value;
}

const int node::getKey() const
{
	return m_key;
}

int node::getKey()
{
	return m_key;
}



node* node::getNext()
{
	return m_next;
}

void node::setNext(node* next)
{
	m_next = next;
}

node* node::getNext() const
{
	return m_next;
}