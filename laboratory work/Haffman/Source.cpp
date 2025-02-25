
#include<iostream>
#include"huffmanTree.h"
#include "bit_array.h"
#include <iostream>
#include <fstream>








int main() {
    std::string text = "bfdbgb";

    huffman huff;
    huff.build(text);

    std::cout << "Huffman Tree:" << std::endl;
    huff.printTree(huff.getHead());

    std::cout << "\nCharacter Codes:" << std::endl;
    huff.printCodes();

    BitVector encoded = huff.encode(text);

    std::cout << "\nEncoded bit sequence: ";
    encoded.print();

    return 0;
}
