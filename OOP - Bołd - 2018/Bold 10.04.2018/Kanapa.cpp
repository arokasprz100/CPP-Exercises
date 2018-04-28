#include "Kanapa.h"

void Kanapa::wypisz(std::ostream& strumien) const
{
	strumien<<"jako Mebel: ";
	Mebel::wypisz(strumien);
	strumien<<"\n jako ";
	Sofa::wypisz(strumien);
	strumien<<"\n jako ";
	Lozko::wypisz(strumien);
}


Kanapa::~Kanapa()
{
	std::cout<<"~Kanapa"<<std::endl;
}