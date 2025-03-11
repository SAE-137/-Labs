#include<iostream>
#include "hashTable.h"


int main() {
    hashTable ht(10);

    ht.insert(0, "apple");
    ht.insert(7, "banana");
    ht.insert(35, "cherry");
    ht.insert(12, "apple");
    ht.insert(23, "banana");
    ht.insert(37, "cherry");
    ht.insert(11, "apple");
    ht.insert(8, "banana");
    ht.insert(137, "cherry");

    ht.printTable();

    
    
    return 0;
}