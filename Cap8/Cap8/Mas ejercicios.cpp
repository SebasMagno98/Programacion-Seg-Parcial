#include "Includes.h"
#include <iostream>
using std::cout;
void print()
{
	cout << "Ingresa numeros los  cuales seran almacenados dentro de un vector:\n";
	vector<int>numeros;
	int numbers;
	while (cin >> numbers)
	{
		numeros.push_back(numbers);
		for (auto j : numeros)
		{
			cout << j;
		}
		cout << '\n';
	}
	
}
void ejercicio2()
{
	cout << "Hasta que numero quieres que se muestre la secuencia Fibonacci?: \n";
	vector<int>numeros;
	int numbers;
	int resultado = 0;
	int numbers2 = 1;
	int numbers1 = 0;
	cin >> numbers;
	for (int i = 0; i < numbers; i++)
	{
		if (i == 0)
		{
			numbers2 = 0;
		}
		else if (i == 1)
		{
			numbers2 = 1;
		}
		else if (i == 2)
		{
			numbers2 = 0;
		}
		resultado = numbers1 + numbers2;
		numbers1 = numbers2;
		numbers2 = resultado;
		numeros.push_back(resultado);
		for (auto x : numeros)
		{
			cout << x;
		}
		cout << '\n';
	}
	
}
void ejercicio3()
{
	vector<int>V{ 1,2,3,4,5,6,7,8,9,10 };
	cout << "Los valores del vector son: \n";
	for (int i = 0; i < V.size(); i++)
	{
		for (auto i : V);
		cout << i;
	}
	cout << '\n';

	cout << "Los valores al reves del vector son: \n";
	std::reverse(V.begin(), V.end());

}

void ejercicio4()
{
	vector<string>name{ "Miguel,Alonso,Gerardo;Roberto,Luis" };
	cout << "Los datos almacenados en el vector son: \n";
	for (int i = 0; i < name.size(); i++)
	{
		for (auto i : name);
		cout << i;
	}
	cout << '\n';
}

void ejercicio5()
{
	vector<string>names;
	vector<int>age;
	string nombre;
	int edad;
	cout << "Ingresa un nombre: \n"
		<< "\nPuedes escribir exit para dejar de ingresar datos. \n";
	
	while (cin >> nombre)
	{
		if (nombre == "exit")
		{
			exit(-1);
			break;
		}
		names.push_back(nombre);
		cout << "Ingresa una edad: \n";
		cin >> edad;
		age.push_back(edad);
	}
	for (int i = 0; i < names.size(); i++)
	{
		for (int j = 0; j < age.size(); j++)
			cout << names[i] << " " << age[j] << '\n';
	}
}
void ejercicio6()
{
	vector<string>names;
	vector<int>age;
	int limite;
	string nombre;
	int edad;
	cout << "Ingresa un limite para los datos: \n"
		<< "\nPuedes escribir exit para dejar de ingresar datos. \n";
	cin >> limite;
	cout << "El limite de datos que se pueden ingresar es de: " << limite << '\n';

	while (cin >> nombre)
	{
		if (nombre == "exit")
		{
			exit(-1);
			break;
		}
		names.push_back(nombre);
		cout << "Ingresa una edad: \n";
		cin >> edad;
		age.push_back(edad);
		if (names.size() > limite)
		{
			error("Fuera del limite establecido");
			exit(-1);
		}
	}
	for (int i = 0; i < names.size(); i++)
	{
		for (int j = 0; j < age.size(); j++)
			cout << names[i] << " " << age[j] << '\n';

	}
}
void ejercicio7()
{
	vector<double>weight;
	vector<double>price;
	double peso;
	double precio;
	double resultado;
	cout << "Ingresa el caracter pipe para dejar de ingresar datos.\n";
	cout << "Ingresa un peso: \n";
	while (cin >> peso)
	{
		weight.push_back(peso);
		cout << "Ingresa un precio: \n";
		cin >> precio;
		price.push_back(precio);
	}
	if (weight.size() == price.size())
	{
		for (int i = 0; i < weight.size(); i++)
		{
			for (int j = 0; j < price.size(); i++)
				resultado = price[j] * weight[i];
		}
		cout << "La suma de todos los valores es igual a: " << resultado;
	}
	else
	{
		error("El tamaño de los vectores no coincide.");
		exit(-1);
	}
	
}
void maxv()
{
	vector<int>valores;
	int numeros;
	cout << "Ingresa los numeros que se almacenarán en el vector."
		<< "\nAl final, el programa devolvera el numero mas alto que se haya ingresado: \n";
	while (cin >> numeros)
	{
		valores.push_back(numeros);
	}
	for (int i = 0; i < valores.size(); i++)
	{
		if (valores[i] > valores[i + 1])
			cout <<"El valor mayor es: " << valores[i];
		else if (valores[i] < valores[i + 1])
			cout <<"El valor mayor es: " << valores[i + 1];
	}
}

int main()
{
	cout << "Escoge un numero del 1 al 9 para ver los diferentes ejercicios: \n";
	int eleccion;
	cin >> eleccion;
	switch (eleccion)
	{
	case 1:
		print();
		keep_window_open();
		break;
	case 2:
		ejercicio2();
		keep_window_open();
		break;
	case 3:
		ejercicio3();
		keep_window_open();
		break;
	case 4:
		ejercicio4();
		keep_window_open();
		break;
	case 5:
		ejercicio5();
		keep_window_open();
		break;
	case 6:
		ejercicio6();
		keep_window_open();
		break;
	case 7:
		ejercicio7();
		keep_window_open();
		break;
	case 8:
		maxv();
		keep_window_open();
		break;
	}


	return 0;
	keep_window_open();
}