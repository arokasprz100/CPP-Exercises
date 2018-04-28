#ifndef CSamochod_h
#define CSamochod_h

#include "CPojazd.h"

class CSamochod : public CPojazd
{
public:
	CSamochod(const CSilnik& silnik, std::string kolor, double stanLicznika):
		CPojazd(silnik, kolor, stanLicznika, 4) {}

};

#endif