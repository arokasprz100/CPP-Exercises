#include "Mebel.h"
#include <algorithm>

std::ostream& operator<< (std::ostream& strumien, const Mebel& wypisywany) 
{
	strumien << wypisywany.m_nazwa << " " << wypisywany.m_dlugosc << " " 
			 << wypisywany.m_szerokosc << " " << wypisywany.m_wysokosc << " \"" << wypisywany.m_opis << "\" ";
	return strumien;
}

std::ifstream& operator>> (std::ifstream& strumien, Mebel& do_zapisu)
{
	strumien >> do_zapisu.m_nazwa  >> do_zapisu.m_dlugosc >> do_zapisu.m_szerokosc >> do_zapisu.m_wysokosc;
	std::string temp_opis;
	while (strumien.good())
	{
		strumien >> temp_opis;
		do_zapisu.m_opis += temp_opis;
		if (temp_opis.back() == '\"')
			break;
		else 
			do_zapisu.m_opis += " ";
	}
	do_zapisu.m_opis.erase(std::remove(do_zapisu.m_opis.begin(), do_zapisu.m_opis.end(), '\"'), do_zapisu.m_opis.end());
	return strumien;
}

std::ifstream& operator>> (std::ifstream& strumien, std::vector<Mebel>& do_zapisu)
{
	while (strumien.good()){
		Mebel nowy_mebel;
		strumien >> nowy_mebel;
		if (!strumien.good())
			break;
		do_zapisu.push_back(nowy_mebel);


	}

	return strumien;
}