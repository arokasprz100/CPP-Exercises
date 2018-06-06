#ifndef Vect_h
#define Vect_h

#include "Swap.h"
#include "IsPod.h"

/// This class implements vector that can
/// store data of type T
template <typename T>
class Vect
{
public:
	/// Constructor - allocates memory for vector
	/// Its argument provides number of elements 
	/// to be stored. This container handles memory
	/// allocation - there is no need for used to
	/// delete elements stored here
	Vect(unsigned numberOfElements);

	/// Overloaded operator [] that enables access
	/// to stored data - index specified, which 
	/// element in vector to access
	T& operator [] (int index);

	/// Returns number of stored elements
	unsigned size() const;

	/// Sorting using simple bubble sort algorithm. It uses
	/// different swaps for types that are POD and for types
	/// that are non - POD
	void buble_sort(bool (*porownanie)(const T&, const T&));
	
	/// Destructor, frees memory allocated in constructor 
	~Vect();

private: /// fields

	/// Stored data
	T* m_data;

	/// Number of elements stored in vector (size of vector)
	unsigned m_numberOfElements;
};


/// Method implementation

template <typename T>
Vect<T>::Vect(unsigned numberOfElements):
	m_numberOfElements(numberOfElements)
{
	m_data = new T [m_numberOfElements];
}

template <typename T>
T& Vect<T>::operator [] (int index)
{
	return m_data[index];
}

template <typename T>
unsigned Vect<T>::size() const
{
	return m_numberOfElements;
}

template <typename T>
void Vect<T>::buble_sort(bool (*porownanie)(const T&, const T&))
{
	for (unsigned i = 0; i < m_numberOfElements; i++ )
		for (unsigned j = i+1; j < m_numberOfElements; ++j ) 
  			if (porownanie(m_data[i], m_data[j]))
  				Swap<T, is_pod<T>::value>::swap(&m_data[i], &m_data[j]);
}

template <typename T>
Vect<T>::~Vect()
{
	delete [] m_data;
}

#endif