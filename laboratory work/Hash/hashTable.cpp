#include <cmath>
#include<stdexcept>
#include<iostream>
#include "hashTable.h"



int hashTable::hashFunction_1(int key) const 
{
    int n = this->getSize();
    const int c = 3;
    const int d = 5;
    static int i = 0;
    static int prevH = key % n;

    if (i == 0) {
        i++;
        return prevH;
    }


    int currentH = (prevH + c * i + d * i * i) % n;

    prevH = currentH;
    i++;

    return currentH;
}

int hashTable::hashFunction_2(int key) const {
    int n = this->getSize();
    static int i = 0;
    static int prevH = key % n;

    if (i == 0) {
        i++;
        return prevH;
    }

    
    double a = -(1 - std::sqrt(5)) / 2;

   
    int currentH = static_cast<int>(prevH * a * n) % n;

    
    prevH = currentH;
    i++;

    return currentH;
}

int hashTable::hashFunction_3(int key) const {
    int n = this->getSize(); 
    static int i = 0; 
    static int prevH = key % n;

    if (i == 0) {
        i++;
        return prevH;
    }
   
    int h1 = (key % n + i * (1 + key % (n - 2))) % n;

    i++; 
    return h1; 
}

void hashTable::setHashFunction(int choice) {
    switch (choice) {
    case 1: hashFunc = &hashTable::hashFunction_1; break;
    case 2: hashFunc = &hashTable::hashFunction_2; break;
    case 3: hashFunc = &hashTable::hashFunction_3; break;
    default: hashFunc = &hashTable::hashFunction_1; 
    }
}

int hashTable::computeHash(int key) const {
    return (this->*hashFunc)(key); 
}

hashTable::hashTable()
{
    m_size = 1;
    table = nullptr;
    hashFunc = &hashTable::hashFunction_1;
}

hashTable::hashTable(int size)
{
	m_size = size;
	table = new node * [m_size];
	for (int i = 0; i < m_size; ++i)
	{
		table[i] = nullptr;
	}
    hashFunc = &hashTable::hashFunction_1;
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
    int index = computeHash(key);
    node* newNode = new node(key, value);

    newNode->setNext(table[index]);
    table[index] = newNode;
}

std::string hashTable::search(int key) const
{
    int index = computeHash(key);
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
    int index = computeHash(key);
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

int hashTable::getSize() const
{
    return m_size;
}

node* hashTable::getBucket(int key) const
{
    if (key >= 0 && key < getSize())
    {
        return table[key];
    }
    return nullptr;
}

hashTable& hashTable::operator=(const hashTable& other) {
    if (this == &other) {
        return *this; 
    }

   
    for (int i = 0; i < m_size; i++) {
        node* current = table[i];
        while (current != nullptr) {
            node* temp = current;
            current = current->getNext();
            delete temp;
        }
    }
    delete[] table;

   
    m_size = other.m_size;
    table = new node * [m_size];
    for (int i = 0; i < m_size; i++) {
        table[i] = nullptr;
    }

   
    for (int i = 0; i < m_size; i++) {
        node* current = other.table[i];
        while (current != nullptr) {
            insert(current->getKey(), current->getValue()); 
            current = current->getNext();
        }
    }

    return *this;
}

std::string& hashTable::operator[](int key) const{
    int index = computeHash(key);
    node* current = table[index];

   
    while (current != nullptr) {
        if (current->getKey() == key) {
            return current->getValueRef(); 
        }
        current = current->getNext();
    }

    
    node* newNode = new node(key, "");
    newNode->setNext(table[index]);
    table[index] = newNode;

    return newNode->getValueRef(); 
}
