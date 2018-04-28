#include "Lozko.h"

void Lozko::wypisz(std::ostream& strumien) const
{
	strumien<<"Lozko: ";
	Mebel::wypisz(strumien);
	strumien<<" sz.spania: "<<m_szerokosc_spania;
}

Lozko::~Lozko()
{
	std::cout<<"~Lozko"<<std::endl;
}
