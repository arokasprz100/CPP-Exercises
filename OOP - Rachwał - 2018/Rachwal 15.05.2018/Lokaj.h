#ifndef Lokaj_h
#define Lokaj_h

#include "Pomieszczenie.h"

/// Typdef na wskazniki na metody "sprzatajace" z klasy pomieszczenie
typedef void (Pomieszczenie::*funkcja)() const;

template <funkcja fun> 
void Lokaj(const Pomieszczenie& pom)
{
	std::cout<<"Pomieszczenie "<<pom.daj_nazwe()<<" jest zamkniete."<<std::endl;
}

template <funkcja fun>
void Lokaj(Pomieszczenie& pom)
{
	(pom.*fun)();
}

template <int N>
void Lokaj(Pomieszczenie& pom)
{
	std::cout<<"Nic nie robie."<<std::endl;
}



#endif