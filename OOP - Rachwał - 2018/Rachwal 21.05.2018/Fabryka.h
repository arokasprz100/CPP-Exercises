#ifndef Fabryka_h
#define Fabryka_h

#include "Samochod.h"

class Fabryka
{
public:
	template <typename T>
	T& prototyp(T wartosc, bool czyZmieniac = true);

	template <typename T>
	T& produkuj();
};

/// Method implementation ///

template <typename T>
T& Fabryka::prototyp(T wartosc, bool czyZmieniac)
{
	static T m_wartosc;
	if (czyZmieniac)
		m_wartosc = wartosc;
	return m_wartosc;
}

template <typename T>
T& Fabryka::produkuj()
{
	return prototyp(T(), false);
}

#endif