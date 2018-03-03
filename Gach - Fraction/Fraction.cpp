#include "Fraction.h"
#include <iostream>


Fraction::Fraction (int numerator, int denominator)
{
	if (numerator == 0 || denominator == 0)
		m_denominator = m_numerator = m_integerPart = 0;
	else 
	{
		m_numerator = numerator % denominator;
		m_denominator = denominator;
		m_integerPart = numerator / denominator;
	}

}


void Fraction::Print() const
{
	if (m_integerPart!=0)
		std::cout<<m_integerPart<<" ";
	std::cout<<m_numerator<<"/"<<m_denominator<<std::endl;
}

Fraction Fraction::Add(const Fraction& added) const
{
	if (m_denominator == 0 || added.m_denominator == 0 )
		return Fraction (m_numerator + added.m_numerator, m_denominator + added.m_denominator);
	int newNumerator = 0;
	int newDenominator = 0;
	if (m_denominator==added.m_denominator)
	{
		newNumerator = m_integerPart*m_denominator + m_numerator + added.m_integerPart*added.m_denominator+added.m_numerator;
		newDenominator = m_denominator;
	}
	else
	{
		newDenominator = m_denominator*added.m_denominator;
		newNumerator = (m_integerPart*m_denominator + m_numerator)* added.m_denominator + (added.m_integerPart*added.m_denominator + added.m_numerator)*m_denominator;
	}
	return Fraction (newNumerator, newDenominator);

}