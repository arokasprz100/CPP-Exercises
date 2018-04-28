#ifndef Sofa_h
#define Sofa_h

#include "Mebel.h"

class Sofa : public virtual Mebel
{
public:
	Sofa (int szerokosc, int wysokosc, int dlugosc, int siedzisko):
		Mebel(szerokosc, wysokosc, dlugosc), m_siedzisko(siedzisko) {}

	virtual void wypisz (std::ostream& strumien) const;

	virtual ~Sofa();

private:
	int m_siedzisko;

};

#endif
