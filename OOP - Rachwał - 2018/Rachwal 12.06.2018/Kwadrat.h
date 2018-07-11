#ifndef Kwadrat_h
#define Kwadrat_h

#include "Ksztalt.h"

/* 
 * Klasa kwadrat bedaca konkretnym typem Ksztaltu - stad tez dziedziczenie.
 * Klasa ta korzysta z interfesju Ksztalt - implementuje metody. Dodatkowo
 * przechowuje informacje o wymiarach (jeden bok) kwadratu.
 */
class Kwadrat : public Ksztalt
{
public:
	/*
	 * Konstruktor jednoargumentowy z domyslnym argumentem 0 - czyli tez konstruktor
	 * domniemany. Jest to sposob na stworzenie obiektu typu Kwadrat poprzed podanie
	 * dlugosci jego boku - w przypadku kwadaratu wystarczy to do jednoznacznosci
	 */
	Kwadrat (int a = 0) : m_a(a) {}

	/*
	 * Implementacja metody print wypisujaca na ekran informacje ze ksztalt jest kwadratem
	 * o danej dlugosci boku. Nie modyfikuje obiektu - jest const.
	 */
	void print(std::ostream& stream) const
	{
		stream << "Kwadrat o boku: " << m_a << std::endl;
	}

	/*
	 * Kolejna implementacja metody z interfejsu Ksztalt. Oblicza pole powierzchni kwadratu
	 * zgodnie ze wzorem P = a * a gdzie a to bok kwadratu. Nie modyfikuje obiektu.
	 */
	double polePow() const { return m_a * m_a; }

private:
	/// Pole przechowujace dlugosc boku kwadratu
	double m_a;

};

#endif