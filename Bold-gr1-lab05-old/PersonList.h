#ifndef PersonList_h
#define PersonList_h

#include "Person.h"

class PersonListNode;

class PersonList
{
public:
    PersonList();
    ~PersonList();
    void addPerson (const char *newName, const char *newFamily);

    class Iterator
    {
    public:
        bool isValid();
        Person& obj();
        void moveToNext();
        PersonListNode * iter;
    };

    Iterator getIterator();


private:
    PersonListNode *head;

};

class PersonListNode
{
    friend class PersonList;
private:
    Person* thisPerson;
    PersonListNode* nextPerson;
};

#endif // PersonList_h
