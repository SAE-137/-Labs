#pragma once

#include <algorithm>

#include <iostream>

using namespace std;

class BitArray
{
public:

	BitArray()
		: length_(0), size_(1), array_(new uint8_t[1]())
	{
	}

	BitArray(int length);
	BitArray(const char* string);
	BitArray(const char* string, int length);
	BitArray(const BitArray& obj);
	~BitArray();

	void addBit(int bit);

	void Set(int status, int key = -1, int count = 1);
	void Invert(int key = -1, int count = 1);

	int Weight();
	int getL();
	const int getL() const;

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


	void Append(const BitArray& other)
	{
		int oldLength = length_;
		Resize(length_ + other.getL());

		for (int i = 0; i < other.getL(); i++)
		{
			Set(other[i], oldLength + i);
		}
	}

	void Resize(int newLength)
	{
		int newSize = (newLength + 7) / 8;
		uint8_t* newArray = new uint8_t[newSize];

		// Копируем старые данные
		for (int i = 0; i < size_; i++)
		{
			newArray[i] = array_[i];
		}

		// Инициализируем новые биты нулями
		for (int i = size_; i < newSize; i++)
		{
			newArray[i] = 0;
		}

		delete[] array_;
		array_ = newArray;
		size_ = newSize;
		length_ = newLength;
	}

	void Append(int bit);
	void Pop();

protected:
	int length_;
	int size_;

	uint8_t* array_;

	friend istream& operator>>(istream& is, BitArray& obj);
	friend ostream& operator<<(ostream& os, const BitArray& obj);
};