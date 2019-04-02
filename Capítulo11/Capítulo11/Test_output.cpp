#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;
template<class T>
char* as_bytes(T & i)
{
	void* addr = &i;
	return static_cast<char*>(addr);
}
void Drill()
{
	int Birth_year = 1998;

	cout << Birth_year << " \tDecimal.\n"
		<< hex << Birth_year << " \tHexadecimal.\n"
		<< oct << Birth_year << " \tOctal.\n"
		<< 21 << " \tDecimal.\n"
		<< hex << 21 << "\tHexadecimal.\n"
		<< oct << 21 << "\tOctal.\n"
		<< "\n\n\n"
		<< 1234567.89 << "(\t Default Float\n"
		<< fixed << 1234567.89 << "\t fixed\n"
		<< scientific << 1234567.89 << " \t Scientific\n"
		<< "\n\n\n"
		<< "Apellido: Magno \tNombre: Sebastian\n"
		<< "Numero: " << 324532 << " Decimal\n"
		<< "Numero: " << hex << 324532 << " Hexadecimal\n"
		<< "Numero: " << oct << 324532 << " Octal\n\n"
		<< "Apellido: Gutierrez \tNombre: Alejandro\n"
		<< "Numero: " << 5628437 << " Decimal\n"
		<< "Numero: " << hex << 5628437 << " Hexadecimal\n"
		<< "Numero: " << oct << 5628437 << " Octal\n\n"
		<< "Apellido: Gonzalez \tNombre: Isai\n"
		<< "Numero: " << 5562187 << " Decimal\n"
		<< "Numero: " << hex << 5562187 << " Hexadecimal\n"
		<< "Numero: " << oct << 5562187 << " Octal\n\n"
		<< "Apellido: Ramirez \tNombre: Sofia\n"
		<< "Numero: " << 6321487 << " Decimal\n"
		<< "Numero: " << hex << 6321487 << " Hexadecimal\n"
		<< "Numero: " << oct << 6321487 << " Octal\n\n"
		<< "Apellido: Balderas \tNombre: Eduardo\n"
		<< "Numero: " << 5456121 << " Decimal\n"
		<< "Numero: " << hex << 5456121 << " Hexadecimal\n"
		<< "Numero: " << oct << 5456121 << " Octal\n\n"
		<< "Apellido: Leyva \tNombre: Diego\n"
		<< "Numero: " << 465416 << " Decimal\n"
		<< "Numero: " << hex << 465416 << " Hexadecimal\n"
		<< "Numero: " << oct << 465416 << " Octal\n\n"
		<< "Apellido: Castro \tNombre: Francisco\n"
		<< "Numero: " << 3215484 << " Decimal\n"
		<< "Numero: " << hex << 3215484 << " Hexadecimal\n"
		<< "Numero: " << oct << 3215484 << " Octal\n\n";
}
bool is_vowel(const char p_char)
{

	constexpr char vowels[] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
	return std::find(std::begin(vowels), std::end(vowels), p_char) != std::end(vowels);
}
void tolowers(string& s)
{
	for (char& x : s) x = tolower(x);
}
string remove_vowel(std::string st)
{
	auto to_erase = std::remove_if(st.begin(), st.end(), is_vowel);
	st.erase(to_erase, st.end());
	return st;
}

void ejercicio1()
{
	cout << "Este programa leera todo el contenido de un archivo y pasara todas las mayusculas a minusculas.\n\n";
	string contenido;
	ifstream archivo;
	archivo.open("file.txt", ios::in);
	while (!archivo.eof())
	{
		getline(archivo, contenido);
		tolowers(contenido);
		cout << contenido << '\n';
	}

}
void ejercicio2()
{
	cout << "Este programa leera un archivo con todo y saltos de linea.\n\n";
	string contenido;
	ifstream archivo;
	archivo.open("cosa.txt", ios::in);
	while (!archivo.eof())
	{
		getline(archivo, contenido);
		cout << contenido << '\n';
	}
}
void ejercicio3()
{
	cout << "Este programa leera el contenido de un archivo y eliminara todas las vocales.\n\n";
	string contenido;
	ifstream archivo;
	archivo.open("Vocales.txt", ios::in);
	while (!archivo.eof())
	{
		getline(archivo, contenido);
		cout << remove_vowel(contenido) << '\n';
	}
}
void ejercicio4()
{
	int num;
	vector<int>cantidades;
	cout << "Ingresa cualquier numero, ya sea este decimal, octal o hexadecimal: \n";
	while (cin >> num)
	{
		if (num == 99)
		{
			break;
		}
		cantidades.push_back(num);
	}
	for (int i = 0; i < cantidades.size(); i++)
	{
		cout << dec << i << " decimal\n";
	}
}
void ejercicio5()
{
	cout << "Este programa eliminara los signos de puntuacion que se ingresen, cambiandolos por un espacio.\n\n";
	string linea;
	getline(cin, linea);
	for (char& ch : linea)

		switch (ch)
		{
		case ';': case'.': case ',': case'?':case'!':
			ch = ' ';
		}
}
void ejercicio6()
{
	cout << "Este programa pasara todos los caracteres a minusculas.\n";
	string linea;
	getline(cin, linea);
	tolowers(linea);
	cout << linea << '\n';
}
/*void ejercicio7()
{
	string linea;
	getline(cin, linea);
	for(char& ch : linea)
		switch (ch)
		{
		case ';': case'.': case ',': case'?':case'!':
			ch = ' ';
		}
	stringstream ss(linea);
	vector<string>vs;
	for (string palabra; ss >> palabra;)
		vs.push_back(palabra);
}*/
void ejercicio8()
{
	cout << "Ingresa el nombre de un archivo: \n";
	string iname;
	cin >> iname;
	ifstream ifs{ iname,ios_base::binary }; 
	cout << "Escribe el nombre de otro archivo: \n";
	string oname;
	cin >> oname;
	ofstream ofs{ oname,ios_base::binary }; 
	vector<int> v;
	
	for (int x; ifs.read(as_bytes(x), sizeof(int)); ) 
		v.push_back(x);
	
	for (int x : v)
		ofs.write(as_bytes(x), sizeof(int));
}
void ejercicio9()
{
	vector<string>vs;
	cout << "Escribe las palabras que quieras: \n\n";
	string palabras;
	while (cin >> palabras)
	{
		if (palabras == "")
		{
			break;
		}
		vs.push_back(palabras);
		for (auto i : palabras)
		{
			cout << i << " " << '\n';
		}

	}
}
void ejercicio10()
{
	cout << "Este programa leera el contenido de un archivo de manera invertida.\n\n";
	char c;
	ifstream myFile("documento.txt", ios::ate);
	streampos size = myFile.tellg();
	for (int i = 1; i <= size; i++) {
		myFile.seekg(-i, ios::end);
		myFile.get(c);
		printf("%c\n", c);
	}
}
void ejercicio11()
{
	cout << "Este programa leera un archivo y contara la cantidad de caracteres que posee.\n";
	vector<string>vs;
	string contenido;
	ifstream archivo;
	archivo.open("Textoloco.txt", ios::in);
	while (!archivo.eof())
	{
		getline(archivo, contenido);
	}
	vs.push_back(contenido);
	cout << vs.size() << '\n';
}
int main()
{
	int eleccion;
	cout << "Elige una opcion.\n"
		<< "1. Para el Drill.\n"
		<< "2 al 11 para el resto de ejercicios.\n";
	cin >> eleccion;
	switch (eleccion)
	{
	case 1:
		Drill();
		break;
	case 2:
		ejercicio1();
		break;
	case 3:
		ejercicio2();
		break;
	case 4:
		ejercicio3();
		break;
	case 5:
		ejercicio4();
		break;
	case 6:
		ejercicio5();
		break;
	case 7:
		ejercicio6();
		break;
	case 8:
		ejercicio8();
		break;
	case 9:
		ejercicio9();
		break;
	case 10:
		ejercicio10();
		break;
	case 11:
		ejercicio11();
	
	default:
		cout << "Esa opcion no esta disponible, volveras al inicio.\n";
		main();
		break;
	}
		
	cin.ignore();
	cin.get();
	return 0;
}