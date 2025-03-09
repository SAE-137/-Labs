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
	void printTable() const;

	std::string search(int key) const;
	
	node* getBucket(int key) const;
	int getSize() const;

	bool isEmpty(int key) const;

	std::string& operator[](int key) const;
	hashTable& operator=(const hashTable& other);
private:
	int hashFunction(int key) const;


private:
	int m_size;
	node** table;

};

