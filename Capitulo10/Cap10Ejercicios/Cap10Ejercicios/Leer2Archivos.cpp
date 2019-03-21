#include <iostream>
#include <conio.h>
#include "Includes.h"

int main()
{
	ofstream archivo;
	string contenido;
	archivo.open("Archivo1.txt", ios::out);

	if (archivo.fail())
	{
		cout << "No se pudo abrir el archivo.\n";
		exit(1);
	}
	cout << "Escribe lo que quieres que contenga el primer archivo: \n\n";
	getline(cin, contenido);

	archivo << contenido;

	cout << "El contenido ha sido agregado.\n";

	archivo.close();

	ofstream archivo2;
	string contenido2;
	archivo.open("Archivo2.txt", ios::out);

	if (archivo2.fail())
	{
		cout << "El archivo no se pudo abrir.\n";
		exit(1);
	}
	cout << "Escribe lo que quieres que contenga el segundo archivo: \n\n";
	getline(cin, contenido2);

	archivo2 << contenido2;

	cout << "El contenido ha sido agregado al segundo archivo.\n";
	archivo2.close();

	ofstream archivo3;
	string nombre;

	cout << "Que nombre quieres que tenga el ultimo archivo?\n\n";
	getline(cin, nombre);
	archivo3.open(nombre.c_str(), ios::out);

	if (archivo.fail())
	{
		cout << "No se pudo abrir el archivo.\n";
		exit(1);
	}

	archivo3 << contenido;
	archivo3 << "\n";
	archivo3 << contenido2;
	keep_window_open();
	return 0;
}

