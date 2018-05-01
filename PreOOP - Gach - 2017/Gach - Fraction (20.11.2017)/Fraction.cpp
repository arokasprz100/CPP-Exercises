#include <iostream>
#include "Fraction.h"


int arraySize = 0;


void Print (const Fraction* printed)
{
	if (printed->m_intPart!=0)
		std::cout<<printed->m_intPart<<" ";
	std::cout<<printed->m_numerator<<"/"<<printed->m_denominator<<std::endl;

}


void SetFraction (Fraction** toSet, int numerator, int denominator)
{
	if ((*toSet)==0)
		(*toSet) = new Fraction;
	(*toSet)->m_numerator = numerator % denominator;
	(*toSet)->m_denominator = denominator;
	(*toSet)->m_intPart = numerator / denominator;
}


Fraction Sum(const Fraction* lhs, const Fraction* rhs)
{
	Fraction newFraction;
	int newDenominator = lhs->m_denominator * rhs->m_denominator;
	int newNumerator = (lhs->m_denominator * lhs->m_intPart + lhs->m_numerator)*rhs->m_denominator 
						+ (rhs->m_denominator * rhs->m_intPart + rhs->m_numerator)*lhs->m_denominator;
	newFraction.m_numerator = newNumerator % newDenominator;
	newFraction.m_denominator = newDenominator;
	newFraction.m_intPart = newNumerator / newDenominator;
	return newFraction;
}


void AddToArray(Fraction*** array, Fraction* toAdd, bool alloc)
{
	Fraction** temp = new Fraction*[arraySize+1];
	for (int i=0; i<arraySize; ++i)
		temp[i] = (*array)[i];
	delete [] (*array);
	(*array) = temp;
	if (alloc)
		(*array)[arraySize] = new Fraction (*toAdd);
	else 
		(*array)[arraySize] = toAdd;
	arraySize++;
}


void PrintArray(Fraction** array)
{
	if (array == nullptr)
		return;

	std::cout<<"Array size: "<<arraySize<<std::endl;

	for (int i=0; i<arraySize; ++i)
	{
		std::cout<<i+1<<": ";
		Print(array[i]);
	}
}

