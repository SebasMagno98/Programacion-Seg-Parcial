#include <iostream>
#include "Includes.h"

//Se define la estructura del Token.
struct Token {
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
};
//----------------------------------------------------------------------------------------------------------------------------

//Se define el flujo de Tokens que se encargará de recibir los tokens que se iran ingresando posteriormente.
class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer = t; full = true; }

	void ignore(char);
};

const char let = '#';
const char quit = 'q';
const char print = ';';
const char number = '8';
const char name = 'a';
//-----------------------------------------------------------------------------------------------------------------------------

//Se definen los caraceters que seràn utilizados para las operacionses, ya sean los numeros y los operadores matematicos.
Token Token_stream::get()
{
	if (isspace('\n'))
	{
		return Token(print);
	}
	if (full) { full = false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
	case '{':
	case '}':
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case 'S':
	case 'P':
	case ';':
	case '=':
		return Token(ch);
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
	{	cin.unget();
	double val;
	cin >> val;
	return Token(number, val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s = ch;
			cin.unget();
			if (s == "let") return Token(let);
			if (s == "quit") return Token(name);
			return Token(print);
		}
		error("Bad token");
	}
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Esto se encargara de revisar si el Flujo de Tokens esta lleno.
void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

// Se define una estructura que se encargará de recibir nombre y edad.
struct Symbol_table {
	string name;
	double value;
	Symbol_table(string n, double v) :name(n), value(v) { }
};
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Vector del mismo tipo de dato que la estructura anterior, este se encargara de almacenar los valores dentro de si mismo.
vector<Symbol_table> names;

double get_value(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

//
void set_value(string s, double d)
{
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
		}
	error("set: undefined name ", s);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

bool is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Token_stream ts;

double expression(Token_stream& ts);
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Esta seccion se encargarña de definir los caracteres que seran utilizados para definir la funcion de los parentesis, y asi como los numeros negativos.
double primary(Token_stream& ts)
{
	Token t = ts.get();
	switch (t.kind) {
	case '{':
	{	double d = expression();
	t = ts.get();
	if (t.kind != '}') error("'{' expected");
	}
	case '(':
	{	double d = expression();
	t = ts.get();
	if (t.kind != ')') error("'(' expected");
	}
	case number:
		return t.value;
	case '-':
		return -primary();
	case name:
		return get_value(t.name);
	default:
		error("primary expected");
	}
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Esta sección se encargará de definir la funciond del signo de multiplicación, y de la division.
double term(Token_stream& ts)
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case 'S':
		{
			double d = primary();
			if (d == -primary())
				error("No se puede sacar raiz cuadrada de un numero negativo.");
			left = sqrt(primary());
			t = ts.get;
			break;
		}
		case '*':
		{
			left *= primary();
			t = ts.get();
			break;
		}
		case '/':
		{	
			double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			t = ts.get();
			break;
		}
		case '%':
		{
			double d = primary();
			if (d == 0) error("%:divide by zero");
			left = fmod(left, d);
			t = ts.get();
			break;
		}
		case 'P':
		{
			double d = primary();
			if (d == 0) error("pow:pow by zero");
			left = pow(left, d);
			t = ts.get();
			break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Esta sección se encargara de definir la funcion de los caracteres de suma y resta.
double expression(Token_stream& ts)
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// 
double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	names.push_back(Symbol_table(name, d));
	return d;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void calculate()
{
	while (cin) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
	std::cout << "Ingresa el numero 1 para acceder a la calculadora o del 2 al ... para acceder a los demas ejercicios: \n";
	int eleccion;
	cin >> eleccion;
	switch (eleccion)
	case 1:
	{
		try {

			const double pi = 3.14;
			const int k = 1000;
			const double e = 2.71;
			string letra;
			std::cout << "Presiona H para recibir ayuda o cualquier otra letra para omitir: \n\n";
			cin >> letra;
			transform(letra.begin(), letra.end(), letra.begin(), ::tolower);
			if (letra == "help")
			{
				std::cout << "Ingresa las operaciones que quieras, al terminar presiona '=' y un enter."
					<< "\nLas operaciones que ingreses deben ser posibles, de lado contrario saldrán errores.\n";
			}
			else
			{
				std::cout << "Muy bien, comencemos.\n";
			}
			calculate();
			return 0;
		}
		catch (exception& e) {
			cerr << "exception: " << e.what() << endl;
			char c;
			while (cin >> c && c != ';');
			return 1;
		}
		catch (...) {
			cerr << "exception\n";
			char c;
			while (cin >> c && c != ';');
			return 2;
		}
		break;

	case 2:

	}
	
}