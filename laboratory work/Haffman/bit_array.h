#pragma once

#include <algorithm>

#include <iostream>

#ifndef BITVECTOR_H
#define BITVECTOR_H

#include <iostream>
#include <vector>

class BitVector {
private:
    std::vector<uint8_t> data_;
    int length_;

public:
    BitVector() : length_(0) {}

    void append(int bit) {
        if (bit != 0 && bit != 1) return;

        if (length_ % 8 == 0) {
            data_.push_back(0); 
        }

        if (bit) {
            data_.back() |= (1 << (length_ % 8));
        }

        length_++;
    }

    void pop() {
        if (length_ == 0) return;
        length_--;
        data_[length_ / 8] &= ~(1 << (length_ % 8));
        if (length_ % 8 == 0 && !data_.empty()) {
            data_.pop_back();
        }
    }

    int operator[](int index) const {
        if (index < 0 || index >= length_) return 0;
        return (data_[index / 8] >> (index % 8)) & 1;
    }

    int size() const { return length_; }

    void print() const {
        for (int i = length_ - 1; i >= 0; i--) {
            std::cout << (*this)[i];
        }
        std::cout << std::endl;
    }
};

#endif 
