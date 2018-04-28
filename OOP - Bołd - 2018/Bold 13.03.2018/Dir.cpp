#include "Dir.h"

Dir::Dir (std::string name):
	Element(name) 
{
	m_stored = nullptr;
	m_numberOfStoredElements = 0;
}

Dir * Dir::operator += (Element* added)
{
	Element ** temp = new Element* [m_numberOfStoredElements+1];
	for (int i=0; i<m_numberOfStoredElements; ++i)
		temp[i] = m_stored[i];
	if (m_stored)
		delete [] m_stored;
	m_stored = temp;
	m_stored[m_numberOfStoredElements] = added;
	m_numberOfStoredElements++;
	return this;
}

void Dir::print(std::ostream& placeToPrint, int numberOfSpaces) const
{
	for (int i=0; i<numberOfSpaces; ++i)
		placeToPrint<<" ";
	placeToPrint<<m_name<<std::endl;
	for (int i=0; i<m_numberOfStoredElements; ++i)
		m_stored[i]->print(placeToPrint, numberOfSpaces + 2);
}

std::ostream& operator << (std::ostream& stream, const Element &printed)
{
	printed.print(stream, 0);
	return stream;
}

Element* Dir::get(std::string name)
{
	for (int i=0; i<m_numberOfStoredElements; ++i)
	{
		if (m_stored[i]->getName() == name)
			return m_stored[i];
	}

	return nullptr;
}

Dir::~Dir()
{
	std::cout<<"Deleting Dir: "<<m_name<<std::endl;
	for (int i=0; i<m_numberOfStoredElements; ++i)
	{
		std::cout<<"About to delete "<<m_stored[i]->getName()<<std::endl;
		delete m_stored[i];
	}

	if (m_stored)
		delete [] m_stored;
}