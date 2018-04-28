#include "Catalog.h"
#include <iostream>

void Catalog::AddBook(Book* added)
{
	m_books.push_back(added);
}

void Catalog::Print() const
{
	std::cout<<"Catalog::name "<<m_name<<std::endl;
	for (unsigned i = 0; i<m_books.size(); ++i){
		std::string title = m_books.at(i)->GetTitle()=="Title page" ? "dummy" : m_books.at(i)->GetTitle();
		if (title.find("Title")!= std::string::npos) title = title.substr(7);
		std::cout<<"Catalog::book("<<i<<") "<<title<<std::endl;
	}
	std::cout<<std::endl;
}


Catalog::~Catalog()
{
	for (unsigned i = 0; i<m_books.size(); ++i)
		delete m_books.at(i);
}