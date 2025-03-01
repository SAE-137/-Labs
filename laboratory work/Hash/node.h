#pragma once
#include<string>
class node
{
public:
	node();
	node(int key, std::string value);
	~node();

	
	int getKey() const;

	
	node* getNext();
	node* getNext() const;


	void setNext(node* next);

	std::string& getValueRef();

	std::string getValue();
	const std::string getValue() const;

private:
	int m_key;
	node* m_next;
	std::string m_value;
};

