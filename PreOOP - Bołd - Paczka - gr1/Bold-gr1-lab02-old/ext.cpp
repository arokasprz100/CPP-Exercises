#include "ext.h"
#include <cstdlib>
#include <iostream>

void init (Ext* vec)
{
    vec->intVector=(int*)malloc(5*sizeof(int));
    vec->ptrToMethod=NULL;
    vec->currentSize=0;
    vec->currentCap=5;
}

void init_with_size_and_policy(Ext* vec, int siz, int(*ptrToFunction)(int))
{
    vec->ptrToMethod=ptrToFunction;
    vec->currentSize=0;
    vec->currentCap=siz;
    vec->intVector=(int*)malloc(5*sizeof(int));

}

void insert (Ext* vec, int value)
{
    if (vec->currentCap==vec->currentSize)
    {
        if (vec->ptrToMethod==NULL)
        {
            vec->currentCap+=5;
            vec->intVector=(int*)realloc(vec->intVector, sizeof(int)*(vec->currentCap));
        }
        else
        {
            vec->currentCap=vec->ptrToMethod(vec->currentCap);
            vec->intVector=(int*)realloc(vec->intVector, sizeof(int)*(vec->currentCap));

        }
    }
    vec->intVector[vec->currentSize]=value;
    vec->currentSize++;
}

int size (Ext *vec)
{
    return vec->currentSize;
}

int capacity (Ext *vec)
{
    return vec->currentCap;
}

int at (Ext *vec, int index)
{
    return vec->intVector[index];
}

void print(int *val)
{
    std::cout<<*val<<" ";
}

void zero (int *val)
{
    *val=0;
}

void for_each_element(Ext *vec, void(*fun)(int*))
{
    for (int i=0; i<vec->currentSize; i++)
        fun(&(vec->intVector[i]));
}

Ext *clone (Ext* vec)
{
    Ext *newExt=new Ext;
    newExt->currentCap=vec->currentCap;
    newExt->currentSize=vec->currentSize;
    newExt->ptrToMethod=vec->ptrToMethod;
    newExt->intVector=(int*)malloc(sizeof(int)*(newExt->currentCap));
    for (int i=0; i<newExt->currentSize; i++)
        newExt->intVector[i]=vec->intVector[i];
    return newExt;
}

void clear (Ext *vec)
{
    free(vec->intVector);
    vec->currentCap=0;
    vec->currentSize=0;
    vec->ptrToMethod=0;
    vec->intVector=NULL;

}

