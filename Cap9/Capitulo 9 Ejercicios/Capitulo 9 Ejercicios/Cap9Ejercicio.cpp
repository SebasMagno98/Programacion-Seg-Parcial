#include <iostream>
#include <conio.h>
#include <Vector>
#include <string>
#include <algorithm>
using namespace std;
//Ejercicio 1

/* Operaciones que se le pueden realizar a:
	Un archivo de computadora; Este puede ser modificado, puede ser eliminado, puede ser creado, puede adjuntarse a otros archivos
	Página Web; Esta puede ser editada de diversas formas; cambiarle el color, el tipo de letra que se empleará, el URL, puede ser creada y eliminada
	Reproductor de Música; Se le puede agregar más música, puede eliminar canciones, puede utilizar una función de aleatorio, puede modificar el audio de lo que se reproducirá.
	Tostadora; Puede tostar pan, ser conectada, desconectada, desamblada, armada.
	Taza de Cafe; puede ser llenada, puede ser vaciada, puede ser lavada, ensuciarse.
	Celular; puede realizar llamadas, puede recibir llamadas, enviar y recibir mensajes, alojar multimedia, navegar por internet.
	Motor de auto; puede ser desamblado, armado, colocado en un auto, reparado, dañado.
	Directorio de telefono; puede ser ojeado, abierto, cerrado.*/


class Name_pairs
{
private:
	vector<string>name;
	vector<double>age;
public:
	Name_pairs()
	{}
	void read_names();
	void print();
	void Sort();
};


void Name_pairs::read_names()
{
	string nombre;
	int edad;
	cout << "Ingresa un nombre, seguido de una edad, cada uno separado por un enter. \n";
	cin >> nombre;
	cin >> edad;
	name.push_back(nombre);
	age.push_back(edad);
}
void Name_pairs::print()
{
	for (int i = 0; i < name.size(); i++)
	{
		for (int j = 0; j < age.size(); j++)
		{
			cout << name[i] << " " << age[j] << '\n';
		}
	}
}

void Name_pairs::Sort()
{
	sort(name.begin(), name.end());
	for (string &s : name)
	{
		cout << s << " ";
	}
}
int main()
{
	Name_pairs persona;
	persona.read_names();
	persona.print();
	persona.Sort();
	cin.ignore();
	cin.get();
	return 0;
}