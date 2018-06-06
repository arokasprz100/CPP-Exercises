#ifndef Matrix_h
#define Matrix_h

#include <iostream> /// std::ostream, std::endl

/// This first part (two forward declarations) is for friend operator to work correctly 
/// when defined outside class 
/// Full explanation: https://en.cppreference.com/w/cpp/language/friend#Template_friends

/// Forward declaration to make function declaration below possible
template <typename T, int m_x, int m_y>
class Matrix;

/// Function declatation for any T, m_x, m_y
template <typename T, int m_x, int m_y>
std::ostream& operator<<(std::ostream& stream, Matrix<T,m_x,m_y>& printed);

////////////////////////////////////////////////////////////////////////


/// Class template representing matrix that stores information
/// of type T
template <typename T, int m_x, int m_y>
class Matrix
{
public:
	/// Default constructor, sets all elements to T()
	Matrix();

	/// Reset function - sets all elements to value
	void reset(T value);

	/// Function that adds two matrices that have the same size
	template <typename U>
	void add(Matrix<U, m_x, m_y>& added);

	/// Access to matrix element
	template <int a, int b>
	T& at();

	/// All Matrices are friend classes
	template <typename U, int a, int b> friend class Matrix;

	// refers to a full specialization for this particular T , m_x and m_y
	friend std::ostream& operator<< <T, m_x, m_y>(std::ostream& stream, Matrix<T,m_x,m_y>& printed);

private:
	T m_data[m_x][m_y];

};


template <typename T, int m_x, int m_y>
std::ostream& operator<<(std::ostream& stream, Matrix<T,m_x,m_y>& printed)
{
	for (int i = 0; i < m_x; ++i){
		stream<<" ";
		for (int j = 0; j < m_y; ++j)
			stream << printed.m_data[j][i]<<" ";
		stream << std::endl;
	}
	return stream;
}


template <typename T, int m_x, int m_y>
Matrix<T,m_x,m_y>::Matrix()
{
	for (int i = 0; i < m_x; ++i)
		for (int j = 0; j < m_y; ++j)
			m_data[i][j] = T();
}


template <typename T, int m_x, int m_y>
void Matrix<T,m_x,m_y>::reset(T value)
{
	for (int i = 0; i < m_x; ++i)
		for (int j = 0; j < m_y; ++j)
			m_data[i][j] = value;
}

template <typename T, int m_x, int m_y>
template <typename U>
void Matrix<T,m_x,m_y>::add(Matrix<U, m_x, m_y>& added)
{
	for (int i = 0; i < m_x; ++i)
		for (int j = 0; j < m_y; ++j)
			m_data[i][j] += added.m_data[i][j];
}

template <typename T, int m_x, int m_y>
template <int a, int b>
T& Matrix<T,m_x,m_y>::at()
{
	return m_data[a][b];
}

#endif