#include "Data.h"

void Data::deleteData() 
{
	if (m_next) 
		m_next->deleteData(); 
	delete this;
}

bool IntData::compare(const Data* compared)
{
	const IntData* temp = dynamic_cast<const IntData*>(compared);
	if (!temp)
		return false;
	if (temp->m_data == m_data)
		return true;
	return false;
}

bool StringData::compare(const Data* compared)
{
	const StringData* temp = dynamic_cast<const StringData*>(compared);
	if (!temp)
		return false;
	if (temp->m_data == m_data)
		return true;
	return false;
}

bool FloatData::compare(const Data* compared)
{
	const FloatData* temp = dynamic_cast<const FloatData*>(compared);
	if (!temp)
		return false;
	if (temp->m_data == m_data)
		return true;
	return false;
}