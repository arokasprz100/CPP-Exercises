#include "ComplexNumber.h"
#include <iostream>

ComplexNumber::ComplexNumber(int real, int imaginary)
{
    m_real = real;
    m_imaginary = imaginary;
    std::cout<<"Creating number: "<<m_real<<" + "<<m_imaginary<<"i"<<std::endl;
}

void ComplexNumber::Print() const
{
    std::cout<<m_real<<" + "<<m_imaginary<<"i"<<std::endl;
}

ComplexNumber& ComplexNumber::SetReal(int newReal)
{
    m_real = newReal;
    return *this;
}

ComplexNumber& ComplexNumber::SetImaginary (int newImaginary)
{
    m_imaginary = newImaginary;
    return *this;
}

ComplexNumber::ComplexNumber (const ComplexNumber& copied)
{
    m_real = copied.m_real;
    m_imaginary = copied.m_imaginary;
}

ComplexNumber::~ComplexNumber()
{
    std::cout<<"Deleting: ";
    Print();
}

void ComplexNumber::Save (Register& savePlace)
{
    savePlace.Write(*this);
}

ComplexNumber ComplexNumber::Add(const ComplexNumber& added) const
{
    return ComplexNumber(m_real + added.m_real, m_imaginary + added.m_imaginary);
}
