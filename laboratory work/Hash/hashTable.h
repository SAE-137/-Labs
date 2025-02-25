#pragma once
#include"node.h"


class hashTable
{
public:
	hashTable();
	hashTable(int size);
	~hashTable();

	void insert(int key, std::string value);
	void remove(int key);
	void printTable();

	std::string search(int key);

	bool isEmpty(int key);

private:
	int hashFunction(int key);


private:
	int m_size;
	node** table;

};

