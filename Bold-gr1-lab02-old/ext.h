#ifndef ext_h
#define ext_h

struct Ext
{
    int *intVector;
    int(*ptrToMethod)(int);
    int currentSize;
    int currentCap;
};

void init (Ext* vec);

void init_with_size_and_policy(Ext* vec, int siz, int(*ptrToFunction)(int));

void insert (Ext* vec, int value);

int size (Ext *vec);

int capacity (Ext *vec);

int at (Ext *vec, int index);

void print(int *val);

void zero (int *val);

void for_each_element(Ext *vec, void(*fun)(int*));

Ext *clone (Ext* vec);

void clear (Ext *vec);


#endif // ext_h
