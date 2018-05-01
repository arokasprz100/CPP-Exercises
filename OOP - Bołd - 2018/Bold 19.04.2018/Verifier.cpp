#include "Verifier.h"

std::ostream& operator << (std::ostream& stream, const ArgVerificationFailed& toPrint)
{
	stream<<toPrint.m_message;
	return stream;
}

bool is::operator > (const int rhs)
{
	if (m_number > rhs)
		return true;
	throw ArgVerificationFailed("Argument " + std::to_string(m_number) + " has to be greator than " + std::to_string(rhs));
}

bool is::operator >= (const int rhs)
{
	if (m_number >= rhs)
		return true;
	throw ArgVerificationFailed("Argument " + std::to_string(m_number) + " has to be greator or equal than " + std::to_string(rhs));
}

bool is::operator < (const int rhs)
{
	if (m_number < rhs)
		return true;
	throw ArgVerificationFailed("Argument " + std::to_string(m_number) + " has to be lower than " + std::to_string(rhs));
}
	
bool is::operator <= (const int rhs)
{
	if (m_number <= rhs)
		return true;
	throw ArgVerificationFailed("Argument " + std::to_string(m_number) + " has to be lower or equal than " + std::to_string(rhs));
}