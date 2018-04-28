#include "Sofa.h"

void Sofa::wypisz(std::ostream& strumien) const
{
	strumien<<"Sofa: ";
	Mebel::wypisz(strumien);
	strumien<<" siedzisko: "<<m_siedzisko;
}

Sofa::~Sofa()
{
	std::cout<<"~Sofa"<<std::endl;
}