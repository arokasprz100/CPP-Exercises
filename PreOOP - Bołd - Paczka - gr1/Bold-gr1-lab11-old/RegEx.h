#ifndef RegEx_h
#define RegEx_h

#include "Checkers.h"

class RegEx
{
public:
	RegEx():
		m_elements(nullptr), m_numberOfElements(0) {}

	RegEx& operator()(const Checker& added);

	std::string elements() const;

	bool match(std::string word);

	~RegEx();

private:
	Checker** m_elements;
	unsigned m_numberOfElements;
};

#endif