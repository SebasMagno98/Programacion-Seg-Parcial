#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include <fstream>


using namespace std;

void Suma_numeros();

int main()
{
	Suma_numeros();
	cin.get();
	return 0;
}
void Suma_numeros()
{
	vector<int>suma;
	string x;
	int numero;
	ifstream archivo;
	archivo.open("Numeros.txt", ios::in);

	if (archivo.fail())
	{
		cout << "El archivo no se puedo abrir.";
		exit(1);
	}
	while (!archivo.eof())
	{
		int num = 0;
		while (archivo >> numero)
		{
			suma.push_back(numero);
			
			
		}
		for (int i = 0; i < suma.size(); i++)
		{
			num = num + suma[i];
		}
		cout << "La suma total de los numeros es: " << num;
	}
	archivo.close();
	
}