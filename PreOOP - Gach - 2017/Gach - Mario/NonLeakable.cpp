#include "NonLeakable.h"
#include <iostream>

unsigned NonLeakable::m_nextID = 0;

NonLeakable::NonLeakable()
{
	m_id = m_nextID;
	m_nextID++;
	std::cout<<"Constructing object "<<m_id<<std::endl;
}

void NonLeakable::Print() const
{
	std::cout<<"This is object with ID="<<m_id<<std::endl;
}

void* NonLeakable::operator new (std::size_t size)
{
	return ::operator new(size);
}

NonLeakable::~NonLeakable()
{
	std::cout<<"Destroying object "<<m_id<<std::endl;
}