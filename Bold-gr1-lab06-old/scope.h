#ifndef scope_h
#define scope_h


class scope_id
{
public:
    scope_id (const char *fun, int line, const char* message);
    ~scope_id();


};

#define ENTER_SCOPE(fun, line, com) scope_id a(fun, line, com)

class List;

class Scope
{
    friend class List;
private:
    char * _function;
    char * _message;
    int _line;
    Scope* next;
    int strLength(const char *str);
    void strCopy (char ** dest, const char** src, int length);

public:
    Scope (const char* function, int line, const char* message);
    ~Scope();

};

#endif // scope_h
