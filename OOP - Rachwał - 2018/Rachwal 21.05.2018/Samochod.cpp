#include "Samochod.h"
#include <iostream>

void Samochod::print() const
{
	std::cout<<m_marka<<" : "<<m_model<<std::endl;
}