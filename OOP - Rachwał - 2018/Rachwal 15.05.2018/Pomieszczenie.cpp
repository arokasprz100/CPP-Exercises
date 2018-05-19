#include "Pomieszczenie.h"

Pomieszczenie::Pomieszczenie (std::string nazwa): m_nazwaPomieszczenia(nazwa) 
{
	std::cout<<"Tworze pomieszczenie: "<<nazwa<<std::endl;
}

void Pomieszczenie::zetrzyj_kurze() const
{ 
	std::cout<<"Scieram kurze w pomieszczeniu: "<<m_nazwaPomieszczenia<<std::endl; 
}

void Pomieszczenie::umyj_podloge() const  
{ 
	std::cout<<"Myje podloge w pomieszczeniu: "<<m_nazwaPomieszczenia<<std::endl;
} 

void Pomieszczenie::odkurz() const 
{ 
	std::cout<<"Odkurzam pomieszczenie: "<<m_nazwaPomieszczenia<<std::endl; 
}

const std::string& Pomieszczenie::daj_nazwe() const 
{ 
	return m_nazwaPomieszczenia;
}