#ifndef list_h
#define list_h

#include "scope.h"

class List
{
private:
    Scope * head;
public:
    List();
    //~List();
    void addToList (Scope* ptrToScope);
    void print();
    void deleteLast();

};

#endif // list_h
