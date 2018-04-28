#include "Checkers.h"

bool capitalLetter::checkCondition(std::string toCheck) 
{
	for (unsigned i = 0; i<toCheck.size(); ++i){
		if (isupper(toCheck[i]))
			return true;
	}
	return false;
}

bool letter::checkCondition(std::string toCheck)
{
	for (unsigned i = 0; i<toCheck.size(); ++i)
		if (toCheck[i]==m_letterCondition)
			return true;
	return false;
}

bool letterFromRange::checkCondition(std::string toCheck)
{
	for (unsigned i = 0; i<toCheck.size(); ++i)
		if (toCheck[i]>= m_rangeStart && toCheck[i] <= m_rangeEnd)
			return true;
	return false;
}

bool anythingUntilLetter::checkCondition(std::string toCheck) 
{
	for (unsigned i = 0; i<toCheck.size(); ++i)
		if (toCheck[i] <= m_letterCondition)
			return true;
	return false;
}