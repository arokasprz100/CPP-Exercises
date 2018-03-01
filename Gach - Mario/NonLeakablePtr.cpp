#include "NonLeakablePtr.h"
#include <iostream>

void NonLeakablePtr::MakeNewObject()
{
	if (m_ptrToNonLeakable==0)
		m_ptrToNonLeakable = new NonLeakable();
	else
	{
		delete m_ptrToNonLeakable;
		m_ptrToNonLeakable = new NonLeakable;
	}

}

void NonLeakablePtr::Print() const
{
	std::cout<<"Object pointing to ";
	if (m_ptrToNonLeakable)
		std::cout<<m_ptrToNonLeakable;
	else
		std::cout<<"nothing.";
	std::cout<<std::endl;
}


NonLeakablePtr::~NonLeakablePtr()
{
	if (m_ptrToNonLeakable!=0)
		delete m_ptrToNonLeakable;

}

NonLeakable* NonLeakablePtr::operator -> ()
{
	return m_ptrToNonLeakable;
}

NonLeakablePtr& NonLeakablePtr::operator = (NonLeakablePtr& copied)
{
	if (this->m_ptrToNonLeakable==copied.m_ptrToNonLeakable)
		return *this;

	m_ptrToNonLeakable = copied.m_ptrToNonLeakable;
	copied.m_ptrToNonLeakable = 0;

	return *this;
}


NonLeakablePtr::NonLeakablePtr(NonLeakablePtr& copied)
{
	m_ptrToNonLeakable = copied.m_ptrToNonLeakable;
	copied.m_ptrToNonLeakable = 0;
}

NonLeakable& NonLeakablePtr::operator*()
{
	return *m_ptrToNonLeakable;
}


NonLeakable* NonLeakablePtr::operator&()
{
	return m_ptrToNonLeakable;
}