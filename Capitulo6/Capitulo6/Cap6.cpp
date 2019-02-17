#include "Includes.h"
#include <iostream>
using namespace std;


const char number = '8';
class Token
{

public:
	char kind;        // what kind of token
	double value;     // for numbers: a value 
	Token(char ch)    // make a Token from a char
		:kind(ch), value(0) { }
	Token(char ch, double val)     // make a Token from a char and a double
		:kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
	Token_stream();   // make a Token_stream that reads from cin
	Token get();      // get a Token (get() is defined elsewhere)
	void putback(Token t);    // put a Token back
private:
	bool full;        // is there a Token in the buffer?
	Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
	:full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
	if (full) error("putback() into a full buffer");
	buffer = t;       // copy t to buffer
	full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
	if (full)
	{       // do we already have a Token ready?
		full = false;     //check if we already have a Token ready.
		return buffer;
	}

	char ch;
	cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

	switch (ch) {
	case '=':    // for "print"
	case 'x':    // for "quit"
	case '{':
	case '}':
	case '(': 
	case ')': 
	case '+': 
	case '-':
	case '*': 
	case '/':
	case '!':
		return Token(ch);        // let each character represent itself
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);         // put digit back into the input stream
		double val;
		cin >> val;              // read a floating-point number
		return Token(number, val);   // let '8' represent "a number"
	}
	default:
		error("Bad token");
	}
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

						//------------------------------------------------------------------------------

class NomNum {
public:
	string nombre;
	double valor;
	NomNum(string str, int val)
		:nombre(str),valor(val){ }
};
vector<NomNum>Mi_Vector;


double expression();    // declaration so that primary() can call expression()
//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
	Token t = ts.get();
	switch (t.kind) {

	case '{':    // handle '(' expression ')'
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("expected");
		return d;
	}
	case '(':    // handle '(' expression ')'
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("expected");
		return d;
	}
	case number:            // we use '8' to represent a number
		return t.value;  // return the number's value
		break;
	default:
		error("primary expected");
	}
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
	double left = primary();
	Token t = ts.get();        // get the next token from token stream
	int factorial = int(left);
	int resultado =1;
	while (true)
	{
		switch (t.kind) {
		case '!': 
			if (factorial == 0)
			{
				left = 1;
				t = ts.get();
			}
			for (int i = 1; i <= factorial; ++i)
			{
				resultado *= i;
			}
			left = resultado;
			t = ts.get();
			break;
		case '*':
		
			left *= primary();
			t = ts.get();
			break;
		
		case '/':
		{
			double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);     // put t back into the token stream
			return left;
		}
	}
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
	double left = term();      // read and evaluate a Term
	Token t = ts.get();        // get the next token from token stream

	while (true) 
	{
		switch (t.kind) {
		case '+':
			left += term();    // evaluate Term and add
			t = ts.get();
			break;
		case '-':
			left -= term();    // evaluate Term and subtract
			t = ts.get();
			break;
		default:
			ts.putback(t);     // put t back into the token stream
			return left;       // finally: no more + or -: return the answer
		}
	}
}

//------------------------------------------------------------------------------

int main()
{
	std::cout << "Bienvenido al programa, para poder acceder a la calculadora, ingresa 1."
		<< "\nPara acceder al Vector e ingresar nombres y edades, ingresa 2. \n";
	int eleccion;
	cin >> eleccion;
	if (eleccion == 1)
	{
		try
		{
			std::cout << "Bienvenido a esta simple calculadora."
				<< "\nPor favor ingresa expresiones usando numeros flotantes."
				<< "\nLos operadores disponibles son: ('+', '-', '*', '/' y '%')"
				<< "\nEscribe '=' para recibir un resultado y 'q' o 'x' para salir de la calculadora.\n";
			double val = 0;
			while (cin) {
				Token t = ts.get();

				if (t.kind == 'x') break; // 'x' para salir
				if (t.kind == '=')

					// '=' para "imprimir ahora"
					cout << "=" << val << '\n';
				else
					ts.putback(t);
				val = expression();
			}
			keep_window_open();
		}
		catch (exception& e) {
			cerr << "error: " << e.what() << '\n';
			keep_window_open();
			return 1;
		}
		catch (...) {
			cerr << "Oops: unknown exception!\n";
			keep_window_open();
			return 2;
		}
	}
	if (eleccion == 2)
	{
		std::cout << "Bienvenido, en este programa se ingresara un nombre y una edad."
			<< "\nEstos elementos se guardaran en una variable la cual pertenecera a un tipo de dato definido por una clase."
			<< "\nEstas variables seran almacenadas en un vector."
			<< "\nEscribe 'exit' seguido de cualquier numero cuando quieras salir del programa.\n\n"
			<< "\nIngresa un nombre e ingresa una edad separados por un Enter: \n";
		string nombre;
		int edad;
		while (cin >> nombre and cin >> edad)
		{

			NomNum Objeto(nombre, edad);
			if (nombre == "exit")
			{
				std::cout << "Hasta la proxima.\n";
				exit(-1);
				keep_window_open();
			}
			else
			{
				for (int i = 0; i < Mi_Vector.size(); i++)
				{
					Mi_Vector.push_back(NomNum(Objeto));
				}
			}
			std::cout << "El nombre: " << nombre << " y la edad: " << edad << " Han sido ingresados al Vector.\n";
			std::cout << "\nIngresa un nombre e ingresa una edad separados por un Enter: \n";
		}
		keep_window_open();
		return 0;
		
	}	
}