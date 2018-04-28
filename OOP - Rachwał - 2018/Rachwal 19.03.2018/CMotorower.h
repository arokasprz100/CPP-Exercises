#ifndef CMotorower_h
#define CMotorower_h

#include "CPojazd.h"

class CMotorower : public CPojazd
{
public:
	CMotorower(const CSilnik& silnik, std::string kolor, double stanLicznika):
		CPojazd(silnik, kolor, stanLicznika, 2) {}
};

#endif