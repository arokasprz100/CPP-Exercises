#include "Ksztalt.h"

std::ostream& operator << (std::ostream& stream, const Ksztalt* printed)
{
	printed->print(stream);
	return stream;
}

std::ostream& operator << (std::ostream& stream, const Ksztalt** printed)
{
	for (unsigned i = 0; i < printed[0]->N(); ++i)
		std::cout << printed[i];;

	return stream;
}