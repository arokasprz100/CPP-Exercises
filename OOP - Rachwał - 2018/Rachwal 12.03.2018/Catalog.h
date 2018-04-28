#ifndef Catalog_h
#define Catalog_h

#include "Book.h"

class Catalog
{
public:
	Catalog(std::string name):
		m_name(name) {}

	void AddBook(Book* added);

	void Print() const;

	~Catalog();

private:
	std::string m_name;
	std::vector <Book*> m_books;

};

#endif