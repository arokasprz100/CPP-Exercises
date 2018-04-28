#ifndef Urzadzenie_h
#define Urzadzenie_h

#include <string>
#include "Rozdzielczosc.h"

class Urzadzenie
{
public:
	virtual std::string rodzaj() const = 0;
	virtual ~Urzadzenie() {}
};

#endif