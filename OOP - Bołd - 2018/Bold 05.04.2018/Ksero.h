#ifndef Ksero_h
#define Ksero_h

#include "Papierozerne.h"

/// Klasa reprezentujaca ksero, czyli urzadzenie
/// pobierajace papier - dlatego dziedziczy po 
/// klasie Papierozerne. Mamy dziedziczenie wirtualne
/// bo nie jest to jedyne urzadzenie dziedziczace po klasie
/// Papierozerne, a po obu tych urzadzeniach dziedziczy 
/// OfficeMultiTool
class Ksero : public virtual Papierozerne
{
public:
	/// Wirtualny destruktor, nie robi nic
	virtual ~Ksero() {}
};

#endif