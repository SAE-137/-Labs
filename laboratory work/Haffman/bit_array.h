#pragma once

#include <algorithm>

#include <iostream>

using namespace std;

class BitArray
{
public:
	BitArray(int length = 1);
	BitArray(const char* string);
	BitArray(const char* string, int length);
	BitArray(const BitArray& obj);
	~BitArray();

	void Set(int status, int key = -1, int count = 1);
	void Invert(int key = -1, int count = 1);

	int Weight();

	int operator[](int key) const;
	BitArray& operator=(const BitArray& obj);

	BitArray operator&(const BitArray& obj);
	BitArray operator|(const BitArray& obj);
	BitArray operator^(const BitArray& obj);
	BitArray operator<<(int value);
	BitArray operator>>(int value);

	BitArray& operator&=(const BitArray& obj);
	BitArray& operator|=(const BitArray& obj);
	BitArray& operator^=(const BitArray& obj);
	BitArray& operator<<=(int value);
	BitArray& operator>>=(int value);

	bool operator==(const BitArray& obj);

protected:
	int length_;
	int size_;

	uint8_t* array_;

	friend istream& operator>>(istream& is, BitArray& obj);
	friend ostream& operator<<(ostream& os, const BitArray& obj);
};