#ifndef Person_h
#define Person_h

class Person
{
public:
    Person (const char *name, const char *family);
    ~Person();
    const char * name() const;
    const char *family() const ;

private:
    char* _name;
    char* _family;

    int stringLength (const char *str);
    void stringCopy (char **dest, const char **src, int srcLength);
};


#endif // Person_h
