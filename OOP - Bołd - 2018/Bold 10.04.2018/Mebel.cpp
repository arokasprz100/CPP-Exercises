#include "Mebel.h"

void Mebel::wypisz(std::ostream& strumien) const
{
	strumien<<"Mebel: sz:"<<m_szerokosc<<" wys:"<<m_wysokosc<<" dl:"<<m_dlugosc;
}

Mebel::~Mebel()
{
	std::cout<<"~Mebel."<<std::endl;
}

std::ostream& operator<<(std::ostream& strumien, const Mebel& wypisywany)
{
	wypisywany.wypisz(strumien);
	return strumien;
}