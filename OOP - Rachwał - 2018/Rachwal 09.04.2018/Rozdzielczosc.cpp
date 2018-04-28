#include "Rozdzielczosc.h"

std::ostream& operator << (std::ostream& strumien, const Rozdzielczosc& wypisywana)
{
	strumien<<wypisywana.dajSzerokosc()<<"x"<<wypisywana.dajWysokosc();
	return strumien;
}