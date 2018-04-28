#include "Array.h"

#include <iostream>

Array& CreateArray(const int * sizes, int numberOfSizes)
{
    Array* ptr = new Array;
    ptr->arrOfSizes = new int [numberOfSizes];
    for (int i=0; i<numberOfSizes; i++)
    {
        ptr->arrOfSizes[i]=sizes[i];
    }

    ptr->arr=new int * [numberOfSizes];
    for (int i=0; i<numberOfSizes; i++)
    {
        ptr->arr[i]=new int [ptr->arrOfSizes[i]];
    }
    ptr->number= numberOfSizes;

    ptr->ptrToSelf=ptr;

    return *ptr;
}


void FillWith (Array& filled, int value)
{
    for (int i=0; i<filled.number; i++)
    {
        for (int j=0; j<filled.arrOfSizes[i]; j++)
        {
            filled.arr[i][j]=value;
        }
    }
}

void Print (Array& printed)
{
    using namespace std;
    for (int i=0; i<printed.number; i++)
    {
        for (int j=0; j<printed.arrOfSizes[i]; j++)
        {
            cout<<printed.arr[i][j]<<" ";
        }
        cout<<endl;
    }

}

void SetElement(int x, int y, Array *toSet, int value)
{
    if (x>=toSet->number)
    {
        std::cout<<"Index out of bounds"<<std::endl;
        return;
    }
    if (y>=toSet->arrOfSizes[x])
    {
        std::cout<<"Index out of bounds"<<std::endl;
        return;

    }
    toSet->arr[x][y]=value;
}

void PrintMax (Array& printed)
{
    using namespace std;
    cout<<"maximum"<<endl;
    int globalmax = printed.arr[0][0];
    for (int i=0; i<printed.number; i++)
    {
        cout<<"max "<<i<<": ";
        int max = printed.arr[i][0];
        for (int j=1; j<printed.arrOfSizes[i]; j++)
        {
            if (printed.arr[i][j]>max)
                max=printed.arr[i][j];
            if (printed.arr[i][j]>globalmax)
                globalmax=printed.arr[i][j];
        }
        cout<<max<<endl;
    }
    cout<<"global max: "<<globalmax<<endl;
}

void Clear (Array &cleared)
{
    for (int i=0; i<cleared.number; i++)
        delete [] cleared.arr[i];

    delete [] cleared.arr;
    delete [] cleared.arrOfSizes;

    delete cleared.ptrToSelf;

}
