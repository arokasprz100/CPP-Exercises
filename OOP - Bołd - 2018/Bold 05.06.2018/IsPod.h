#ifndef IsPod_h
#define IsPod_h

/// Type trait - function operating on
/// types that checks if type T is pod - 
/// rest of implementation in vtest.cpp file
/// This one handles situations, when type is 
/// not POD
template <typename T>
struct is_pod
{
	static const bool value = false;
};

#endif