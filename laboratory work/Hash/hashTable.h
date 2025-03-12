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
	void setHashFunction(int choice);

	std::string search(int key) const;
	
	node* getBucket(int key) const;
	int getSize() const;
	int computeHash(int key) const;

	bool isEmpty(int key) const;

	std::string& operator[](int key) const;
	hashTable& operator=(const hashTable& other);
private:
	int hashFunction_1(int key) const;
	int hashFunction_2(int key) const;
	int hashFunction_3(int key) const;
	int (hashTable::* hashFunc)(int) const;


private:
	int m_size;
	node** table;

};

