#include "Register.h"
#include "ComplexNumber.h"
#include <iostream>

ComplexNumber* Register::storedNumber = 0;
Register* Register::ptrToSelf = 0;

void Register::Clear()
{
    if (storedNumber!=0)
    {
        delete storedNumber;
        storedNumber = 0;

    }
    if (ptrToSelf!=0)
    {
        delete ptrToSelf;
        ptrToSelf = 0;

    }

}

Register& Register::Retrieve()
{
    if (ptrToSelf == 0)
    {
        ptrToSelf = new Register;
    }
    return *ptrToSelf;
}

Register::Register()
{
    std::cout<<"Creating register"<<std::endl;
    storedNumber = 0;
    ptrToSelf = this;

}


void Register::Print() const
{
    if (storedNumber==0)
        std::cout<<"Register is empty"<<std::endl;
    else
    {
        std::cout<<"Register stores number: ";
        storedNumber->Print();
    }
}


void Register::Write(ComplexNumber& writen)
{
    if (storedNumber==0)
        storedNumber = new ComplexNumber(writen);
    else
    {
        storedNumber->m_real = writen.m_real;
        storedNumber->m_imaginary = writen.m_imaginary;
    }
}

ComplexNumber Register::Read() const
{
    if (storedNumber)
        return *storedNumber;
    else
        return ComplexNumber(0,0);
}
