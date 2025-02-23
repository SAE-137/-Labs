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

	int getKey() const;

 node* getRight();
 node* getLeft();

 const node* getRight() const;


	int m_key = 0;
	node* m_left;
	node* m_right;
	int height;
private:
	

	
};

