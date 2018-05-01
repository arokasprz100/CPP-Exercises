#include "List.h"

/// Static values

bool List::Begin = true;
bool List::End = false;

/// Public methods

List::List(const List& copied)
{
	Data *temp = copied.m_start;
	m_start = temp->clone();
	Data *temp2 = m_start;
	temp = temp->m_next;
	while (temp)
	{
		temp2->m_next = temp->clone();
		temp = temp->m_next;
		temp2 = temp2->m_next;
	}
	m_end = temp2;
}


List::~List() 
{
	m_start->deleteData();
}


List& List::insert(const Data& toInsert, bool isBegin)
{
	Data * inserted = toInsert.clone();
	if (isBegin)
		insertBegin(inserted);
	else
		insertEnd(inserted);
	return *this;
}


void List::print()
{
	std::cout<<"[ ";
	Data* temp = m_start;
	while (temp!=nullptr)
	{
		std::cout<<" "<<temp->getData();
		temp = temp->m_next;
	}
	std::cout<<"]"<<std::endl;
}


bool List::find(const Data& toFind)
{
	Data* temp = m_start;
	while (temp)
	{
		if (temp->compare(&toFind))
			return true;
		temp= temp->m_next;
	}
	return false;
}


/// Private methods

void List::insertBegin(Data* inserted)
{
	inserted->m_next = m_start;
	m_start = inserted;
	if (m_end==nullptr)
		m_end = inserted;
}

void List::insertEnd(Data* inserted)
{
	m_end->m_next = inserted;
	m_end = inserted;
	if (m_start==nullptr)
		m_start = inserted;
}