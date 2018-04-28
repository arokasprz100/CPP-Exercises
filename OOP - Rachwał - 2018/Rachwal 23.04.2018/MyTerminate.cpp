#include "MyTerminate.h"
#include <cstdio>
#include <iostream>
#include <exception>

void MyTerminate()
{
	std::cout<<"--- UWAGA: blad mechanizmu wyjatkow ---"<<std::endl;
	exit(0);
}

