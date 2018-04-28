#ifndef Kanapa_h
#define Kanapa_h

#include "Lozko.h"
#include "Sofa.h"

class Kanapa : public Sofa, public Lozko
{
public:
	Kanapa(int szerokosc, int wysokosc, int dlugosc, int siedzisko, int sz_spania):
		Mebel (szerokosc, wysokosc, dlugosc), Sofa(szerokosc, wysokosc, dlugosc, siedzisko), Lozko(szerokosc, wysokosc, dlugosc, sz_spania) {}

	void wypisz(std::ostream& strumien) const;

	~Kanapa();

};

#endif