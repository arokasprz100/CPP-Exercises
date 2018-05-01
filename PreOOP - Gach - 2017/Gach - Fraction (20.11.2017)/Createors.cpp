// Do tego pliku mozna dopisac kod, ale niemozna nic zniego usunac
#include "Fraction.h"


Fraction* CreateFraction (int numerator, int denominator)
{
	Fraction* newFraction = new Fraction;
	SetFraction(&newFraction, numerator, denominator);
	return newFraction; 
}


Fraction** CreateArray()
{
	return nullptr;
}


void CreateAddToArray(Fraction***array, int numerator, int denominator)
{
	Fraction * added = CreateFraction (numerator, denominator);
	AddToArray(array, added, false);
}