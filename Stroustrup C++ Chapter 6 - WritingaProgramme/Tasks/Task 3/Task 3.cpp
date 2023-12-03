//
// This is example code from Chapter 6.6 "Trying the first version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

//RJB - the following is the definition of a class called Token

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }

    
};



class Token_stream {
public:

    Token get();            // get a Token
    void putback(Token t);  // put a Token back
private:
    bool full{ false };      // is there a Token in the buffer?
    Token buffer = { '0' };           // where we store a 'putback' Token
};

void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;         // copy t to buffer
    full = true;        // buffer is now full

    //cout << "Token_stream::putback(Token t) full bool value...."  << full<<'\n';
    //cout << "*************************************************************************\n";
}

Token Token_stream::get()
{
    if (full) {
        full = false;
        //cout << "Tokenstream get, buffer status.." << full<<endl;
        //cout << "*************************************************************************\n";
        return buffer;
    }
    char ch;
    cin >> ch;

    switch (ch) {
    case '=':       // for "print"
    case 'q':       // for "quit"
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '{':
    case '}':
    case '!':       //task 3 factoral operator
        return Token{ ch };   // let each character represent itself
    case '.':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    {
        cin.putback(ch);
        double val;
        cin >> val;
        return Token{ '8', val };
    }
    default:
        error("Bad Token");
    }
}

//------------------------------------------------------------------------------

Token_stream ts;      // provides get() and putback()

//------------------------------------------------------------------------------

double expression();  // read and evaluate a Expression

//------------------------------------------------------------------------------

double term();        // read and evaluate a Term

//------------------------------------------------------------------------------

double primary()     // read and evaluate a Primary
{
    Token t = ts.get();
 
    cout << "primary() calls a token from ts and assigns to Token t. t kind = " << t.kind << " value = " << t.value << endl;
    
    cout << "*************************************************************************\n";
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
    {
        double d = expression();
        cout << "primary() calls expression ("<<d<<").  When '(' is entered...double d = " << d << '\n';
        cout << "*************************************************************************\n";
        t = ts.get();
        cout << "primary() calls a token from ts and assigns to Token t. t kind = " << t.kind << " value = " << t.value << endl;
        
        if (t.kind != ')') error("')' expected");
        return d;
    }
    case '{':    // handle '{'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != '}') error("'}' expected");
        return d;
    }
    case '8':            // we use '8' to represent a number
        cout << "PRIMARY t.value = " << t.value<<'\n';
        cout << "*************************************************************************\n";
        return t.value;  // return the number's value
        
    default:
        error("primary expected");
    }
}
//------------------------------------------------------------------------------

int main()
try {

    cout << "Welcome to the WIP calculator\n"
        << "Please enter an expression followed by '='.  Press q to terminate.\n";
    cout << "*************************************************************************\n";

    while (cin)
        cout<<"Answer = " << expression() << '\n';
    cout << "*************************************************************************\n";
    keep_window_open("~0");
}
catch (exception& e) {
    cerr << e.what() << endl;
    keep_window_open("q");
    return 1;
}
catch (...) {
    cerr << "exception \n";
    keep_window_open("~2");
    return 2;
}

//------------------------------------------------------------------------------

double expression()
{
    double leftExp = term();      // read and evaluate a Term
    cout << "expression() calls term("<<leftExp<<")'...double leftExp = " << leftExp<<". expression() now == expression("<<leftExp<<")\n";
    cout << "*************************************************************************\n";
    Token t = ts.get();        // get the next token
    while (true) {
        switch (t.kind) {
        case '+':
            cout << leftExp << " is now held in the leftExp variable of expression() and is awaiting the next calculation...\n";
            cout << "*************************************************************************\n";
            leftExp += term();    // evaluate Term and add
            cout << "expression() calls term(). A '+' was chosen. double leftExp += term() = " << leftExp << endl;
            cout << "*************************************************************************\n";
            t = ts.get();
            break;
        case '-':
            cout << leftExp << " is now held in the leftExp variable of expression() and is awaiting the next calculation...\n";
            cout << "*************************************************************************\n";
            leftExp -= term();    // evaluate Term and subtract
            cout << "expression() calls term(). A '-' was chosen. double leftExp -= term() = " << leftExp << endl;
            cout << "*************************************************************************\n";
            t = ts.get();
            break;
        default:
            ts.putback(t);
            cout << "Expression("<<leftExp<<") .finally: no more + or -: return the answer..double leftExp = " << leftExp << endl;
            cout << "*************************************************************************\n";
            return leftExp;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

double term()
{
    double leftTerm = primary();
    cout << "term() calls primary("<<leftTerm<<").  leftTerm = " << leftTerm << ". term() now == term("<<leftTerm<<") \n";
    cout << "*************************************************************************\n";
    cout << leftTerm << " is now held in the leftTerm variable of term() and is awaiting the next calculation...\n";
    cout << "*************************************************************************\n";
    Token t = ts.get();     // get the next token

    while (true) {
        switch (t.kind) {
        case '*':
            
           
            leftTerm *= primary();
            cout << "* chosen. leftTerm double of term() *= primary() = " << leftTerm << endl;
            cout << "*************************************************************************\n";
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0) error("divide by zero");
            leftTerm /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);
            return leftTerm;
        }
    }
}

//------------------------------------------------------------------------------
