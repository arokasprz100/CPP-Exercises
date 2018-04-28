#ifndef Rozdzielczosc_h
#define Rozdzielczosc_h

#include <iostream>

class Rozdzielczosc
{
public:
	Rozdzielczosc (int szerokosc, int wysokosc):
		m_szerokosc(szerokosc), m_wysokosc(wysokosc) {}

	int dajSzerokosc() const {return m_szerokosc;}
	int dajWysokosc() const {return m_wysokosc;}

private:
	int m_szerokosc;
	int m_wysokosc;

};

std::ostream& operator << (std::ostream& strumien, const Rozdzielczosc& wypisywana);

#endif