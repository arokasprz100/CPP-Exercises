#include "scope.h"
#include "list.h"

#include "globals.h"
#include <iostream>

scope_id::scope_id (const char *fun, int line, const char* message)
{
    using namespace std;
    Scope* newScope = new Scope (fun, line, message);
    globalList.addToList(newScope);
    cout<<"entering: ";
    globalList.print();


}

scope_id::~scope_id()
{
    using namespace std;
    cout<<"leaving: ";
    globalList.print();
    globalList.deleteLast();

}


Scope::Scope (const char* function, int line, const char* message)
{
    int flength = strLength(function);
    int mlength = strLength(message);

    _line = line;
    _function = new char [flength];
    _message = new char [mlength];

    strCopy(&_function, &function, flength);
    strCopy(&_message, &message, mlength);

    next = 0;
}

int Scope::strLength(const char *str)
{
    int i=0;
    while (str[i]!=0)
        i++;
    return i+1;
}

void Scope::strCopy (char ** dest, const char** src, int length)
{
    for (int i=0; i<length; i++)
    {
        (*dest)[i] = (*src)[i];
    }
}

Scope::~Scope()
{
    delete [] _message;
    delete [] _function;
}
