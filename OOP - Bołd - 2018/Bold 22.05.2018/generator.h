#ifndef generator_h
#define generator_h

template <typename T>
class generator
{
public:
	generator (T start, T (*fun)(T)):
		m_currentValue(start), m_startValue(start), m_function(fun) {}

	T& current() { return m_currentValue;}

	generator& operator++ ();

	void reset (T& newStart, T (*fun)(T));

	void reset () {m_currentValue = m_startValue;}

	operator T () {return m_currentValue;}

	T next();

private:
	T m_currentValue;
	T m_startValue;
	T (*m_function)(T);
};

template <typename T>
generator<T>& generator<T>::operator++()
{
	m_currentValue = m_function(m_currentValue);
	return *this;
}

template <typename T>
void generator<T>::reset (T& newStart, T (*fun)(T))
{
	m_currentValue = newStart;
	m_function = fun;
}

template <typename T>
T generator<T>::next() 
{ 
	++(*this);
	return m_currentValue; 
}

#endif