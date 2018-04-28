#include "Page.h"
#include <iostream>

void Page::AddHeader(std::string addedHeader)
{
	m_header = addedHeader;
}

void Page::AddText(std::string addedText)
{
	m_text = addedText;
}

Page* Page::Copy() const
{
	return new Page(m_text, m_header);
}

void Page::Print() const
{
	std::cout<<"Page::header "<<m_header<<std::endl;
	std::cout<<"Page::text "<<m_text<<std::endl;
	std::cout<<std::endl;
}