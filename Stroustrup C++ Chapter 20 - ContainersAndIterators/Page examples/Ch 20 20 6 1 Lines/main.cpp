#include <iostream>
#include <list>
#include <vector>


using std::vector;
using std::list;

using Line = vector<char>;		// a line is a vector of characters



//=============================
//	TEXT ITERATOR CLASS
//=============================

class Text_iterator			// keep track of line and character position within a line
{
	list<Line>::iterator ln;		// a list of char vectors' iterator.  keeps track of the current line within the text.
	Line::iterator pos;             // keeps track of the current character position within the current line.

public:
	// start the iterator at line II's character position pp:

	Text_iterator(list<Line>::iterator II, Line::iterator pp)
		:ln{ II }, pos{ pp } {}

	char& operator*() { return *pos; }

	Text_iterator& operator++();

	bool operator==(const Text_iterator& other) const
	{
		return ln == other.ln && pos == other.pos;
	}

	bool operator!=(const Text_iterator& other) const
	{
		return !(*this == other);
	}
};





Text_iterator& Text_iterator::operator++()
{
	++pos;			//proceed to next character
	if (pos == (*ln).end())
	{
		++ln;		// proceed to next line
		pos = (*ln).begin();		// bad if ln==line.end(); so make sure it isn't
	}
	return *this;
}





//=============================
//	DOCUMENT CLASS
//=============================

struct Document
{
	list<Line>line;				// a document is a list of lines - a list of character vectors

	Document() { line.push_back(Line{}); } // pushes back char vectors into the list - adds a blank line by default

	Text_iterator begin()		// first character of first line
		{return Text_iterator(line.begin(), (*line.begin()).begin());}

	Text_iterator end()			// one beyond the last character of the last line
	{
		auto last = line.end();
		--last;					// we know that the documenty is not empty

		return Text_iterator(last, (*last).end());
	}
};


//==========================================================



void print(Document& d)
{
	for (auto it = d.begin(); it != d.end(); ++it)
	{
		char ch = *it;
		std::cout << ch;
	}
}



//==========================================================


void erase_line(Document& d, int n)
{
	if (n < 0 || d.line.size() - 1 <= n) return;
	auto p = d.line.begin();
	advance(p, n);
	d.line.erase(p);
}


//==========================================================


// provides cin >> for the Document class

std::istream& operator>>(std::istream& is, Document& d)
{
	for (char ch; is.get(ch);)								// accepts cin >> via get().  Squirts this into line
	{
		d.line.back().push_back(ch);		// add the character - add ch to vector and add to back of last line
		if (ch == '\n')
			d.line.push_back(Line{});		// add another line 
	}

	if (d.line.back().size()) d.line.push_back(Line{});		// add final empty line
	return is;
}

//==========================================================


Text_iterator find_txt(Text_iterator first, Text_iterator last, const std::string& s)
{
	if (s.size() == 0) return last;		// can't find an empty string
	char first_char = s[0];
	while (true) {
		auto p = std::find(first, last, first_char);
		if (p == last || match(p, last, s)) return p;		// define match() myself
		first = ++p;			// look at the next chapter
	}
}


//==========================================================





int main()
{
	




	Document doc;
	std::cin >> doc;

	for (Text_iterator it = doc.begin(); it != doc.end(); ++it)
	{
		char ch = *it;
		std::cout << ch;
	}

}