#ifndef List_h
#define List_h

#include <typeinfo>
#include "TNode.h"

/// Class representing polymorphic list - 
/// it can store data of any type at the same 
/// time. List can be traversed in one 
/// direction. List handles whole memory
/// management - there is no need to manualy
/// delete its nodes.
class List
{
public:
	/// Basic constructor, sets head pointer 
	/// to equal nullptr.
	List():
		m_head(nullptr) {}

	/// Method template used for adding next node to
	/// list. It uses new operator to allocate 
	/// memory for new TNode<T>
	template <typename T>
	void add(T value);

	/// Returns pointer to first node in list.
	Node* head();

	/// Static method that enables access to 
	/// value stored in given node - it 
	/// uses dynamic_cast, co RTTI must
	/// be allowed to use it
	template <typename T>
	static const T& get(Node* node);

	/// List destructor - it handles memory management - 
	/// deletes first node if its not nullptr - and 
	/// because of node construction, every other node
	/// is also deleted, so the memory is fully freed.
	~List();

private: /// fields
	
	/// Pointer to first node in list
	Node * m_head;

};

/// Methods implementation

template <typename T>
void List::add(T value)
{
	TNode<T>* newNode = new TNode<T>(value);
	newNode->next() = m_head;
	m_head = newNode;
}

Node* List::head() 
{
	return m_head;
}

template <typename T>
const T& List::get(Node* node)
{	
	TNode<T> * newNodePtr = dynamic_cast<TNode<T>*>(node);
	return newNodePtr->get();
}

List::~List()
{
	if (m_head)
		delete m_head;
}



#endif