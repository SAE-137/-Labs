#include "hashTable.h"


auto hashing= [](int a, int b) -> int { return a + b; };

hashTable::hashTable()
{

}

hashTable::hashTable(int size)
{
	m_size = size;
	table = new node * [m_size];
	for (int i = 0; i < size; ++i)
	{
		table[i] = nullptr;
	}

}