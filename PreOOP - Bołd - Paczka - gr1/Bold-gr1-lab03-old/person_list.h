#ifndef person_list_h
#define person_list_h

#include "person.h"


struct person_list
{
    person* first_person;
    int size_of_list;

};

typedef person* person_list_iter;


void init_person_list(person_list* List);
void add_person(person_list* List, const char *name, const char* family);

person* get_iterator(person_list* List);
bool is_valid (person_list_iter iter);
void move_to_next (person_list_iter* iter);
void clean (person_list* List);


#endif // person_list_h
