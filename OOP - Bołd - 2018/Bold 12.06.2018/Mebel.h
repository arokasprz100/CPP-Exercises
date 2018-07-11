#ifndef Mebel_h
#define Mebel_h

#include <string>
#include <iostream>
#include <vector>
#include <fstream>



class Mebel
{
public:
	Mebel (const std::string& nazwa = "", unsigned dlugosc = 0, unsigned szerokosc = 0, unsigned wysokosc = 0, const std::string& opis = "") :
		m_nazwa(nazwa), m_dlugosc(dlugosc), m_szerokosc(szerokosc), m_wysokosc(wysokosc), m_opis(opis) {}

	friend std::ostream& operator<< (std::ostream& strumien, const Mebel& wypisywany);

	friend std::ifstream& operator>> (std::ifstream& strumien, Mebel& do_zapisu);

private:
	std::string m_nazwa;
	unsigned m_dlugosc;
	unsigned m_szerokosc;
	unsigned m_wysokosc;
	std::string m_opis;
};


std::ifstream& operator>> (std::ifstream& strumien, std::vector<Mebel>& do_zapisu);

#endif