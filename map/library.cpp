#include"library.h"

std::ostream& operator<< (std::ostream& ostr, const  Library& library)
{
	ostr << library.m_author << ", " << library.m_category << ", " << library.m_number_of_pages << ", Dostepnosc " << library.m_in_out;
	return ostr;
}
Library::Library(const std::string& author, const std::string& category, int pages, bool in_out)
	:m_author(author)
	, m_category(category)
	, m_number_of_pages(pages)
	, m_in_out(in_out)
{
}