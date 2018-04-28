#ifndef ComplexNumber_h
#define ComplexNumber_h

#include "Register.h"

class ComplexNumber
{
public:
    friend class Register;

    ComplexNumber (int real, int imaginary);
    ComplexNumber (const ComplexNumber& copied);
    ~ComplexNumber();
    void Print() const;
    ComplexNumber& SetReal(int newReal);
    ComplexNumber& SetImaginary (int newImaginary);
    void Save (Register& savePlace);
    ComplexNumber Add(const ComplexNumber& added) const ;


private:
    int m_real;
    int m_imaginary;

};

#endif // ComplexNumber_h
