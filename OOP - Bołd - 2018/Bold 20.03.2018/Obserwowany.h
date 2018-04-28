#ifndef Obserwowany_h
#define Obserwowany_h

#include "Obserwator.h"

class Obserwowany
{
public:
	Obserwowany():
		m_obserwatorzy(nullptr), m_iloscObserwatorow(0) {}

	void noweDaneNadeszly(int dane);
	
	void dodajObserwatora(Obserwator* dodawany);

	~Obserwowany();

protected:
	Obserwator** m_obserwatorzy;
	unsigned m_iloscObserwatorow;

};

#endif