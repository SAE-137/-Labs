#pragma once
#include"node.h"


class hashTable
{
public:
	hashTable();
	hashTable(int size);
	~hashTable();

	void insert(int key, std::string value);

private:
	int hashFunction(int key);


private:
	int m_size;
	node** table;

};

