#ifndef Node_h
#define Node_h

/// Abstract class representing list Node
/// It is used for inheritance purposed 
/// - it serves as base class for TNode
// hierarchy
class Node
{
public:
	/// Method that checks if data stored by Node (TNode)
	/// is of a given type
	template <typename U> 
	bool isType();

	/// Pure virtual method - used for checking if stored data
	/// is of a given type
	virtual bool checkType(const std::type_info& id) = 0;

	/// Pure virtual method - methods from derived class should
	/// use it to return next Node in list 
	virtual Node*& next() = 0;

	/// Pure virtual destructor, does nothing
	virtual ~Node() {}
};

/// Methods implementation

template <typename U>
bool Node::isType()
{
	return checkType(typeid(U));
}

#endif