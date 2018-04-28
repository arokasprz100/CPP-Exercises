#include "RegEx.h"

RegEx& RegEx::operator()(const Checker& added)
{
	Checker** temp = new Checker * [m_numberOfElements+1];
	for (unsigned i =0; i<m_numberOfElements; ++i)
		temp[i] = m_elements[i];
	temp[m_numberOfElements] = added.clone();
	delete [] m_elements;
	m_elements = temp;
	m_numberOfElements++;

	return *this;
}

std::string RegEx::elements() const
{
	std::string allElementsNames = "";
	for (unsigned i = 0; i<m_numberOfElements; ++i)
		allElementsNames += m_elements[i]->getName() + " ";
	return allElementsNames;

}

RegEx::~RegEx()
{
	for (unsigned i = 0; i<m_numberOfElements; ++i)
		delete m_elements[i];
	delete [] m_elements;
}

bool RegEx::match(std::string word)
{
	bool isMatching = true;
	for (unsigned i = 0; i<m_numberOfElements; ++i)
	{
		if (!m_elements[i]->checkCondition(word))
			isMatching = false;
	}
	return isMatching;
}
