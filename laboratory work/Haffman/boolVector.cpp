#include "boolVector.h"
#include<string>
#include<iostream>

boolVector::boolVector()
{
	m_size = 0;
}

boolVector::boolVector(std::string txt) {
    m_length = txt.size() * 8;          
    m_size = (m_length + 7) / 8;      
    m_vector = new uint8_t[m_size]();  

    for (size_t i = 0; i < txt.size(); ++i) {
        int value = static_cast<int>(txt[i]); 

        
        for (int j = 0; j < 8; ++j) {
            if (value % 2 == 0) {
                m_vector[i] &= ~(0b1 << j);
            }
            else {
                m_vector[i] |= (0b1 << j); 
            }
            value /= 2; 
        }
    }
}

boolVector::~boolVector()
{
	
}


void boolVector::show() {
    for (size_t i = 0; i < m_size; ++i) {
        for (int bit = 7; bit >= 0; --bit) { 
            std::cout << ((m_vector[i] >> bit) & 1);
        }
    }
    std::cout << std::endl;
}
