#include "FractionArray.h"
#include <iostream>

FractionArray::FractionArray (int size)
{
	m_array = new Fraction* [size];
	m_arraySize = size; 
	m_numberOfAdded = 0;
}

void FractionArray::AddFraction (int numerator, int denominator)
{
	if (m_numberOfAdded==m_arraySize)
	{
		Fraction** tempArray = new Fraction * [m_numberOfAdded+1];
		for (int i=0; i<m_numberOfAdded; ++i)
			tempArray[i] = m_array[i];
		delete[] m_array;
		m_arraySize++;
		m_array = tempArray;
	}
	m_array[m_numberOfAdded] = new Fraction(numerator, denominator);
	m_numberOfAdded++;



}

void FractionArray::Print() const
{
	for (int i=0; i<m_numberOfAdded; ++i)
	{
		std::cout<<i<<": ";
		m_array[i]->Print();
	}
}

Fraction FractionArray::Sum() const
{
	Fraction Sum  (0,0);
	for (int i=0; i<m_arraySize; ++i)
		Sum = Sum.Add(*(m_array[i]));

	return Sum;
}


FractionArray::~FractionArray()
{
	if (m_array!=0)
	{
		for (int i = 0; i < m_numberOfAdded; ++i)
			delete m_array[i];
		delete [] m_array;
	}

}