#ifndef Swap_h
#define Swap_h

#include <cstring> /// memcpy

/// This file contains helper structs that handle 
/// swap funtionality.

/// Struct responsible for situations, when
/// is_pod == true - should be used to swap
/// simple objects (POD)
template <typename U, bool is_pod>
struct Swap
{
	/// Swap implementation using memcpy
	static void swap (U* val1, U* val2)
	{
		U* temp = new U;
		memcpy(temp, val1, sizeof(U));
		memcpy(val1, val2, sizeof(U));
		memcpy(val2, temp, sizeof(U));
		delete temp;
	}
};


/// Struct responsible for situations, when
/// is_pod == false - should be used to swap
/// cimplec objects (non-POD)
template <typename U>
struct Swap<U, false> 
{
	/// Swap implementation that uses copy
	/// constructor and = operator
	static void swap(U* val1, U* val2)
	{
		U temp = *val1;
		*val1 = *val2;
		*val2 = temp;
	}
};


#endif