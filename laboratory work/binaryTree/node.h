#pragma once
class node
{
public:
	node();
	node(int newKey);
	~node();


	void setKey(int newKey);
	void setLeft(node* newLeft);
	void setRight(node* newRight);

	int getKey();

	node* getRight();
	node* getLeft();

	int m_key = 0;
private:
	node* m_left;
	node* m_right;

	
};

