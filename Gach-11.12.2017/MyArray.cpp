#include "MyArray.h"
#include <iostream>

MyArray::MyArray (int startSize):
	size(m_size), m_size (startSize)
{
	m_arrayOfInts = new int [startSize];

}

MyArray::MyArray (const MyArray& copied):
	size (m_size)
{
	m_arrayOfInts = new int [copied.size];
	m_size = copied.m_size;
	for (int i=0; i<size; ++i)
		m_arrayOfInts[i] = copied.m_arrayOfInts[i];
}

int& MyArray::at(int index) const
{
	return m_arrayOfInts[index];
}

void MyArray::print() const
{
	std::cout<<"Array content: "<<std::endl;
	for (int i=0; i<size; ++i)
		std::cout<<"array["<<i<<"] = "<<m_arrayOfInts[i]<<std::endl;

}

void MyArray::resize (int newSize)
{
	int * temp = new int [newSize];
	for (int i=0; i<size; ++i)
		temp[i] = m_arrayOfInts[i];
	delete [] m_arrayOfInts;

	m_arrayOfInts = temp;

	m_size = newSize;

}

MyArray::~MyArray()
{
	delete [] m_arrayOfInts;
}