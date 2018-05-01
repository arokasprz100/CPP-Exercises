// Do tego pliku mozna dopisac kod, ale niemozna nic zniego usunac
#include "Fraction.h"

void DestroyFraction (Fraction* frac)
{
	delete frac;
}

void ClearArray(Fraction*** array)
{
	if ((*array)==nullptr)
		return;

	for (int i=0; i<arraySize; ++i)
		delete (*array)[i];
	delete [] (*array);

	arraySize = 0;
	(*array) = nullptr;

}