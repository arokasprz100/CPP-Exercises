#include "PersonList.h"

PersonList::PersonList()
{
    head = 0;
}

void PersonList::addPerson (const char *newName, const char *newFamily)
{
    if (head == 0)
    {
        head = new PersonListNode;
        head->nextPerson = 0;
        head->thisPerson = new Person (newName, newFamily);
        return;
    }

    PersonListNode *temp = head;
    while (temp->nextPerson!=0)
        temp=temp->nextPerson;
    temp->nextPerson = new PersonListNode;
    temp->nextPerson->nextPerson=0;
    temp->nextPerson->thisPerson= new Person (newName, newFamily);
}


PersonList::~PersonList()
{
    if (head == 0)
        return;
    PersonListNode *temp = head;
    PersonListNode *temp2 = head;
    while (temp->nextPerson!=0)
    {
        temp2=temp->nextPerson;
        delete temp->thisPerson;
        delete temp;
        temp=temp2;
    }
    delete temp->thisPerson;
    delete temp;
    head = 0;
}

PersonList::Iterator PersonList::getIterator()
{
    Iterator iterate;
    iterate.iter = head;

    return iterate;

}

Person& PersonList::Iterator::obj()
{
    return *iter->thisPerson;
}

bool PersonList::Iterator::isValid()
{
    if (iter==0)
        return false;
    return true;
}

void PersonList::Iterator::moveToNext()
{
    iter=iter->nextPerson;
}

