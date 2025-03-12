#include<iostream>
#include "hashTable.h"


int main() {
    hashTable ht(5);
    ht.setHashFunction(3);
    ht.insert(0, "apple");
    ht.insert(1, "banana");
    ht.insert(2, "cherry");
    ht.insert(3, "apple");
    ht.insert(4, "banana");
    ht.insert(5, "cherry");
    ht.insert(6, "apple");
    ht.insert(7, "banana");
    ht.insert(8, "cherry");

    ht.printTable();

    
    
    return 0;
}