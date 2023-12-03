// Chapter 23 PPP using CPP - Task 3
// rj baldwin 28/07/2023
/*
2. Add a multimap and have it hold subjects. Let the program take an input string from the keyboard and print out every
message with that string as its subject.
*/


#include<string>
#include<vector>
#include<map>
#include<fstream>
#include<iostream>
#include<regex>

using std::string;
using std::vector;
using std::map;
using std::fstream;
using std::iostream;
using std::cout;
using std::multimap;
using std::ifstream;


// typedef vector<string>::const_iterator Line_iter;
using Line_iter = vector<string>::const_iterator;

class Message
{
	// a Message points to the first and last lines of a message

	Line_iter first;  // vector iterators (const)
	Line_iter last;

public:
	Message(Line_iter p1, Line_iter p2)
		:first{p1},
		last{p2}{}

	Line_iter begin() const { return first; }
	Line_iter end() const { return last; }


	//...
};


//======================================================================================

using Mess_iter = vector<Message>::const_iterator;

struct Mail_file
{
	// a Mail_file holds all the lines from a file 
	// and simplifies access to messages
	string name;	// file name
	vector<string> lines;	// the lines in order
	vector<Message> m;		// Messages in order

	Mail_file(const string& n);	// reaad file n into lines
	
	Mess_iter begin() const { return m.begin(); }
	Mess_iter end() const { return m.end(); }


};








// helper functions 


int is_prefix(const string& s, const string& p)
// is p the first part of s?
{
	int n = p.size();
	if (string(s, 0, n) == p) 
		
		return n;


	return 0;
	
}


// find the name of the sender in a message;
// return true if found
// if not,  place the sender's name in s:

bool find_from_addr(const Message* m, string& s)
{
	for (const auto& x :*m)
		if (int n = is_prefix(x, "From: "))
		{
			s = string(x, n);
			return true;
		}
	return false;
};


// return the subject of the message, if any, otherwise "":


string find_subject(const Message* m)
{
	std::regex pattern {R"(^Subject:\s?(.+)$)"};


	for (const auto& x : *m)
	{
		std::smatch matches;
		if (std::regex_search(x, matches, pattern))
		{
			return matches[1];
		}
	}
	
};



// implementation 

Mail_file::Mail_file(const string& n)
// open file named n
// read the lines from n into lines
// find the messages in the lines and compose them in m
// for simplicity assume every message is ended by a ---- line
{
	ifstream in{ n };		//  open the file
	if (!in)
	{
		std::cerr << "no " << n << '\n';	
		exit(1);			// terminate the programme 
	}

	for (string s; getline(in, s);)		// build the vector of lines
		lines.push_back(s);




	auto first = lines.begin();			// build the vector of messages
	for (auto p = lines.begin(); p != lines.end(); ++p)
	{
		if (*p == "----")
		{
			// end of message
			m.push_back(Message(first, p));
			first = p + 1;	// ---- not part of message
		}
	}

	
}




int main()
{
	Mail_file mfile{ "my-mail-file.txt" };		// initialise mfile from a file 

	// first gather messages from each sender together in a multimap:

	multimap<string, const Message*> sender;

	
	for (const auto& m : mfile)
	{
		string s;
		if (find_from_addr(&m, s))
			sender.insert(make_pair(s, &m));
		
	}

	// now iterate through the multimap
	// and extract the subjects of john doe's messages:

	auto pp = sender.equal_range("John Doe <jdoe@machine.example>");
	for (auto p = pp.first; p != pp.second; ++p)
		cout << find_subject(p->second) << '\n';



	multimap<string, const Message*> subject;

	for (const auto& m : mfile)
	{
		string s = find_subject(&m);

		if (s.size())
			subject.insert(make_pair(s, &m));

	}



};




