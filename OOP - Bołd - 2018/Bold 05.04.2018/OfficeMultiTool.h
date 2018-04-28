#ifndef OfficeMultiTool_h
#define OfficeMultiTool_h

#include "Ksero.h"
#include "Drukarka.h"
#include "Skaner.h"

/// Klasa dziedziczaca po kilku urzadzeniach. Reprezentuje funkcjonalnosci
/// drukarki, skanera i ksera naraz. Ma dwie rozdzielczosci odziedziczone po
/// klasach bazowych. W przypadku tej klasy mamy do czynienia z dziedziczeniem 
/// wielokrotnym.
class OfficeMultiTool : public Ksero, public Drukarka, public Skaner
{
public:
	/// Konstruktor, przyjmuje dwie rozdzielczosci i ustawia je dla odpowiednich urzadzen
	/// stanowiacych baze
	OfficeMultiTool(Rozdzielczosc rozdzielczoscDrukarki, Rozdzielczosc rozdzielczoscSkanera):
		Drukarka(rozdzielczoscDrukarki), Skaner(rozdzielczoscSkanera) {}

	/// Wirtualny destruktor, nie robi nic
	virtual ~OfficeMultiTool() {}
};

#endif