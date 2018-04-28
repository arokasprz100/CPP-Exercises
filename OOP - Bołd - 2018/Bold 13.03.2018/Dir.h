#ifndef Dir_h
#define Dir_h

#include "Element.h"
#include <iostream>

class Dir : public Element
{
public:
	Dir (std::string name);

	Dir * operator += (Element* added);

	virtual void print(std::ostream& placeToPrint, int numberOfSpaces) const;

	Element* get(std::string name);

	~Dir();


protected:
	Element** m_stored;
	int m_numberOfStoredElements;

};

std::ostream& operator << (std::ostream& stream, const Element &printed);

#endif