#ifndef Mebel_h
#define Mebel_h

#include <iostream>

class Mebel 
{
public:
	Mebel (int szerokosc, int wysokosc, int dlugosc):
		m_szerokosc(szerokosc), m_wysokosc(wysokosc), m_dlugosc(dlugosc) {}

	virtual void wypisz(std::ostream& strumien) const;


	virtual ~Mebel();

private:
	int m_szerokosc;
	int m_wysokosc;
	int m_dlugosc;
};

std::ostream& operator<<(std::ostream& strumien, const Mebel& wypisywany);

#endif