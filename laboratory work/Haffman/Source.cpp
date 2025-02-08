#include <iostream>
#include <cstdint>
#include "boolVector.h"
#include"huffmanTree.h"

int main() {
   
    std::string txt = "a";
    huffmanTree a;
    a.build(txt);
    a.testShow();
    boolVector b(txt);
    b.show();
    

    return 0;
}