#ifndef StringWrapper_h
#define StringWrapper_h

class StringWrapper
{
public:
    StringWrapper (const char * stringToStore);
    StringWrapper (const StringWrapper& copied);
    static bool eq (const char * oneString, const char * otherString);
    operator const char*();
    static bool eqIcase (const char * oneString, const char * otherString);
    StringWrapper& append (const char *newFragment);
    ~StringWrapper();

    friend void print (const StringWrapper& printed);

private:
    char * storedString;
    static int StringLength(const char *measuredString);
};

#endif // StringWrapper_h
