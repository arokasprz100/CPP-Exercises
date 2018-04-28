#ifndef Wielofunkcyjne_h
#define Wielofunkcyjne_h

#include "Drukarka.h"
#include "Ksero.h"
#include "Skaner.h"

class Wielofunkcyjne : public Drukarka, public Ksero, public Skaner
{
public:
	Wielofunkcyjne(const Rozdzielczosc& roz1, const Rozdzielczosc& roz2):
		Papierozerne(), Drukarka(roz1), Skaner(roz2) {}

	virtual std::string rodzaj() const {return "Wielofunkcyjne";}
};

#endif