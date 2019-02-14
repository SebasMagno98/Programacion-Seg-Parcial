#include "includes.h"
#include <iostream>

void TryThis()
{
	vector<double>temps;

	for (double temp; cin >> temp;)
		temps.push_back(temp);
	double sum = 0;
	double high_temp = 0;
	double low_temp = 0;

	for (double x : temps)
	{
		if (x > high_temp) high_temp = x;
		if (x < low_temp)low_temp = x;
		sum += x;
	}
	std::cout << "High temperature: " << high_temp << '\n';
	std::cout << "Low temperature: " << low_temp << '\n';
	std::cout << "Average Temperature: " << sum / temps.size() << '\n';


}
/*double ctok()
{
	int k = c + 273.15;  "Este es el primer error, ya que es un entero cuando debería de ser un tipo Double".
	return int          "Aquí faltó ";" además de que la funcion es de tipo Double, por lo tanto es un error indicar que retorne un tipo int.
}
int main()
{
	double c = 0;
	cin >> d;             "La variable d es irrelevante ya que no tiene ninguna funcion dentro del programa. Deberia ser la variable c".
	double k =ctok("c");
	Cout << k << '\n';         "cout esta mal escrito, no debe llevar ninguna letra en mayuscula.
}*/

void ejercicio1()
{
	double c;
	std::cout << "Ingresa una temperatura en Celsius para que sea convertida a Kelvin: \n";
	cin >> c;
	double kelvin = c + 273.15;
	std::cout << "La temperatura " << c << " es: " << kelvin << " en Kelvin.\n";
	keep_window_open();
}
void ejercicio2()
{
	double c;
	std::cout << "Ingresa una temperatura en Celsius para que sea convertida a Kelvin: \n";
	cin >> c;
	if (c < -273.15)
	{
		std::cout << "No se puede convertir, la temperatura dada es muy baja. \n";
	}
	double kelvin = c + 273.15;
	std::cout << "La temperatura " << c << " es: " << kelvin << " en Kelvin.\n";
	keep_window_open();

}
void ejercicio3()
{
	double c;
	std::cout << "Ingresa una temperatura en Celsius para que sea convertida a Kelvin: \n";
	cin >> c;
	if (c < -273.15)
	{
		std::cout << "No se puede convertir, la temperatura dada es muy baja. \n";
	}
	double kelvin = c + 273.15;
	std::cout << "La temperatura " << c << " es: " << kelvin << " en Kelvin."
		<< "\nIngresa la cantidad de grados Kelvin que quieres convertir a Celsius: \n ";
	double k;
	cin >> k;
	if (k < 0)
	{
		std::cout << "La temperatura dada es muy baja, no se puede convertir. \n";
	}
	double KtoC = k - 273.15;
	std::cout << "La temperatura " << k << " es :" << KtoC << "en Celisus. \n";
	keep_window_open();
}
void ejercicio4()
{
	double c;
	std::cout << "Ingresa una temperatura en Celsius para que sea convertida a Farenheit: \n";
	cin >> c;
	double farenheit = (c*1.8) + 32;
	std::cout << "La temperatura " << c << " es: " << farenheit << " en Farenheit."
		<< "\nAhora escribe una temperatura en Farenheit para que sea convertida a Celsius:\n";
	double f;
	cin >> f;
	double FtoC = (f - 32) * 0.555;
	std::cout << "La temperatura: " << f << " farenheit es " << FtoC << " en Celsius. \n";
	keep_window_open();
}



void ejercicio5()
{
	{
		double c;
		std::cout << "Ingresa una temperatura en Celsius para que sea convertida a Farenheit y Kelvin: \n";
		cin >> c;
		double farenheit = (c*1.8) + 32;
		double kelvin = c + 273.15;
		std::cout << "La temperatura " << c << " es: " << farenheit << " en Farenheit y " << kelvin << " en grados Kelvin."
			<< "\nAhora escribe una temperatura en Farenheit para que sea convertida a Celsius:\n";
		double f;
		cin >> f;
		double FtoC = (f - 32) * 0.555;
		double FtoK = ((f - 32) / 1.800) + 273.15;
		std::cout << "La temperatura: " << f << " farenheit es " << FtoC << " en Celsius y" << FtoK << " en Kelvin.\n";
		keep_window_open();
	}

}

int Raiz(int a, int b, int c)
{
	double Valor = 0;
	double Verificacion = 0;
	Verificacion = sqrt(a);
	Valor = sqrt(pow(b, 2) - (4 * a*c));
	if ((a*a) != Verificacion)
	{
		std::cout << "Estos valores no se pueden usar para la formula general.\n";
		cin >> Valor;
		exit(-1);
	}
	return Valor;
}

void ejercicio6()
{

	double a;
	double b;
	double c;
	std:cout << "En este programa vamos a resolver una ecuacion cuadratica por la formula general."
		<< "\nIngrese valores para los argumentos a, b y c, con un espacio entre cada uno.\n";
	cin >> a >> b >> c;
	double root = Raiz(a, b, c);
	double Paso1 = (-b + root);
	double Paso2 = (2 * a);
	double PasoAlt = (-b - root);
	double Resultado1 = Paso1 / Paso2;
	double Resultado2 = PasoAlt / Paso2;
	std::cout << "El valor del primer resultado es: " << Resultado1
		<< "\nEl valor del segundo resultado es: " << Resultado2 << '\n';
	keep_window_open();

}
void ejercicio7()
{
	std::cout << "En este programa, se sumaran los primeros n numeros de un vector."
	<< "\nIngresa la cantidad de elementos del vector que quieres que se sumen.";
	double resultado = 0;
	int max;
	cin >> max;
	std::cout << "Ahora ingresa los valores que estaran dentro del vector y para dejar de ingresarlos, escribe el caracter '│'. \n";
	vector<int>valores;
	
	for (int x; cin >> x;)
	{
		valores.push_back(x);
	}
	if (max > valores.size())
	{
		std::cout << "El valor maximo que ingreso es superior al tamaño maximo del vector. Presiona cualquier boton para cerrar. \n";
		cin >> max;
		exit(-1);

	}
	for (int i = 0; i < max; i++)
	{
		resultado = resultado + valores[i];
	}
	std::cout << "La suma de los valores es: " << resultado << '\n';
	keep_window_open();
}
void ejercicio8()
{
	std::cout << "En este programa, se sumaran los primeros n numeros de un vector."
		<< "\nIngresa la cantidad de elementos del vector que quieres que se sumen.";
	int diferencia;
	double resultado = 0;
	int max;
	cin >> max;
	std::cout << "Ahora ingresa los valores que estaran dentro del vector y para dejar de ingresarlos, escribe el caracter '│'. \n";
	vector<double>valores;

	for (double x; cin >> x;)
	{
		valores.push_back(x);
	}
	if (max > valores.size())
	{
		std::cout << "El valor maximo que ingreso es superior al tamaño maximo del vector. Presiona cualquier boton para cerrar. \n";
		cin >> max;
		exit(-1);

	}
	for (int i = 0; i < max; i++)
	{
		resultado = resultado + valores[i];
	}
	std::cout << "La suma de los valores es: " << resultado << '\n';
	for (int i = 0; i < valores.size(); i++)
	{
		diferencia = valores[1] - valores[i + 1];
		std::cout << "La diferencia entre " << valores[1] << " y " << valores[i + 1] << " es igual a: " << diferencia << '\n';
	}
	keep_window_open();
}
void ejercicio9()
{
	std::cout << "En este programa se imprimirán los numeros de la secuencia Fibonacci. \n";
	int num = 0;
	int num2 = 1;
	int resultado = 0;
	for (int i = 0; i < 10; i++)
	{
		if (i == 0)
		{
			num2 = 0;
		}
		else if (i == 1)
		{
			num2 = 1;
		}
		else if (i == 2)
		{
			num2 = 0;
		}
		resultado = num + num2;
		num = num2;
		num2 = resultado;
		std::cout << resultado << '\n';
	}
	keep_window_open();
}	
void ejercicio10()
{
	std::cout << "En este programa, haremos un pequeño juego de adivinar numeros."
		<< "\nPor cada numero correcto que hayas adivinado se sumara un toro, se ganara si se alcanzo el numero de 4 toros."
		<< "\nY Por cada numero incorrecto se sumara una vaca, al final del programa se dirán cuantos toros y cuantas vacas se han obtenido.\n";
	vector<int>adivinar{ 1,2,3,4 };
	int toros = 0;
	int vacas = 0;
	int primAdi;
	int SegAdi;
	int TerAdi;
	int CuarAdi;
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
	keep_window_open();
}
void ejercicio11()
{
	std::cout << "En este programa, haremos un pequeño juego de adivinar numeros."
		<< "\nPor cada numero correcto que hayas adivinado se sumara un toro, se ganara si se alcanzo el numero de 4 toros."
		<< "\nY Por cada numero incorrecto se sumara una vaca, al final del programa se dirán cuantos toros y cuantas vacas se han obtenido.\n"
		<< "\nEsta vez los valores dentro a adivinar van a variar, aunque seguiran siendo del rango del 0 al 10.";
	vector<int>adivinar{randint(10),randint(10),randint(10),randint(10)};
	int toros = 0;
	int vacas = 0;
	int primAdi;
	int SegAdi;
	int TerAdi;
	int CuarAdi;
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
		ejercicio11();
	}
	else
	{
		std::cout <<"Hasta la proxima.\n";
		exit(-1);
	}
	keep_window_open();
}

void ejercicio12()
{
	std::cout << "En este programa ingresa dos pares de informacion, un dia de la semana y un numero."
		<< "\nAl final, el programa regresara la suma de los numeros ingresados, asi como tambien la suma de los numeros de los dias de la semana."
		<< "\nIngresa el caracter '│' para dejar de ingresar valores.\n";

	int ValoresRech = 0;
	int sumaNum = 0;
	string day;
	int num=0;
	vector<int>valores;
	vector<string>dias;
	while (dias.size() > 6)
	{
		std::cout << "Ingresa un dia de la semana y un numero, separados por un enter.\n";
		cin >> day;
		cin >> num;
		if (day == "lunes" or day == "martes" or day == "miercoles" or day == "jueves" or day == "viernes" or day == "sabado" or day == "domingo")
		{
			dias.push_back(day);
		}
		else
		{
			std::cout << "Ese dia no es valido.\n";
			ValoresRech += 1;
		}
		valores.push_back(num);
	}
	for (int i = 0; i < 6; i++)
	{
		sumaNum = sumaNum + valores[i];
	}
	std::cout << "La suma de todos los numeros ingresados es: " << sumaNum << '\n'
		<< "La cantidad de valores rechazados es de: " << ValoresRech << '\n';
	keep_window_open();
}
int drill()
{
	try {
		std::cout << "Success!\n";
			keep_window_open();
		return 0;
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
int drill5()
{
	try {
		int res = 7;
		vector<int>v(10);
		v[5] = res;
		std::cout << "Succes!\n";
			keep_window_open();
		return 0;
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
int drill6()
{
	try {
		vector <int> v(5);
		v[5] = 7;
		if (v[5] != 7)
			std::cout << "Succes!\n";
			keep_window_open();
		return 0;
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

int drill7()
{
	try {
		bool cond = true;
		if (cond)
		{
			std::cout << "Success!\n";
		}
		else
		{
			std::cout << "Fail!\n";
		}
		keep_window_open();
		return 0;
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
int drill8()
{
	try {
		bool cond = true;
		if (cond)
		{
			std::cout << "Success!\n";
		}
		else
		{
			std::cout << "Fail!\n";
		}
		keep_window_open();
		return 0;
			
		return 0;
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
int drill9()
{
	try {
		string s = "ape";
		if (s == "ape")
		{
			std::cout << "Success!\n";
		}
			keep_window_open();
		return 0;
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
int drill10()
{
	try {
		string s = "ape";
		if (s == "ape")
		{
			std::cout << "Success!\n";
		}
		keep_window_open();
		return 0;
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
int drill11()
{
	try {
		string s = "ape";
		if (s == "ape")
		{
			std::cout << "Success!\n";
		}
		keep_window_open();
		return 0;
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
int drill12()
{
	try {
		string s = "ape";
		if (s == "ape")
		{
			std::cout << "Success!\n";
		}
		keep_window_open();
		return 0;
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
	
int drill13()
{
	try {
		vector<char>v;
		for (int i = 0; i < v.size(); ++i)  
		{
			std::cout << "Success!\n";
		}
		keep_window_open();
		return 0;
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

int drill14()
{
	try {
		vector<char>v;
		for (int i = 0; i < v.size(); ++i)
		{
			std::cout << "Success!\n";
		}
		keep_window_open();
		return 0;
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

int drill15()
{
	try {
		string s = "Success!\n";
		for (int i = 0; i < 8; ++i)
		{
			cout << s[i];
		}
		std::cout << " " << '\n';
		keep_window_open();
		return 0;
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
int drill16()
{
	try {
		if (true)
		{
			std::cout << "Success!\n";
		}
		else
		{
			std::cout << "Fail!\n";
		}
		keep_window_open();
		return 0;
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
int drill17()
{
	try {
		int x = 2000;
		int c = x; 
		if (c == 2000)
		{
			std::cout << "Success!\n";
		}
		keep_window_open();
		return 0;
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
int drill18()
{
	try {
		string s = "Success!\n";
		for (int i = 0; i < 10; ++i)
		{
			std::cout << s[i];
		}
		std::cout << " " << '\n';
		keep_window_open();
		return 0;
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
int drill19()
{
	try {
		vector<int> v(5);
		for (int i = 0; i <= v.size(); ++i)
		{
			std::cout << "Success!\n";
		}
		keep_window_open();
		return 0;
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
int drill20()
{
	try {
		int i = 0;
		int j = 9;
		while (i < 10)
		{
			++i;
		}
		if (j < i)
		{
			std::cout << "Success!\n";
		}
		keep_window_open();
		return 0;
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
int drill21()
{
	try {
		int x = 2;
		double d = 5 / (x / 2);
		if (d == 2 * x + 1)
		{
			std::cout << "Success!\n";
		}
		keep_window_open();
		return 0;
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
int drill22()
{
	try {
		string s = "Success!\n"; 
		for (int i = 0; i < 10; ++i) 
		{
			std::cout << s[i];
		}
		keep_window_open();
		return 0;
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
int drill23()
{
	try {
		int i = 0;
		int j = 0;
		while (i < 10)
		{
			++i;
		}
		if (j < i)
		{
			std::cout << "Success!\n";
		}
		keep_window_open();
		return 0;
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
int drill24()
{
	try {
		int x = 4;
		double d = 5 / (x - 2);
		if (d = x - 2 + 0.5)
		{
			std::cout << "Success!\n";
		}
		keep_window_open();
		return 0;
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
int drill25()
{
	try {
		cout << "Success!\n";
		keep_window_open();
		return 0;
		keep_window_open();
		return 0;
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

int main()
{
	int eleccion;
	std::cout << "Ingresa un numero del 1 al 13 para ver los ejercicios."
		<< "\nEn esta ocasion el drill consta de 25 incisos, los cuales son errores que deben ser corregidos."
		<< "\nPara acceder alguno de los incisos de Drill, estos se encuentran entre los numeros 13 al 37.\n";
	cin >> eleccion;
	switch (eleccion)
	{
	case 1:
		ejercicio1();
		break;
	case 2:
		ejercicio2();
		break;
	case 3:
		ejercicio3();
		break;
	case 4:
		ejercicio4();
		break;
	case 5:
		ejercicio5();
		break;
	case 6:
		ejercicio6();
		break;
	case 7:
		ejercicio7();
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
		break;
	case 12:
		ejercicio12();
		break;
	case 13:
		drill();
		break;
	case 14:
		drill();
		break;
	case 15:
		drill();
		break;
	case 16:
		drill();
		break;
	case 17:
		drill5();
		break;
	case 18:
		drill6();
		break;
	case 19:
		drill7();
		break;
	case 20:
		drill8();
		break;
	case 21:
		drill9();
		break;
	case 22:
		drill10();
		break;
	case 23:
		drill11();
		break;
	case 24:
		drill12();
		break;
	case 25:
		drill13();
		break;
	case 26:
		drill14();
		break;
	case 27:
		drill15();
		break;
	case 28:
		drill16();
		break;
	case 29:
		drill17();
		break;
	case 30:
		drill18();
		break;
	case 31:
		drill19();
		break;
	case 32:
		drill20();
		break;
	case 33:
		drill21();
		break;
	case 34:
		drill22();
		break;
	case 35:
		drill23();
		break;
	case 36:
		drill24();
		break;
	case 37:
		drill25();
		break;
	}


	return 0;
	keep_window_open();
}