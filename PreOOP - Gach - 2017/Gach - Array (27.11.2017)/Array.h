#ifndef Array_h
#define Array_h

struct Array
{
    int **arr;
    int *arrOfSizes;
    int number;

    Array *ptrToSelf;

};

Array& CreateArray(const int * sizes, int numberOfSizes);
void FillWith (Array& filled, int value);
void Print (Array& printed);
void SetElement(int x, int y, Array *toSet, int value);
void PrintMax (Array& printed);
void Clear (Array &cleared);

#endif // Array_h
