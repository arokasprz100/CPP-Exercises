#include "Obserwator.h"
#include <iostream>


void ObserwatorWypisywacz::aktualizujDane(int dane)
{
	std::cout<<" "<<dane;
}

void ObserwatorLicznik::aktualizujDane(int dane)
{
	m_suma+=dane;
}