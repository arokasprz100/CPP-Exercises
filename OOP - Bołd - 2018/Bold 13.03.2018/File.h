#ifndef File_h
#define File_h

#include "Element.h"

class File : public Element
{
public:
	File (std::string name):
		Element(name){}

	virtual void print(std::ostream& placeToPrint, int numberOfSpaces) const;
};

#endif