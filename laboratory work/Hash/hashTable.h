#pragma once
#include"node.h"


class hashTable
{
public:
	hashTable();
	hashTable(int size);
	~hashTable();


private:
	int m_size;
	node** table;

};

