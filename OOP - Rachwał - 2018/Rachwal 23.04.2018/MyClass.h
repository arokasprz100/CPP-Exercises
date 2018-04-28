#ifndef MyClass_h
#define MyClass_h

#include <string>

class MyClass
{
public:
	MyClass (std::string name);

	MyClass(const MyClass& copied);

	~MyClass();

private:
	std::string m_name;

};

#endif