#include "MyClass.h"
#include <iostream>

MyClass::MyClass (std::string name):
	m_name(name)
{
	std::cout<<"Created MyClass: "<<m_name<<std::endl;
}

MyClass::MyClass(const MyClass& copied)
{
	m_name = copied.m_name;
	m_name[2]+=1;
	std::cout<<"Copy created MyClass: "<<copied.m_name<<std::endl;
}

MyClass::~MyClass()
{
	std::cout<<"Destroyed MyClass: "<<m_name<<std::endl;
}