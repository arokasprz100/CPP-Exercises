#ifndef Kolo_h
#define Kolo_h

#include "Ksztalt.h"

/* 
 * Klasa Kolo bedaca konkretnym typem Ksztaltu - stad tez dziedziczenie.
 * Klasa ta korzysta z interfesju Ksztalt - implementuje metody. Dodatkowo
 * przechowuje informacje o wymiarach (promien) kola.
 */
class Kolo : public Ksztalt
{
public:
	/*
	 * Konstruktor kola - przyjmuje promien. Promien jest domyslne rowny 0.0
	 */
	Kolo (double r = 0.0) : m_promien(r) {}

	/*
	 * Implementacja metody print wypisujaca na ekran informacje ze ksztalt jest kolem
	 * o danym promieniu. Nie modyfikuje obiektu - jest const.
	 */
	void print(std::ostream& stream) const
	{
		stream << "Kolo o promieniu: " << m_promien << std::endl;
	}

	/*
	 * Implementacja metody polePow zwracajacej pole powierzchni kola. Pole powierzchni
	 * kola uzykiwane jest ze wzoru P = PI * promien * promien. Metoda nie modyfikuje
	 * obiektu na rzecz ktorego zostala wywolana
	 */
	double polePow() const { return m_promien * m_promien * 3.1415; }

private:
	/// Pole przechowujace promien kola
	double m_promien;

};


#endif