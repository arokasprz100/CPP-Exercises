#ifndef Skaner_h
#define Skaner_h

#include "Rozdzielczosc.h" /// klasa Rozdzielczosc

/// Klasa reprezentujaca urzadzenie - skaner
/// Skaner jest urzadzeniem posiadajacym rozdzielczosc - 
/// dlatego wlasnie zawiera w sobie obiekt klasy Rozdzielczosc
/// Nie dziedziczy po niczym, a zwlaszcza po klasie Papierozerne - wynika
/// to z faktu, iz rzutowanie dynamic_cast w pliku main zwraca nulla
/// (oraz z faktu, ze wykonanie skanowania nie zuzywa dodatkowego papieru)
class Skaner
{
public:
	/// Konstruktor, ustala rozdzielczosc skanera
	/// Oprocz ustawiania pol klasy nie robi nic
	Skaner(Rozdzielczosc rozdzielczoscSkanera):
		m_rozdzielczoscSkanera(rozdzielczoscSkanera) {}

	/// Metoda zwracajaca rozdzielczosc skanera (getter)
	/// metoda ta zapewnia, ze rozdzielczosc nie zostanie 
	/// w zaden sposob zmieniona
	const Rozdzielczosc& rozdzielczosc() const {return m_rozdzielczoscSkanera;}

	/// Wirtualny destruktor, nie robi nic, pojawia sie bo
	/// wykonujemy delete na wskaznikach w pliku main oraz
	/// z powodu dynamic_cast
	virtual ~Skaner() {}

private:
	/// Pole reprezentujace rozdzielczosc skanera
	Rozdzielczosc m_rozdzielczoscSkanera;
};


#endif