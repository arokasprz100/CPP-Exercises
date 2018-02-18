#ifndef strop_h
#define strop_h

struct delimited
{
    char wholeString[256];
    char nextFragment[256];

    char *current;

    char delimiter;
};

void chunk (const char *str, delimited* helpStruct, char character);

bool next (delimited* helpStruct);

void part (delimited* helpStruct, char *buffer);

#endif // strop_h
