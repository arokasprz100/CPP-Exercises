#ifndef Ksero_h
#define Ksero_h

#include "Papierozerne.h"

class Ksero : public virtual Papierozerne
{
public:
	virtual std::string rodzaj() const {return "Ksero";}
	virtual ~Ksero() {}
};

#endif