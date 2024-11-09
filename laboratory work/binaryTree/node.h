#pragma once
class node
{
public:
	node();
	node(int newKey);


	void setKey(int newKey);
	void setLeft(node* newLeft);
	void setRight(node* newRight);

	int get();




private:
	node* m_left = nullptr;
	node* m_right = nullptr;

	int m_key = 0;
};

