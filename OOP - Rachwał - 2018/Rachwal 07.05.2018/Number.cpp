#include "Number.h"

std::vector <Number*> Number::m_manufacturedNumbers = {};

double Number::m_lowRange = 0.0;
double Number::m_highRange = 0.0;


void Number::ClearFactory()
{
	for (unsigned i =0; i<m_manufacturedNumbers.size(); ++i){
		if (m_manufacturedNumbers.at(i)){
			delete m_manufacturedNumbers.at(i);
			m_manufacturedNumbers.at(i) = nullptr;
		}
	}
}

Number* Number::Factory(std::string name, double value)
{
	Number* produced = new Number(name, value);
	m_manufacturedNumbers.push_back(produced);

	if (IsOutOfRange(value))
		throw OutOfRange(produced);

	return produced;
}

void Number::SetRange(double low, double high)
{
	m_lowRange = low;
	m_highRange = high;
}

void Number::Print() const 
{
	std::cout<<m_name<<" = "<<m_value<<std::endl;
}

Number::~Number()
{
	std::cout<<"Destroying number "<<m_value<<std::endl;
}

Number::Number(std::string name, double value):
	m_name(name), m_value(value) 
{
	std::cout<<"Manufacturing number "<<value<<std::endl;
}

bool Number::IsOutOfRange(double value)
{
	if (value > m_highRange)
		return true;
	else if (value < m_lowRange)
		return true;
	return false;
}