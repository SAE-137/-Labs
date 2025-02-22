#pragma once

#include "bit_array.h"

class Set : public BitArray
{
public:
	Set();
	Set(const char* string);
	Set(const Set& obj);

	uint8_t Min();
	uint8_t Max();

	Set Complement();

	Set operator&(const Set& obj);
	Set operator|(const Set& obj);
	Set operator+(uint8_t key);
	Set operator-(uint8_t key);
	Set operator-(const Set& obj);

	Set& operator&=(const Set& obj);
	Set& operator|=(const Set& obj);
	Set& operator+=(uint8_t key);
	Set& operator-=(uint8_t key);
	Set& operator-=(const Set& obj);

private:
	int cardinality_;

	void Cardinality();

	friend ostream& operator<<(ostream& os, const Set& obj);
};