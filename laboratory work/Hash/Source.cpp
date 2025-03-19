#include<iostream>
#include "hashTable.h"


#include <iostream>
#include "hashTable.h"

int main() {
   
    hashTable table(10);

   
    

    
    table.insert(1, "1");
    table.insert(2, "2");
    table.insert(3, "3");
    table.insert(4, "4");
    table.insert(5, "5");
    table.insert(6, "6");
    table.insert(7, "7");
    table.insert(8, "8");
    table.insert(9, "9");
    table.insert(10, "10");

    for (int i = 0; i < 10; ++i)
    {
        table.remove(i + 1);
        std::cout << "deliting -> " << i+1 << std::endl;
        table.printTable();
    }

    return 0;
}
