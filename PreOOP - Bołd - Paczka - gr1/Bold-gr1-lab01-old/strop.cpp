#include "strop.h"


void chunk (const char *str, delimited* helpStruct, char character)
{
    int i=0;
    while (str[i]!='\0')
    {
        helpStruct->wholeString[i]=str[i];
        i++;
    }
    helpStruct->wholeString[i]='\0';

    helpStruct->delimiter=character;

    helpStruct->nextFragment[0]='\0';

    helpStruct->current=&(helpStruct->wholeString[0]);
}

bool next (delimited* helpStruct)
{
    if (helpStruct->current[0]=='\0')
        return false;

    int i=0;
    while (helpStruct->current[i]!=helpStruct->delimiter && helpStruct->current[i]!='\0')
    {
        helpStruct->nextFragment[i]=helpStruct->current[i];
        i++;
    }
    helpStruct->nextFragment[i]='\0';
    if (helpStruct->current[i]!='\0')
        helpStruct->current=&helpStruct->current[i+1];
    else
        helpStruct->current=&helpStruct->current[i];

    return true;

}

void part (delimited* helpStruct, char *buffer)
{
    int i=0;
    while (helpStruct->nextFragment[i]!='\0')
    {
        buffer[i]=helpStruct->nextFragment[i];
        i++;

    }
    buffer[i]='\0';
}
