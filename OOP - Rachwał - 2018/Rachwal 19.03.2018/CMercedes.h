#ifndef CMercedes_h
#define CMercedes_h

#include "CSamochod.h"

class CMercedes : public CSamochod
{
public:
	CMercedes(const CSilnik& silnik, double przebieg):
		CSamochod(silnik, "czarny metalic", przebieg) {}

	CMercedes (const CMercedes& copied):
		CSamochod(copied.m_silnik, copied.m_kolor, 0) {}

} ;

#endif