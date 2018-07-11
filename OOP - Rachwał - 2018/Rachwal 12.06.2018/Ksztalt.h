#ifndef Ksztalt_h
#define Ksztalt_h


#include <iostream>
#include <cmath>


#include "LicznikInstancji.h"

/*
 * Klasa abstrakcyjna Ksztalt reprezentujaca ksztalt geometryczny. Sluzy za 
 * interfejs do dziedziczenia i tworzenia konkretnych ksztaltow. Klasa ta
 * udostepnia interfejs do obliczania pola powierzchni, wypisywania informacji
 * o ksztalcie oraz do liczenia instancji wszystkich ksztaltow. Dziedziczy po
 * konkretyzacji szablonu LicznikInstancji w celu zastosowania wzorca CRTP.
 */
class Ksztalt : public LicznikInstancji<Ksztalt>
{
public:
	/*
	 * Czysto wirtualna metoda print. Interfejs do wypisywania informacji
	 * o obiekcie dziedziczacym po tej klasie.
	 */
	virtual void print(std::ostream& stream) const = 0;

	/* 
	 * Czysto wirtualna metoda stanowiaca interfejs do liczenia pola powierzchni
	 * ksztaltu dziedziczacego po tej klasie. Jest const, bo liczenie pola 
	 * nie zmienia w zaden sposob obiektu. Pole jest zwracane jako double.
	 */
	virtual double polePow() const = 0;

	/*
	 * Statyczna metoda zwracajaca ilosc istniejacych obiektow pochodnych
	 * do Ksztaltu. Korzysta z klasy LicznikInstancji.
	 */
	static unsigned N() { return dajLiczbeInstancji(); }

	/* 
	 * Wirtualny destruktor, nie robi nic, jest tu w celu poprawnego zwalaniania
	 * pamieci jesli uzyjemu operatorow new i delete
	 */
	virtual ~Ksztalt() {}

};

/*
 * Przeladowany operator << do wypisywania dowolnego obiektu z hierarchi Ksztaltow.
 * Wywoluje implementacje funkcji print w celu wypisania informacji o obiekcie na 
 * obiekt typu ostream - np standardowe wyjscie. Obiekt przekazujemy za pomoca
 * wskaznika.
 */ 
std::ostream& operator << (std::ostream& stream, const Ksztalt* printed);

/* 
 * Przeladowany operator << wypisujacy tablice wskaznikow na obiekty typu Ksztalt. 
 * Ksztalty sa wypisywane kazdy w nowej linii
 */
std::ostream& operator << (std::ostream& stream, const Ksztalt** printed);

#endif