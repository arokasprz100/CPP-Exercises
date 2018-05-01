#ifndef Fraction_h
#define Fraction_h

/// Simple fraction implementation
struct Fraction 
{
	int m_numerator;
	int m_denominator;
	int m_intPart;

};

/// Array size, we make assumption that there can be only one array at the time
extern int arraySize;

/// Sets fraction parameters
void SetFraction (Fraction** toSet, int numerator, int denominator);

/// Prints one fraction
void Print (const Fraction* printed);

/// Adds to fractions, returns result
Fraction Sum(const Fraction* lhs, const Fraction* rhs);

/// Adds fraction to array - it makes a copy using new operator - 
/// fraction in array is not the same fraction as the one in argument
void AddToArray(Fraction*** array, Fraction* toAdd, bool alloc = true);

/// Prints whole fraction array
void PrintArray(Fraction** array);



////////////////////////////////////
/////// -- Createors.cpp -- ////////
////////////////////////////////////

/// Creates fraction - uses new operator and returns pointer
Fraction* CreateFraction (int numerator, int denominator);

/// Returns nullptr - our array is empty at the start
Fraction** CreateArray();

/// Creates fraction and adds it to our array - uses other functions, allocates
/// memory
void CreateAddToArray(Fraction***array, int numerator, int denominator);



////////////////////////////////////
/////// -- Destroyers.cpp -- ///////
////////////////////////////////////

/// Destroys fraction - dealocates memory
/// Uses delete operator
void DestroyFraction (Fraction* frac);

/// Clears array - deletes all fractions in it (delete operator)
/// and deletes array itself (delete [] operator)
/// Sets array pointer to nullptr
/// Makes global arraySize equal 0
void ClearArray(Fraction*** array);



#endif