#ifndef LIBRARY_H
#define LIBRARY_H
#include <string>
#include <iostream>
class Library
{
public:
	Library(const std::string& author, const std::string& category, int pages, bool in_out);
	friend std::ostream& operator<< (std::ostream& ostr, const  Library& library);
	friend int main();
private:

	std::string m_author;
	std::string m_category;
	int m_number_of_pages;
	bool m_in_out;

};

 std::ostream& operator<< (std::ostream& ostr, const  Library& library);
#endif // !LIBRARY_H

