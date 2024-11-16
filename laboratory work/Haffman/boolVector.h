#pragma once
#include<string>
class boolVector
{
public:
	boolVector();
	boolVector(std::string txt);
	~boolVector();


	
	void show();

private:
	int m_length = 0;
	int m_size = 0;

	uint8_t* m_vector = nullptr;
};

