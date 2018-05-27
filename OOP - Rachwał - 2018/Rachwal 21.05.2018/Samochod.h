#ifndef Samochod_h
#define Samochod_h

#include <string>

class Samochod
{
public:
	Samochod(std::string marka = "", std::string model = ""):
		m_marka(marka), m_model(model) {}

	void print() const;

private:
	std::string m_marka;
	std::string m_model;

};

#endif