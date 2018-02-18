#include "Main.h"
#include <iostream>
#include <cstdlib>

void set_student (const char fln, const char sln, int gr, Student* st)
{
    st->f_name_init=fln;
    st->s_name_init=sln;
    st->grade=gr;
    st->next=NULL;
}

void print (Student& st)
{
    std::cout<<"Initials: "<<st.f_name_init<<". "<<st.s_name_init<<".   grade: "<<st.grade<<std::endl;
}

void attach_back (Student* st1, Student* st2)
{
    Student* temp=st1;
    while (temp->next!=NULL)
        temp=temp->next;
    temp->next=(Student*)malloc(sizeof(Student));
    temp->next->f_name_init=st2->f_name_init;
    temp->next->s_name_init=st2->s_name_init;
    temp->next->grade=st2->grade;
    temp->next->next=NULL;

}

void print_all(Student* first)
{
    Student* temp=first;
    if (temp==NULL)
        return;
    while (temp->next!=NULL)
    {
        print (*temp);
        temp=temp->next;
    }
    print(*temp);
}

void clear_all(Student* first)
{
    Student* temp=first->next;
    Student* temp2=first->next;
    first->next=NULL;
    while (temp!=NULL)
    {
        temp2=temp->next;
        free(temp);
        temp=temp2;

    }
}
