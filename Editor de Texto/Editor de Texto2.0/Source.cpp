#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

class Texto				//Clases.
{
public:
	string contenido;
	string linea;
	Texto(){}
	~Texto(){}

	void menu()
	{
		system("cls");
		cout << "Bienvenido al Editor de texto.\n"
			<< "Ingresa un numero para lo que quieras hacer: \n"
			<< "1.Crear un archivo.\n"
			<< "2.Leer un archivo.\n"
			<< "3.Modificar archivo.\n";
		int eleccion, *P_numero;			//Puntero
		cin >> eleccion;
		P_numero = &eleccion;
		switch (*P_numero)
		{
		case 1:
			Crear_archivo();
			break;
		case 2:
			Leer_Archivo();
			break;
		case 3: Modificar_archivo();
		default:
			cout << "Esa opcion no esta disponible, seras devuelto al menu.\n";
			menu();
			break;
		
			
		}
	}
	void Texto_Usuario()
	{
		do
		{
			getline(cin, linea);
			contenido += linea + "\n";
		} while (linea != "");
	}
	void Crear_archivo()			//Creacion del archivo.
	{
		system("cls");
		ofstream archivo;
		string Archivo_nombre;
		cout << "Escribe el nombre del archivo, no olvides la terminacion .txt: \n\n";
		cin.ignore();
		getline(cin, Archivo_nombre);
		archivo.open(Archivo_nombre.c_str(), ios::out);

		if (archivo.fail())
		{
			cout << "No se pudo crear el archivo.\n"
				<< "Seras devuelto al inicio.";
			Sleep(2000);
			Crear_archivo();
		}
		else
		{
			cout << "El archivo ha sido creado.\n\n";
		}
		cout << "Escribe lo que quieras."
			<< "\nEl programa dejara de recibir caracteres cuando no se escriba nada y se de un Enter: \n\n"
			<< "-------------------------------------------------\n\n";
		Texto_Usuario();
		archivo << contenido;
		archivo.close();
		system("cls");
		cout << "El contenido se ha ingresado al archivo.\n"
			<< "Que quieres hacer ahora?\n"
			<< "1. Para volver al menu.\n"
			<< "2. Para cerrar el programa.\n";
		int opcion,*P_opcion;				//Puntero
		cin >> opcion;
		P_opcion = &opcion;
		switch (*P_opcion)
		{
		case 1:
			menu();
		case 2:
			system("cls");
			cout << "Hasta luego.\n";
			Sleep(2000);
			exit(1);
		default:
			cout << "Esa opcion no esta disponible. Seras devuelto al menu.\n";
			menu();
			break;
		}
	}
	void Leer_Archivo()				//Apertura y Lectura de archivos
	{
		system("cls");
		string palabras;
		ifstream archivo;
		string Archivo_nombre;
		cout << "Escribe el nombre del archivo, no olvides la terminacion .txt: \n\n";
		cin.ignore();
		getline(cin, Archivo_nombre);
		archivo.open(Archivo_nombre.c_str(), ios::in);
		cout << "\n\n";
		if (archivo.fail())
		{
			cout << "Ese archivo no existe o escribio mal el nombre.\n"
				<< "Procura haber escrito bien el nombre. \n";
			Sleep(2000);
			Leer_Archivo();
		}
		cout << "Contenido del archivo.\n\n"
			<< "------------------------------------------\n\n";
		while (!archivo.eof())
		{
			getline(archivo, palabras);
			cout << palabras << '\n';
		}
		archivo.close();
		cout << "Que quieres hacer ahora?\n"
			<< "1. Para volver al menu.\n"
			<< "2. Para cerrar el programa.\n";
		int opcion, *P_opcion;				// Puntero
		cin >> opcion;
		P_opcion = &opcion;
		switch (*P_opcion)
		{
		case 1:
			menu();
		case 2:
			system("cls");
			cout << "Hasta luego.\n";
			Sleep(2000);
			exit(1);
		default:
			cout << "Esa opcion no esta disponible. Seras devuelto al menu.\n";
			menu();
			break;
		}
	}
	void Modificar_archivo()	// Apertura y Modificacion de archivos.
	{
		system("cls");
		string palabras;
		ifstream archivo;
		string Archivo_nombre;
		cout << "Escribe el nombre del archivo, no olvides la terminacion .txt: \n\n";
		cin.ignore();
		getline(cin, Archivo_nombre);
		archivo.open(Archivo_nombre.c_str(), ios::in);
		cout << "\n\n";
		if (archivo.fail())
		{
			cout << "Ese archivo no existe o escribio mal el nombre.\n"
				<< "Procura haber escrito bien el nombre. \n";
			Sleep(2000);
			Leer_Archivo();
		}
		cout << "Contenido del archivo.\n\n"
			<< "------------------------------------------\n\n";
		while (!archivo.eof())
		{
			getline(archivo, palabras);
			cout << palabras << '\n';
		}
		archivo.close();
		ofstream file;
		file.open(Archivo_nombre.c_str(), ios::app);
		cout << "Se dejaran de recibir caracteres cuando no se escriba nada y se de un Enter:\n"
			<< "-------------------------------------------------------\n";
		Texto_Usuario();
		file << contenido;
		file.close();
		system("cls");
		cout << "El contenido se ha ingresado al archivo.\n"
			<< "Que quieres hacer ahora?\n"
			<< "1. Para volver al menu.\n"
			<< "2. Para cerrar el programa.\n";
		int opcion;
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			menu();
		case 2:
			system("cls");
			cout << "Hasta luego.\n";
			Sleep(2000);
			exit(1);
		default:
			cout << "Esa opcion no esta disponible. Seras devuelto al menu.\n";
			menu();
			break;
		}

		
	}
};
ostream& operator<<(ostream& os, const Texto& p)  //Sobrecarga de operadores
{
	os << p.contenido;
	return os;
}
int main()
{
	Texto t;
	t.menu();

	return 0;
}