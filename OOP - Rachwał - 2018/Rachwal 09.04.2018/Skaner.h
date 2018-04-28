#ifndef Skaner_h
#define Skaner_h

#include "Urzadzenie.h"

class Skaner : public Urzadzenie
{
public:
	Skaner (const Rozdzielczosc& rozdzielczosc):
		m_rozdzielczoscUrzadzenia(rozdzielczosc) {}

	virtual std::string rodzaj() const {return "Skaner";}

	virtual ~Skaner() {}

	const Rozdzielczosc& rozdzielczosc() const {return m_rozdzielczoscUrzadzenia;}

private:
	Rozdzielczosc m_rozdzielczoscUrzadzenia;

};

#endif