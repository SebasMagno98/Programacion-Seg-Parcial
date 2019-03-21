#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

using namespace std;

enum class Genre {
	fiction = 1, nonfiction, periodical, biography, children

};


class Book
{
public:
	string title;
	string author;
	string date;
	string ISBN;
	Genre genero;

	Book(string t, string au, string d, string IS, Genre g)
	{
		title = t;
		author = au;
		date = d;
		ISBN = IS;
		genero = g;
	}
};


class Patron
{
public:
	string User_name;
	int Card_number;
	int fees = 0;

	Patron(string u, int c, int f)
	{
		User_name = u;
		Card_number = c;
		fees = f;
	}

};

class Library
{
public:
	vector<Book>libros;
	vector<Patron>pat;
	struct Transaction
	{
	};
	void Add_book(Book a)
	{
		libros.push_back(a);
		cout << "\nEl libro ha sido ingresado.";
	}
	void Add_patrons(Patron p)
	{
		pat.push_back(p);
		cout << "\nEl patron fue ingresado.";
	}
};






bool Chck_fees(Patron& p)
{
	if (p.fees == 0)
	{
		return false;
		cout << "\nNo hay deudas.\nMuy bien, " << p.User_name << ".\n";
	}
	else
	{
		return true;
		cout << "\nHay deuda y es de: " << p.fees << " Ya paga, " << p.User_name << ".\n";
	}
}

Book operator==(Book& a, Book& b)
{
	if (a.ISBN == b.ISBN)
	{
		cout << "ISBN iguales";
		return a == b;
		
	}
}

Book operator!=(Book& a, Book& b)
{

	if (a.ISBN != b.ISBN)
	{
		return a != b;
		cout << "ISBN diferentes";
	}
}
ostream& operator<<(ostream& os, Book& b)
{
	return os <<'\n' <<"Titulo: " << b.title << '\n'<< "Autor: " << b.author << '\n'<< "Fecha: " << b.date << '\n'<< "ISBN: " << b.ISBN << '\n';
}
ostream& operator<<(ostream& os, Patron& p)
{
	return os <<'\n' << "User name: " << p.User_name << '\n' << "Numero de tarjeta: " << p.Card_number << '\n' << "Deudas: " << p.fees <<'\n';
}
int main()
{
	
	Book Libro1{ "Halo", "Un Men","2018/65/6165", "201651R", Genre::fiction };
	Book Libro2{ "Pokemon", "Otro men" , "2018/82/21", "202018H", Genre::fiction };
	Book Libro3{ "Hee Hee", "Ayuwoki" , "2050/02/21" , "303262V", Genre::children };
	Book Libro4{ "La Mafia del poder" , "AMLO" , "2005/25/04", "305212X" , Genre::nonfiction };
	Book Libro5{ "Tres mayor a Cinco" , "EPN" , "2006/10/02",  "31516F" , Genre::fiction };
	cout << "Estos son los libros disponibles: \n\n";
	cout << Libro1;
	cout << Libro2;
	cout << Libro3;
	cout << Libro4;
	cout << Libro5;
	Patron Us1{ "Mastur chif", 5246,0 };
	Patron Us2{ "Marcos Fenicks",5263,25 };
	Patron Us3{ "Jefe Maistro" , 5234, 15 };
	Patron Us4{ "Luis Miguel" , 6325, 0 };
	cout << "\n\nEstos son los patrones registrados: \n\n";
	cout << Us1;
	cout << Us2;
	cout << '\n';
	Chck_fees(Us1);
	Chck_fees(Us2);
	Chck_fees(Us3);
	Chck_fees(Us4);
	

	cout <<
	cin.get();
	return 0;
	
}