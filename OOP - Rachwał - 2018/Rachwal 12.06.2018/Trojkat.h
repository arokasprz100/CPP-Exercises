#ifndef Trojkat_h
#define Trojkat_h

#include "Ksztalt.h"

/* 
 * Klasa Trojkat bedaca konkretnym typem Ksztaltu - stad tez dziedziczenie.
 * Klasa ta korzysta z interfesju Ksztalt - implementuje metody. Dodatkowo
 * przechowuje informacje o wymiarach (boki) trojkata.
 */
class Trojkat : public Ksztalt
{
public:
	/*
	 * Konstruktor trojkata - przyjmuje jako argumenty boku trojkata. 
	 * Jedyny sposob na stworzenie obiektu typu Trojkat.
	 */
	Trojkat (double a, double b, double c) : m_a(a), m_b(b), m_c(c) {}

	/*
	 * Metoda wypisujaca do strumienia informacje o trojkacie (dlugosci bokow).
	 * Nie modyfikuje obiektu.
	 */
	void print(std::ostream& stream) const
	{
		stream << "Trojkat o bokach: " << m_a << " " << m_b << " " << m_c << std::endl;
	}

	/*
	 * Metoda liczaca pole powierzchni trojkata na podstawie dlugosci jest bokow. 
	 * Wzor jest nastepujacy: P = sqrt (x*(x-a)*(x-b)*(x-c)) gdzie x = 0.5*(a+b+c)
	 * Metoda ta nie modyfikuje obiektu
	 */
	double polePow() const { double x = 0.5 * (m_a + m_b + m_c); return std::sqrt(x * (x- m_a)* (x-m_b) * (x- m_c)); }

private:
	/// Pola przechowujace dlugosci bokow trojkata
	double m_a, m_b, m_c;

};



#endif