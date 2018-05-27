#ifndef Map_h
#define Map_h

#include <string>
#include <stdexcept>

template <typename T, typename U>
class Map
{
public:
	Map() 
		: m_keys(nullptr), m_values(nullptr), m_numberOfStored(0) {}

	void insert(T key, U value);

	void print (std::string printedString);

	U& operator [] (const T& key);

	const U& operator [] (const T& key) const;

	bool contains(const T& key) const;

	~Map();

private:
	T* m_keys;
	U* m_values;

	int m_numberOfStored;
};

/// Method implementation

template <typename T, typename U>
void Map<T,U>::insert(T key, U value)
{
	T* tempKeys = new T [m_numberOfStored + 1];
	U* tempVals = new U [m_numberOfStored + 1];
	for (int i = 0; i<m_numberOfStored; ++i)
	{
		tempKeys[i] = m_keys[i];
		tempVals[i] = m_values[i];
	}
	if (m_numberOfStored)
	{
		delete [] m_keys;
		delete [] m_values;
	}
	tempKeys[m_numberOfStored] = key;
	tempVals[m_numberOfStored] = value;
	m_keys = tempKeys;
	m_values = tempVals;
	m_numberOfStored++;
}

template <typename T, typename U>
void Map<T, U>::print (std::string printedString)
{
	for (int i = 0; i<m_numberOfStored; ++i)
		std::cout<<printedString<<" k: "<<m_keys[i]<<" v: "<<m_values[i]<<std::endl;
}

template <typename T, typename U>
U& Map<T, U>::operator [] (const T& key)
{
	for (int i = 0; i<m_numberOfStored; ++i)
		if (m_keys[i] == key)
			return m_values[i];

	insert(key, U());
	return m_values[m_numberOfStored-1];
}

template <typename T, typename U>
const U& Map<T, U>::operator [] (const T& key) const
{
	for (int i = 0; i<m_numberOfStored; ++i)
		if (m_keys[i] == key)
			return m_values[i];	
	throw std::invalid_argument("Klucz nieodpowiedni");
}

template <typename T, typename U>
bool Map<T, U>::contains(const T& key) const
{
	for (int i = 0; i<m_numberOfStored; ++i)
		if (m_keys[i] == key)
			return true;
	return false;
}

template <typename T, typename U>
Map<T, U>::~Map() 
{
	delete [] m_keys;
	delete [] m_values;
}

#endif