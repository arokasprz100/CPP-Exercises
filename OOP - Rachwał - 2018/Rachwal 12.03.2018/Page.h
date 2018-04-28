#ifndef Page_h
#define Page_h

#include <string>

class Page
{
public:
	Page (std::string text = "empty", std::string header = "empty"):
		m_header(header), m_text(text) {}

	void AddHeader(std::string addedHeader);

	void AddText(std::string addedText);

	Page* Copy() const ;

	void Print() const;

	std::string GetHeader() const {return m_header;}

	std::string GetText() const {return m_text;}

private:
	std::string m_header;
	std::string m_text;


};

#endif