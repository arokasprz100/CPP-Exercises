#ifndef Book_h
#define Book_h

#include "Page.h"
#include <vector>

class Book 
{
public:
	Book(std::string title = "Title page");

	void AddPage(const Page* added);

	void Print() const;

	void Copy (const Book* copied);

	void AddTitle(std::string title);

	void AddHeader(std::string header);

	void AddText(std::string text);

	std::string GetTitle() const {return m_storedPages.at(0).GetText();}

private:
	std::vector<Page> m_storedPages;
	std::string m_author;
	unsigned m_currentPage;

};

#endif