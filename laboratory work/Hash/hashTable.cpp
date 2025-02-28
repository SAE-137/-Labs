#include<stdexcept>
#include<iostream>
#include "hashTable.h"



auto hashing= [](int a, int b) -> int { return a + b; };

int hashTable::hashFunction(int key) const 
{
    return key % m_size;  
}

hashTable::hashTable()
{
    int m_size = 1;
    node** table = nullptr;
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

std::string hashTable::search(int key) const
{
    int index = hashFunction(key);
    node* current = table[index];

    while (current != nullptr) {
        if (current->getKey() == key) {
            return current->getValue();
        }
        current = current->getNext();
    }
    return "";
}

void hashTable::remove(int key) 
{
    int index = hashFunction(key);
    node* current = table[index];
    node* prev = nullptr;

    while (current != nullptr) {
        if (current->getKey() == key) {
            if (prev == nullptr) {
                
                table[index] = current->getNext();
            }
            else {
               
                prev->setNext(current->getNext());
            }

            delete current; 
            return;
        }
        prev = current;
        current = current->getNext();
    }

    return;
    //throw std::runtime_error("Key not found");
}

void hashTable::printTable() const
{
    for (int i = 0; i < m_size; i++) {
        std::cout << "[" << i << "]: "; 

        node* current = table[i]; 
        while (current != nullptr) {
            std::cout << "(" << current->getKey() << ", " << current->getValue() << ") -> ";
            current = current->getNext(); 
        }

        std::cout << "nullptr" << std::endl; 
    }
}

bool hashTable::isEmpty(int key) const
{
    if (search(key) == "") return true;
    return false;
}