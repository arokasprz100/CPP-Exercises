#ifndef NONLEAKABLE_H
#define NONLEAKABLE_H

#include <cstddef>

class NonLeakable 
{
public:
	NonLeakable();
	void Print() const;
	~NonLeakable();

private:
	unsigned m_id;
	static unsigned m_nextID;

	static void* operator new (std::size_t size);

	friend class NonLeakablePtr;

};

#endif