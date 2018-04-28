#ifndef CSilnik_h
#define CSilnik_h

#include <string>

class CSilnik
{
public:
	CSilnik(double pojemnosc, double moc, std::string rodzajPaliwa):
		m_pojemnosc(pojemnosc), m_moc(moc), m_rodzajPaliwa(rodzajPaliwa) {}

private:
	double m_pojemnosc;
	double m_moc;
	std::string m_rodzajPaliwa;

};

#endif