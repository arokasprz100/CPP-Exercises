#ifndef CPojazd_h
#define CPojazd_h

#include "CSilnik.h"
#include <iostream>

class CPojazd
{
public:
	CPojazd(const CSilnik& silnik, std::string kolor, double stanLicznika, int liczbaKol):
		m_silnik(silnik), m_kolor(kolor), m_stanLicznika(stanLicznika), m_liczbaKol(liczbaKol) {}

	void wypisz(std::ostream& strumien);

protected:
	CSilnik m_silnik;
	std::string m_kolor;
	double m_stanLicznika;
	int m_liczbaKol;
};

std::ostream& operator<<(std::ostream& strumien, CPojazd& wypisywany);


#endif