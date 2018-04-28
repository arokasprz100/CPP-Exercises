#include "StringWrapper.h"
#include <iostream>

StringWrapper::StringWrapper (const char * stringToStore)
{
    int length = StringLength(stringToStore);
    storedString = new char [length];
    for (int i=0; i<length; ++i)
        storedString[i] = stringToStore[i];

}

int StringWrapper::StringLength(const char *measuredString)
{
    int length = 0;
    while (measuredString[length]!='\0')
        length++;
    return length+1;
}

StringWrapper::operator const char*()
{
    return storedString;
}

bool StringWrapper::eq (const char * oneString, const char * otherString)
{
    int length1 = StringLength(oneString);
    int length2 = StringLength(otherString);
    if (length1!=length2)
    {
        std::cout<<"Not equal length"<<std::endl;
        return false;

    }
    for (int i=0; i<length1; i++)
    {
        if (oneString[i]==otherString[i])
            i++;
        else
            return false;

    }
    return true;
}

bool StringWrapper::eqIcase (const char * oneString, const char * otherString)
{
    int length1 = StringLength(oneString);
    int length2 = StringLength(otherString);
    if (length1!=length2)
    {
        std::cout<<"Not equal length"<<std::endl;
        return false;
    }
    for (int i=0; i<length1; i++)
    {
        if (oneString[i]==otherString[i])
            i++;
        else if (oneString[i] >='A' && oneString[i] <='Z')
        {
            if (oneString[i]+('a'-'A') == otherString[i])
                i++;
            else
                return false;
        }
        else if (otherString[i] >='A' && otherString[i] <='Z')
        {
            if (otherString[i]+('a'-'A') == oneString[i])
                i++;
            else
                return false;
        }

    }
    return true;



}

void print (const StringWrapper& printed)
{
    std::cout<<printed.storedString<<std::endl;
}


StringWrapper& StringWrapper::append (const char *newFragment)
{
    int oldlength = StringLength(storedString);
    char * temp = new char [oldlength];
    for (int i=0; i<oldlength; i++)
        temp[i] = storedString[i];
    delete [] storedString;

    int newlength = oldlength-1 + StringLength(newFragment);
    storedString = new char [newlength];
    for (int i=0; i<oldlength-1; i++)
        storedString[i] = temp[i];
    delete [] temp;
    for (int i=0; i<newlength-oldlength+1; i++)
    {
        storedString[i+oldlength-1] = newFragment[i];
    }

    return *this;

}

StringWrapper::StringWrapper (const StringWrapper& copied)
{
    int length = StringLength(copied.storedString);
    storedString = new char [length];
    for (int i=0; i<length; ++i)
        storedString[i] = copied.storedString[i];
}

StringWrapper::~StringWrapper()
{
    delete [] storedString;
    storedString = 0;
}
