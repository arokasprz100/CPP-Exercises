#ifndef Number_h
#define Number_h

#include <string>
#include <iostream>
#include <vector>
#include <exception>
#include "OutOfRange.h"

class Number
{
public:
	static void ClearFactory();

	static Number* Factory(std::string name, double value);

	static void SetRange(double low, double high);

	void Print() const;

	~Number();

public:
	Number(std::string name, double value);

	static bool IsOutOfRange(double value);

	std::string m_name;
	double m_value;

	static double m_lowRange;
	static double m_highRange;
	static std::vector <Number*> m_manufacturedNumbers;

};




#endif