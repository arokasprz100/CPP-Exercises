#ifndef FractionArray_h
#define FractionArray_h

#include "Fraction.h"

class FractionArray
{
public:
	FractionArray (int size);
	void AddFraction (int numerator, int denominator);
	void Print() const;
	Fraction Sum() const;
	~FractionArray();

private:
	Fraction** m_array;
	int m_arraySize;
	int m_numberOfAdded;

};

#endif