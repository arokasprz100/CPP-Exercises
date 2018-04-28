#ifndef Register_h
#define Register_h

class ComplexNumber;

class Register
{
public:
    friend class ComplexNumber;

    static void Clear();
    static Register& Retrieve();
    void Print() const;
    void Write(ComplexNumber& writen);
    ComplexNumber Read() const;

private:
    static ComplexNumber* storedNumber;
    static Register *ptrToSelf;
    Register();


};


#endif // Register_h
