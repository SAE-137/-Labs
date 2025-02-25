#include "bit_array.h"



BitArray::BitArray(int length)
	: length_(length)
	, size_((length_ + 7) / 8)
	, array_(new uint8_t[size_])
{
	
}

BitArray::BitArray(const char* string)
	: length_(strlen(string))
	, size_((length_ + 7) / 8)
	, array_(new uint8_t[size_])
{
	for (int i = 0; i < size_; i++)
	{
		array_[i] = 0;
	}

	for (int i = 0; i < length_; i++)
	{
		Set(string[length_ - i - 1] - '0', i);
	}
}

BitArray::BitArray(const char* string, int length)
	: length_(length)
	, size_((length_ + 7) / 8)
	, array_(new uint8_t[size_])
{
	for (int i = 0; i < size_; i++)
	{
		array_[i] = 0;
	}

	length = strlen(string);

	for (int i = 0; i < length; i++)
	{
		Set(string[length - i - 1] - '0', i);
	}
}

BitArray::BitArray(const BitArray& obj)
	: length_(obj.length_)
	, size_(obj.size_)
	, array_(new uint8_t[size_])
{
	for (int i = 0; i < size_; i++)
	{
		array_[i] = obj.array_[i];
	}
}

BitArray::~BitArray()
{
	delete[] array_;
}

//void BitArray::Resize(int length)
//{
//	int size = (length + 7) / 8;
//
//	if (length_ < length)
//	{
//		length_ = length;
//	}
//
//	if (size > size_)
//	{
//		uint8_t *array = new uint8_t[size];
//	
//		int i = 0;
//
//		for (; i < size_; i++)
//		{
//			array[i] = array_[i];
//		}
//
//		for (; i < size; i++)
//		{
//			array[i] = 0;
//		}
//	}
//}

void BitArray::Set(int status, int key, int count)
{
	if (key == -1)
	{
		key = 0;
		count = length_;
	}

	for (int i = key; i < key + count; i++)
	{
		if (status)
		{
			array_[i / 8] |= 0b1 << (i % 8);
		}
		else
		{
			array_[i / 8] &= ~(0b1 << (i % 8));
		}
	}
}

void BitArray::addBit(int bit)
{
	
	if (bit)
	{
		array_[length_ / 8] |= 0b1 << ((length_ - 0) % 8);
	}
	else
	{
		array_[length_ / 8] &= ~(0b1 << ((length_ - 0) % 8));
	}
	length_++;
}

void BitArray::Invert(int key, int count)
{
	if (key == -1)
	{
		key = 0;
		count = length_;
	}

	for (int i = key; i < key + count; i++)
	{
		array_[i / 8] ^= 0b1 << (i % 8);
	}
}

const int BitArray::getL() const
{
	return length_;
}

int BitArray::getL()
{
	return length_;
}

int BitArray::Weight()
{
	int res = 0;

	for (int i = 0; i < length_; i++)
	{
		if (operator[](i) == 1)
		{
			res++;
		}
	}

	return res;
}

int BitArray::operator[](int i) const
{
	return (array_[i / 8] >> i % 8) & 0b1;
}

BitArray& BitArray::operator=(const BitArray& obj)
{
	delete[] array_;

	length_ = obj.length_;
	size_ = obj.size_;
	array_ = new uint8_t[size_];

	for (int i = 0; i < size_; i++)
	{
		array_[i] = obj.array_[i];
	}

	return *this;
}

BitArray BitArray::operator&(const BitArray& obj)
{
	BitArray res(max(length_, obj.length_));

	for (int i = 0; i < min(length_, obj.length_); i++)
	{
		res.Set(operator[](i) & obj[i], i);
	}

	return res;
}

BitArray BitArray::operator|(const BitArray& obj)
{
	BitArray res(max(length_, obj.length_));

	int i = 0;

	for (; i < min(length_, obj.length_); i++)
	{
		res.Set(operator[](i) | obj[i], i);
	}

	for (; i < length_; i++)
	{
		res.Set(operator[](i), i);
	}

	for (; i < obj.length_; i++)
	{
		res.Set(obj[i], i);
	}

	return res;
}

BitArray BitArray::operator^(const BitArray& obj)
{
	BitArray res(max(length_, obj.length_));

	int i = 0;

	for (; i < min(length_, obj.length_); i++)
	{
		res.Set(operator[](i) ^ obj[i], i);
	}

	for (; i < obj.length_; i++)
	{
		res.Set(obj[i], i);
	}

	return res;
}

BitArray BitArray::operator<<(int value)
{
	BitArray res(length_);

	for (int i = value; i < length_; i++)
	{
		res.Set(operator[](i - value), i);
	}

	return res;
}

BitArray BitArray::operator>>(int value)
{
	BitArray res(length_);

	for (int i = value; i < length_; i++)
	{
		res.Set(operator[](i), i - value);
	}

	return res;
}

BitArray& BitArray::operator&=(const BitArray& obj)
{
	return *this = *this & obj;
}

BitArray& BitArray::operator|=(const BitArray& obj)
{
	return *this = *this | obj;
}

BitArray& BitArray::operator^=(const BitArray& obj)
{
	return *this = *this ^ obj;
}

BitArray& BitArray::operator<<=(int value)
{
	return *this = *this << value;
}

BitArray& BitArray::operator>>=(int value)
{
	return *this = *this >> value;
}

bool BitArray::operator==(const BitArray& obj)
{
	if (length_ != obj.length_)
	{
		return false;
	}

	for (int i = 0; i < size_; i++)
	{
		if (array_[i] != obj.array_[i])
		{
			return false;
		}
	}

	return true;
}

istream& operator>>(istream& is, BitArray& obj)
{
	char* string = new char[obj.length_ + 1];

	is.getline(string, obj.length_ + 1);

	for (int i = 0; i < obj.length_; i++)
	{
		obj.Set(string[obj.length_ - i - 1] - '0', i);
	}

	return is;
}

ostream& operator<<(ostream& os, const BitArray& obj)
{
	for (int i = obj.length_ - 1; i >= 0; i--)
	{
		os << obj[i];
	}

	return os;
}

void BitArray::Append(int bit)
{
	if (length_ % 8 == 0 && length_ / 8 >= size_) 
	{
		uint8_t* newArray = new uint8_t[size_ + 1](); 
		for (int i = 0; i < size_; i++)
		{
			newArray[i] = array_[i];
		}
		delete[] array_;
		array_ = newArray;
		size_++;
	}

	Set(bit, length_, 1); 
	length_++;
}


void BitArray::Pop()
{
	if (length_ > 0)
	{
		length_--;
		Set(0, length_, 1); 
	}
}

