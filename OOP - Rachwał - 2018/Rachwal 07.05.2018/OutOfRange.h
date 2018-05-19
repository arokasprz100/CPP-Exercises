#ifndef OutOfRange_h
#define OutOfRange_h

#include <iostream>
#include <string>

class Number;

class OutOfRange : public std::exception
{
public:
	OutOfRange(Number* wrongValue):
		m_wrongValue(wrongValue) {}

	~OutOfRange();

	Number* GetValue() const;

private:
	Number * m_wrongValue;

};

std::ostream& operator<<(std::ostream& stream, const OutOfRange& printed);

#endif