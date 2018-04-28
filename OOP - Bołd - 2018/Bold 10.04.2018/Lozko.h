#ifndef Lozko_h
#define Lozko_h

#include "Mebel.h"

class Lozko: public virtual Mebel
{
public:
	Lozko(int szerokosc, int wysokosc, int dlugosc, int szerokosc_spania):
		Mebel(szerokosc, wysokosc, dlugosc), m_szerokosc_spania(szerokosc_spania) {}

	virtual void wypisz(std::ostream& strumien) const;

	virtual ~Lozko();

private:
	int m_szerokosc_spania;

};

#endif