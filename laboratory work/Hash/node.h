#pragma once
#include<string>
class node
{
public:
	node();
	~node();

	int getKey();
	const int getKey() const;

	std::string getValue();
	const std::string getValue() const;

private:
	int m_key;
	node* m_next;
	std::string m_value;
};

