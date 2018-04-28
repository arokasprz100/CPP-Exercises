#ifndef NONLEAKABLEPTR_H
#define NOBLEAKABLEPTR_H

#include "NonLeakable.h"

class NonLeakablePtr
{
public:
	NonLeakablePtr():
		m_ptrToNonLeakable(0) {}

	NonLeakablePtr(NonLeakablePtr& copied);

	void MakeNewObject();

	void Print() const;

	NonLeakable* operator -> ();

	NonLeakablePtr& operator = (NonLeakablePtr& copied);

	NonLeakable& operator*();

	NonLeakable* operator&();

	~NonLeakablePtr();

private:
	NonLeakable* m_ptrToNonLeakable;

	NonLeakablePtr& operator = (const NonLeakablePtr& copied);



};

#endif