#include "Person.h"
#include <iostream>

Person::~Person()
{
    delete [] _name;
    delete [] _family;

    _name=0;
    _family=0;
}


int Person::stringLength (const char *str)
{
    int i=0;
    while (str[i]!='\0')
    {
        i++;
    }

    return i+1;
}

void Person::stringCopy (char **dest, const char  **src, int srcLength)
{
    for (int i=0; i<srcLength; i++)
    {
        (*dest)[i] = (*src)[i];
    }

}

Person::Person (const char *name, const char *family)
{
    int nameLength = stringLength(name);
    int familyLength = stringLength(family);

    _name = new char [nameLength];
    _family = new char [familyLength];

    stringCopy (&_name, &name, nameLength);
    stringCopy(&_family, &family, familyLength);

}

const char * Person::name() const
{
    return _name;
}

const char * Person::family() const
{
    return _family;
}
