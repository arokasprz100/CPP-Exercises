#ifndef Papierozerne_h
#define Papierozerne_h

#include "Urzadzenie.h"

class Papierozerne : public Urzadzenie
{
public:
	virtual std::string rodzaj() const= 0;
	virtual ~Papierozerne() {}
};

#endif