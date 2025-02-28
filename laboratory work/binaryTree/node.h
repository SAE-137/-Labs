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


	const int getKey() const;

	node* getRight();
	const node* getRight() const;

	node* getLeft();
	const node* getLeft() const;


	int m_key = 0;
	node* m_left;
	node* m_right;
	int height;
private:
	

	
};

