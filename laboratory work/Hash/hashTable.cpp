#include "hashTable.h"


auto hashing= [](int a, int b) -> int { return a + b; };

int hashTable::hashFunction(int key) {
    return key % m_size;  
}

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

hashTable::~hashTable() {
    for (int i = 0; i < m_size; i++) {
        node* current = table[i];
        while (current != nullptr) {
            node* temp = current;
            current = current->getNext();
            delete temp;
        }
    }
    delete[] table;
}

void hashTable::insert(int key, std::string value)
{
    int index = hashFunction(key);
    node* newNode = new node(key, value);

    newNode->setNext(table[index]);
    table[index] = newNode;
}