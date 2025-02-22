#include "set.h"

Set::Set()
	: BitArray(256)
	, cardinality_(0)
{

}

Set::Set(const char* string)
	: BitArray(256)
{
	for (int i = 0; string[i] != '\0'; i++)
	{
		operator+=(string[i]);
	}

	Cardinality();
}

Set::Set(const Set& obj)
	: BitArray(obj)
	, cardinality_(obj.cardinality_)
{

}

uint8_t Set::Min()
{
	int i = 0;

	while (i < length_ && operator[](i) == 0)
	{
		i++;
	}

	return i;
}

uint8_t Set::Max()
{
	int i = 255;

	while (i >= 0 && operator[](i) == 0)
	{
		i--;
	}

	return i;
}

void Set::Cardinality()
{
	cardinality_ = 0;

	for (int i = 0; i < length_; i++)
	{
		if (operator[](i) == 1)
		{
			cardinality_++;
		}
	}
}

Set Set::Complement()
{
	Set res(*this);

	for (int i = Min(); i <= Max(); i++)
	{
		res.Invert(i);
	}

	Cardinality();

	return res;
}

Set Set::operator&(const Set& obj)
{
	Set res(*this);

	res.BitArray::operator&=(obj);

	res.Cardinality();

	return res;
}

Set Set::operator|(const Set& obj)
{
	Set res(*this);

	res.BitArray::operator|=(obj);

	res.Cardinality();

	return res;
}

Set Set::operator+(uint8_t key)
{
	Set res(*this);

	res.BitArray::Set(1, key);

	res.Cardinality();

	return res;
}

Set Set::operator-(uint8_t key)
{
	Set res(*this);

	res.BitArray::Set(0, key);

	res.Cardinality();

	return res;
}

Set Set::operator-(const Set& obj)
{
	Set res(*this);

	for (int i = 0; i < length_; i++)
	{
		if (obj[i] == 1)
		{
			res.BitArray::Set(0, i);
		}
	}

	res.Cardinality();

	return res;
}

Set& Set::operator&=(const Set& obj)
{
	return *this = *this & obj;
}

Set& Set::operator|=(const Set& obj)
{
	return *this = *this | obj;
}

Set& Set::operator+=(uint8_t key)
{
	return *this = *this + key;
}

Set& Set::operator-=(uint8_t key)
{
	return *this = *this - key;
}

Set& Set::operator-=(const Set& obj)
{
	return *this = *this - obj;
}

ostream& operator<<(ostream& os, const Set& obj)
{
	os << obj.cardinality_ << ":";

	for (int i = 0; i < obj.length_; i++)
	{
		if (obj[i] == 1)
		{
			os << (char)i;
		}
	}

	return os;
}
