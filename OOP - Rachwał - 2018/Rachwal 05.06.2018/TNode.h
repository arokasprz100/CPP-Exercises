#ifndef TNode_h
#define TNode_h

#include "Node.h"

/// Class template representing list node 
/// that stores data of type T.
template <typename T>
class TNode : public Node 
{
public:
	/// Constructor, its argument represents
	/// data to be stored
	TNode(T value) :
		m_value(value), m_next(nullptr) {}

	/// Returns pointer to next node in list
	Node*& next();

	/// Returns const reference to stored value
	/// Value can not be modified
	const T& get() const;

	/// Checks if given type is the same as type
	/// of stored data
	bool checkType(const std::type_info& id);

	/// Destructor, calls delete on next pointed node
	/// if it is not set to nullptr
	virtual ~TNode();

private: /// fields

	/// Stored value of type T
	T m_value;

	/// Pointer to next Node in list
	Node * m_next;
};

/// Method implementations

template <typename T>
Node*& TNode<T>::next() 
{ 
	return m_next; 
}

template <typename T>
const T& TNode<T>::get() const 
{
	return m_value;
}

template <typename T>
bool TNode<T>::checkType(const std::type_info& id)
{
	return id == typeid(T);
}

template <typename T>
TNode<T>::~TNode() 
{
	if (m_next)
		delete m_next;
}

#endif