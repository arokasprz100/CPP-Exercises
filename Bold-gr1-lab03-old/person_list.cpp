#include "person_list.h"
#include <cstring>

void init_person_list(person_list* List)
{
    List->first_person = 0;
}

void add_person(person_list* List, const char *name, const char* family)
{
    if (List->first_person==0)
    {
        List->first_person=new person;
        int length = strlen(name)+1;
        List->first_person->name  = new char [length];
        for (int i=0; i<length-1; i++)
            List->first_person->name[i]=name[i];
        List->first_person->name[length-1]='\0';

        length= strlen(family)+1;
        List->first_person->family = new char [length];
        for (int i=0; i<length-1; i++)
            List->first_person->family[i]=family[i];
        List->first_person->family[length-1]='\0';


        List->first_person->next=0;
        List->size_of_list=1;
    }
    else
    {
        person* temp = List->first_person;
        while (temp->next!=0)
            temp=temp->next;
        temp->next = new person;
        int length = strlen(name)+1;
        temp->next->name  = new char [length];
        for (int i=0; i<length-1; i++)
            temp->next->name[i]=name[i];
        temp->next->name[length-1]='\0';

        length= strlen(family)+1;
        temp->next->family = new char [length];
        for (int i=0; i<length-1; i++)
            temp->next->family[i]=family[i];
        temp->next->family[length-1]='\0';


        temp->next->next=0;
        List->size_of_list++;
    }
}

person* get_iterator(person_list* List)
{
    return List->first_person;
}

bool is_valid (person_list_iter iter)
{
    if (iter!=0)
        return true;
    else
        return false;
}

void move_to_next (person_list_iter* iter)
{
    (*iter)=(*iter)->next;
}

void clean (person_list* List)
{
    person * temp1 = List->first_person;
    person * temp2 = List->first_person;
    while (temp1!=0)
    {
        temp2=temp1;
        temp1=temp1->next;
        delete [] temp2->name;
        delete [] temp2->family;
        delete temp2;

    }
    List->size_of_list=0;
}
