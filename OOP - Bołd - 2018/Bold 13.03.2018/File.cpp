#include "File.h"

void File::print(std::ostream& placeToPrint, int numberOfSpaces) const
{
	for (int i=0; i<numberOfSpaces; ++i)
		placeToPrint<<" ";
	placeToPrint<<m_name<<std::endl;
}