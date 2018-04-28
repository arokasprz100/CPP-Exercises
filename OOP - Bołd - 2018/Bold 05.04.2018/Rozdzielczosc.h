#ifndef Rozdzielczosc_h
#define Rozdzielczosc_h

#include <iostream> /// std::ostream& 

/// Klasa reprezentujaca rozdzielczosc, czyli pare dwoch
/// liczb calkowitych. Rozdzielczosc jest parametrem wystepujacym 
/// w kilku implementowanych urzadzeniach
class Rozdzielczosc
{
public:
	/// Konstruktor obiektu klasy rozdzielczosc, przyjmujacy
	/// liczby calkowite odpowiadajace szerokosci oraz wysokosci
	/// Konstruktor ten nie robi nic poza ustawieniem pol w klasie
	Rozdzielczosc(int szerokosc, int wysokosc):
		m_szerokosc(szerokosc), m_wysokosc(wysokosc) {}

	/// Prosta metoda zwracajaca szerokosc (getter)
	/// Zapewnia niemodyfikowalnosc obiektu
	int dajSzerokosc() const {return m_szerokosc;}

	/// Prosta metoda zwracajaca wysokosc (getter)
	/// Zapewnia niemodyfikowalnosc obiektu
	int dajWysokosc() const {return m_wysokosc;}

private:
	/// pole reprezentujace szerokosc
	int m_szerokosc;

	/// pole reprezentujace wysokosc
	int m_wysokosc;

};

/// Przeladowany operator << pozwalajacy na wypisywanie rozdzielczosci do
/// strumienia. Format wypisywania: <szerokosc>x<wysokosc>
/// Nie jest friend z klasa Rozdzielczosc, bo klasa ta ma gettery i wystarczy
/// korzystac z nich
std::ostream& operator<<(std::ostream& strumien, const Rozdzielczosc& wypisywana)
{
	strumien<<wypisywana.dajSzerokosc()<<"x"<<wypisywana.dajWysokosc();
	return strumien;
}

#endif