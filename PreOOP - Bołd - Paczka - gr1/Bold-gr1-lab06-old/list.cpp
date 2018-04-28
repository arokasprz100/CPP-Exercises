#include "list.h"
#include <iostream>

List::List()
{
    head=0;
}


void List::addToList (Scope* ptrToScope)
{
    if (head==0)
    {
        head=ptrToScope;
        return;
    }
    Scope* temp=head;
    while (temp->next!=0)
        temp=temp->next;
    temp->next = ptrToScope;

}

void List::print()
{
    using namespace std;
    Scope *temp=head;
    while (temp!=0)
    {
        cout<<"["<<temp->_function<<":"<<temp->_line<<":"<<temp->_message<<"]";
        temp=temp->next;

    }
    cout<<endl;
}

void List::deleteLast()
{
    if (head==0)
        return;
    if (head->next == 0)
    {
	    delete head;
	    head = 0;
	    return;
    }
    Scope* temp1=head;
    Scope* temp2=head;
    while (temp1->next!=0)
    {
        temp2=temp1;
        temp1=temp1->next;
    }
    delete temp1;
    temp2->next=0;

}
