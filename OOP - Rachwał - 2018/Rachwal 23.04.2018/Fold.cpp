#include "Fold.h"
#include "MyException.h"
#include <iostream>
#include "MyTerminate.h"

unsigned ReturnValueID = 0;

void Fold1(MyClass copied, int foldLevel)
{
	std::cout<<"Entering fold level "<<foldLevel<<std::endl;
	Fold2(copied, foldLevel+1);

}

void Fold2(MyClass copied, int foldLevel)
{
	std::cout<<"Entering fold level "<<foldLevel<<std::endl;
	Fold3(copied, foldLevel+1);
}

void Fold3(MyClass copied, int foldLevel)
{
	std::cout<<"Entering fold level "<<foldLevel<<std::endl;
	try
	{
		switch(ReturnValueID)
		{
			case 0:
				throw 9.242f; /// float case
			case 1:
				throw -87; /// int case
			case 2:
				throw 16u; /// unsigned case
			case 3:
				throw 3.14157; /// double case
		}

	}
	catch(float number)
	{
		std::cout<<"Caught an exception of type: float"<<std::endl;
	}
	catch(int number)
	{
		std::cout<<"Caught an exception of type: int"<<std::endl;
	}
	catch(unsigned number)
	{
		std::cout<<"Caught an exception of type: unsigned"<<std::endl;
	}
	catch(double number)
	{
		std::cout<<"Caught an exception of type: double"<<std::endl;
	}

	void (*ptrTerm)() = MyTerminate;

	std::set_terminate(ptrTerm);

	throw MyException();

	
}