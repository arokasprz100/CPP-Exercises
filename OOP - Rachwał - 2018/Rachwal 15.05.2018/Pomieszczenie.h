#ifndef Pomieszczenie_h
#define Pomieszczenie_h

#include <string>
#include <iostream>

class Pomieszczenie
{
public:
	/// Prosty konstruktor przyjmujacy nazwe pomieszczenia 
	/// Konstruktor jest glosny, tzn wypisuje informacje o
	/// towrzeniu obiektu
	Pomieszczenie (std::string nazwa);

	void zetrzyj_kurze() const;

	void umyj_podloge() const;

	void odkurz() const;

	const std::string& daj_nazwe() const;

	template <typename T> void wstaw (T wartosc);

private:
	std::string m_nazwaPomieszczenia;

};

/// Musi byc w tym pliku (nie moze byc w cpp)
template <typename T>
void Pomieszczenie::wstaw (T wartosc)
{
	std::cout<<"Wstawiam "<<wartosc<<" do pomieszczenia: "<<m_nazwaPomieszczenia<<std::endl;
}





#endif