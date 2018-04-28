#ifndef Drukarka_h
#define Drukarka_h

#include "Papierozerne.h"

class Drukarka : public virtual Papierozerne
{
public:
	Drukarka (const Rozdzielczosc& rozdzielczosc):
		m_rozdzielczoscUrzadzenia(rozdzielczosc) {}

	virtual std::string rodzaj() const {return "Drukarka";}

	virtual ~Drukarka() {}

	const Rozdzielczosc& rozdzielczosc() const {return m_rozdzielczoscUrzadzenia;}

private:
	Rozdzielczosc m_rozdzielczoscUrzadzenia;

};

#endif