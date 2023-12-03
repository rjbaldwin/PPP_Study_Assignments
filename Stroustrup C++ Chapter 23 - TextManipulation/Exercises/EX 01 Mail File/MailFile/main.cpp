// Chapter 23 PPP using CPP - Page 858 - Mail File
// rj baldwin 20/07/2023


#include<string>
#include<vector>
#include<map>
#include<fstream>
#include<iostream>

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

	// so i can print out the pointers for inspection
	friend std::ostream& operator<<(std::ostream& os, const Message& message);

	//...
};


//=============================debugging stuff - delete=================================
std::ostream& operator<<(std::ostream& os, const Message& message)
{
	// Print the pointers of the first and last lines
	os << "First Line Iterator: " << &(*message.begin()) << " " << (*message.begin()) << '\n';
	os << "Last Line Iterator: " << &(*std::prev(message.end())) << " " << (*std::prev(message.end())) << '\n';

	// Print the content of each line
	/*for (Line_iter it = message.begin(); it != message.end(); ++it)
	{
		os << *it << '\n';
	}*/

	return os;
}






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
	cout << "is_prefix return value: " << n << " " << '\n';

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
	for (const auto& x : *m)
		if (int n = is_prefix(x, "Subject: "))  return string(x, n);
	
	return "";
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

	// delete this - this is to see the contents of the vector lines
	cout << '\n';
	cout << "******************CONTENTS OF LINES***************************\n";
	for (auto& text : lines)
	{
		cout << text << " : " << &text << '\n';
	}


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

	// delete this - this is to see the contents of the vector m
	cout << '\n';
	cout << "******************CONTENTS OF M***************************\n";
	for (auto& p : m)
	{
		cout << p << '\n';
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

	// Contents of sender - delete this.  for debugging
	cout << '\n';
	cout << "******************CONTENTS OF SENDER***************************\n";
	for (const auto& pair : sender)
	{
		cout << "Pair: " << "First = " << pair.first << " - Second = " << *pair.second << '\n';
	}





	// now iterate through the multimap
	// and extract the subjects of john doe's messages:

	auto pp = sender.equal_range("John Doe <jdoe@machine.example>");
	for (auto p = pp.first; p != pp.second; ++p)
		cout << find_subject(p->second) << '\n';


};




