#include "ObiektMiotajacy.h"

void ObiektMiotajacy::Rzuc() 
{ 
	typ2* rzucany = new typ2; 
	rzucany->rzucajacy = this; 
	throw rzucany; 
}

void Przetworz(typ* przetwarzany)
{
	delete przetwarzany->rzucajacy;
	std::cout<<"Przetworz - wyjatek typu 2 o adresie: "<<przetwarzany<<std::endl;
	throw;
}