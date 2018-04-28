#ifndef Element_h
#define Element_h

#include <string>
#include <iostream>

class Element
{
public:
	Element (std::string name):
		m_name(name) {}

	virtual void print(std::ostream& placeToPrint, int numberOfSpaces) const = 0;

	std::string& getName () {return m_name;}

	virtual ~Element() {}

protected:
	std::string m_name;

};

#endif