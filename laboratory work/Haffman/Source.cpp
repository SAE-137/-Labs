
#include<iostream>
#include"huffmanTree.h"
#include "bit_array.h"
#include <iostream>
#include <fstream>

int madin() {
    std::string input = "hell";

  
    huffman huff;

    

    
    BitArray encodedBits = huff.encode(input);

   
    std::ofstream outFile("encoded.bin", std::ios::binary);
    outFile << encodedBits;
    outFile.close();

    std::cout << "Исходная строка: " << input << std::endl;
    std::cout << "Закодированная строка: " << encodedBits << std::endl;

   

   

    


    return 0;
}

int main()
{
    BitArray a;
    a.addBit(0);
    a.addBit(0);
    a.addBit(1);
    
 

    std::cout << a;



    return 0;
}