#include "CPojazd.h"

void CPojazd::wypisz(std::ostream& strumien)
{
	strumien<<"\nLiczba kol "<<m_liczbaKol<<std::endl;
	strumien<<"Stan licznika "<<m_stanLicznika<<" [km]"<<std::endl;
	strumien<<"Kolor "<<m_kolor<<std::endl;
}

std::ostream& operator<<(std::ostream& strumien, CPojazd& wypisywany)
{
	wypisywany.wypisz(strumien);
	return strumien;
}