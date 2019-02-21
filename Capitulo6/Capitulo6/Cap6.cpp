#include "Includes.h"
#include <iostream>
using namespace std;


/*
Sentence:
	Noun Verb
	Sentence Conjuction Sentence
Conjuction:
	"and"
	"or"
	"but"
	"The"
Noun:
	"birds"
	"fish"
	"C++"
Verb:
	"rules"
	"fly"
	"swim"
*/

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

void Bulls()
{
	std::cout << "En este programa, haremos un pequeño juego de adivinar letras."
		<< "\nPor cada letra correcta que hayas adivinado se sumara un toro, se ganara si se alcanzo el numero de 4 toros."
		<< "\nY Por cada letra incorrecta se sumara una vaca, al final del programa se dirán cuantos toros y cuantas vacas se han obtenido.\n";	
	vector<char>adivinar{'x', 'a' , 'f','g'};
	int toros = 0;
	int vacas = 0;
	char primAdi;
	char SegAdi;
	char TerAdi;
	char CuarAdi;
	string eleccion;
	std::cout << "Ingresa el primer valor a adivinar: \n";
	cin >> primAdi;
	if (primAdi == adivinar[0])
	{
		toros += 1;
	}
	else
	{
		vacas += 1;
	}
	std::cout << "Ingresa el segundo valor a adivinar: \n";
	cin >> SegAdi;
	if (SegAdi == adivinar[1])
	{
		toros += 1;
	}
	else
	{
		vacas += 1;
	}
	std::cout << "Ingresa el tercer valor a adivinar: \n";
	cin >> TerAdi;
	if (TerAdi == adivinar[2])
	{
		toros += 1;
	}
	else
	{
		vacas = +1;
	}
	std::cout << "Ingresa el cuarto valor a adivinar: \n";
	cin >> CuarAdi;
	if (CuarAdi == adivinar[3])
	{
		toros += 1;
	}
	else
	{
		vacas += 1;
	}
	std::cout << "La cantidad de toros conseguidos es de: " << toros << " y la cantidad de vacas conseguidas es de: " << vacas << '\n';
	if (toros == 4)
	{
		std::cout << "Felicidades, acertaste todos los numeros y conseguiste todos los toros. \n";
	}
	std::cout << "¿Quieres volver a jugar?"
		<< "\nIngresa 'Y' para si o 'N' para cerrar.\n";
	if (eleccion == "Y" or eleccion == "y")
	{
		Bulls();
	}
	else
	{
		std::cout << "Hasta la proxima.\n";
		exit(-1);
	}
	keep_window_open();
}
void numeros()
{
	std::cout << "En este programa se deben ingresar un maximo de cuatro digitos"
		<< "\nel programa devolvera las unidades respectivas de esos numeros.";
	vector<int>numbers;
	int num1;
	int num2;
	int num3;
	int num4;
	int opcion;
	std::cout << "Cuantos valores quieres ingresar?: \n";
	cin >> opcion;
	if (opcion == 1) 
	{
		std:cout << "Ingresa el numero: \n";
		cin >> num1;
		std:cout << "Son: " << num1 << " unidades.\n";
	}
	if (opcion == 2)
	{
		std::cout << "Ingresa los numeros separados por espacios:\n";
		cin >> num1, num2;
		std::cout << "Son: " << num1 << " decenas y " << num2 << " unidades.\n";
	}
	if (opcion == 3)
	{
		std::cout << "Ingresa los numeros separados por espacios:\n";
		cin >> num1, num2, num3;
		std::cout << "Son: " << num1 << " centenas  " << num2 << " decenas " << num3<< " unidades.\n";
	}
	if (opcion == 4)
	{
		std::cout << "Ingresa los numeros separados por espacios:\n";
		cin >> num1, num2, num3, num4;
		std::cout << "Son: " << num1 << " miles  " << num2 << " centenas " << num3 << " decenas" <<num4 << " unidades.\n";
	}
}

void Permutacion()
{
	std::cout << "En este programa veremos cual es el resultado de una permutacion. \n\n";
	int a;
	int b;
	std::cout << "Ingresa el valor de a: \n";
	cin >> a;
	std::cout << "ingresa el valor de b: \n";
	cin >> b;
	int resultado = 1;
	int resultado2 = 1;
	double perm;
	int b2 = a - b;
	{
		for (int i = 1; i <= a; ++i)
		{
			resultado *= i;
		}
		a = resultado;
	}
	std::cout << "Ingresa el valor de b: \n";
	{
		for (int i = 1; i <= b2; ++i)
		{
			resultado2 *= i;
		}
		b = resultado2;
	}
	perm = resultado / resultado2;
	std::cout << "La permutacion de (a,b) es: " << perm << '\n';
}
void combinacion()
{
	std::cout << "En este programa veremos cual es el resultado de una combinacion. \n\n";
	int a;
	int b;
	std::cout << "Ingresa el valor de a: \n";
	cin >> a;
	std::cout << "ingresa el valor de b: \n";
	cin >> b;
	int resultado = 1;
	int resultado2 = 1;
	double perm;
	double combinacion;
	int b2 = a - b;
	{
		for (int i = 1; i <= a; ++i)
		{
			resultado *= i;
		}
		a = resultado;
	}
	std::cout << "Ingresa el valor de b: \n";
	{
		for (int i = 1; i <= b2; ++i)
		{
			resultado2 *= i;
		}
		b = resultado2;
	}
	perm = resultado / resultado2;
	combinacion = perm / b;
	std::cout << "La combinacion es de: " << combinacion << '\n';

}
int main()
{
	std::cout << "Bienvenido al programa, para poder acceder a la calculadora, ingresa 1."
		<< "\nPara acceder al Vector e ingresar nombres y edades, ingresa 2. \n"
		<< "\nY Del 3 al 7 para el resto de ejercicios";
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
	if (eleccion == 3)
	{
		std::cout << "En este programa revisaremos si la oracion escrita esta bine gramaticamente."
			<< "\nEl programa devolvera 'OK' en caso de estar bien, y 'Not OK' si es el caso opuesto.\n\n";
		string Palabras;
		char oracion[10];
		std::cout << "Ingresa una oracion: \n";
		gets_s(oracion);
		Palabras = oracion;
		if (Palabras.back() == '.')
		{
			std::cout << "OK";
		}
		else
		{
			std::cout << "Not OK";
		}
		keep_window_open();
		return 0;
	}
	if (eleccion == 4)
	{
		Bulls();
		keep_window_open();
	}
	if (eleccion == 5)
	{
		numeros();
		keep_window_open();
	}
	if (eleccion == 6)
	{
		Permutacion();
		keep_window_open();
	}
	if (eleccion == 7)
	{
		combinacion();
		keep_window_open();
	}
	keep_window_open();
	return 0;
}