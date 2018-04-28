#include "Obserwowany.h"

void Obserwowany::dodajObserwatora(Obserwator* dodawany)
{
	Obserwator** temp = new Obserwator* [m_iloscObserwatorow + 1];
	for (unsigned i=0; i<m_iloscObserwatorow; ++i)
		temp[i] = m_obserwatorzy[i];
	delete [] m_obserwatorzy;
	m_obserwatorzy = temp;
	m_obserwatorzy[m_iloscObserwatorow] = dodawany;
	m_iloscObserwatorow++;
}

void Obserwowany::noweDaneNadeszly(int dane)
{
	for (unsigned i=0; i<m_iloscObserwatorow; ++i)
		m_obserwatorzy[i]->aktualizujDane(dane);
}

Obserwowany::~Obserwowany()
{
	delete [] m_obserwatorzy;
}