#ifndef CRomet_h
#define CRomet_h

#include "CMotorower.h"

class CRomet : public CMotorower
{
public:
	CRomet(const CSilnik& silnik, double stanLicznika):
		CMotorower(silnik, "czerwony metalic", stanLicznika) {}

};

#endif