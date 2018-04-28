#include "Book.h"
#include <iostream>

Book::Book(std::string title):
	m_author("anonym"), m_currentPage(1)
{
	m_storedPages.emplace_back(Page(title));
}

void Book::AddPage(const Page* added)
{
	m_storedPages.emplace_back(*added);
}


void Book::Print() const
{
	std::cout<<"Book::autor "<<m_author<<std::endl;
	for (unsigned i = 0; i<m_storedPages.size(); ++i)
		std::cout<<"Page("<<i<<")::text "<<m_storedPages.at(i).GetText()<<"(header: "<<m_storedPages.at(i).GetHeader()<<")"<<std::endl;
	std::cout<<std::endl;
}

void Book::Copy (const Book* copied)
{
	m_author = "(copy) " + copied->m_author;
	m_storedPages = copied->m_storedPages;
	m_currentPage = copied->m_currentPage;
}

void Book::AddTitle(std::string title)
{
	m_storedPages.at(0).AddText("Title: " + title);
}

void Book::AddHeader(std::string header)
{
	for (unsigned i =1; i<m_storedPages.size(); ++i)
		m_storedPages.at(i).AddHeader(header);
}

void Book::AddText(std::string text)
{
	if (m_currentPage < m_storedPages.size())
	{
		m_storedPages.at(m_currentPage).AddText(text);
		m_currentPage++;
	}
	else
	{
		std::cout<<"[ERROR]:: No enough pages in the book!"<<std::endl;
		std::cout<<std::endl;
	}
}