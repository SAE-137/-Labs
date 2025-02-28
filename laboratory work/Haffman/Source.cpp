#include "huffmanTree.h"
#include <iostream>

int main() {
    huffman tree;

   
    tree.encodeToFile("input.txt", "output.bin");

   
    tree.decodeFromFile("output.bin", "decoded.txt");

    tree.printTree();

    return 0;
}
