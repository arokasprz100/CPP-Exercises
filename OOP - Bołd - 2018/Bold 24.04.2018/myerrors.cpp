#include "myerrors.h"

void myerrors::handler()
{
	try
	{
		throw;
	}
	catch(std::runtime_error* error)
	{
		std::cout<<"Wyjatek w: ";
		calc_error* temp = dynamic_cast<calc_error*>(error);
		std::cout<<temp->what()<<std::endl;
		calc_error* temp2 = temp;
		temp = dynamic_cast<calc_error*>(temp->m_error);
		delete temp2;
			
		while (temp)
		{
			std::cout<<"z powodu : "<<temp->what()<<std::endl;
			temp2 = temp;
			temp = dynamic_cast<calc_error*>(temp->m_error);
			if (!temp)
			{
				std::cout<<"z powodu : "<<temp2->m_error->what()<<std::endl;
				delete temp2->m_error;
			}
			delete temp2;
		}
	}
}