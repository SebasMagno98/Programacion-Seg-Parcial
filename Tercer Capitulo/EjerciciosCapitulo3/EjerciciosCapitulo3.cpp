#include "Includes.h"
#include <iostream>

int main()
{
	std::cout << "Hola, elige un numero del 0 al 10 para ingresar a alguno de los ejercicios del tercer capitulo del libro:"
		<< "\nElige 0 para ver el Drill."
		<< "\nElige 1 para ver el primer ejercicio que convierte millas a kilometros."
		<< "\nElige 2 para ver el segundo ejercicio que va de declarar variables."
		<< "\nElige 3 para ver el tercer ejercicio que determina de entre dos cantidades cual es la menor, la mayor, la suma, la multiplicacion, etc."
		<< "\nElige 4 para ver el cuarto ejercicio que hace lo mismo que el anterior punto, pero con Doubles en lugar de Enteros."
		<< "\nElige 5 para ver el quinto ejercicio que va de ingresar 3 cantidades y el programa las organizara del mayor al menor."
		<< "\nElige 6 para ver el sexto ejercicio el cual hace lo mismo que el anterior, pero tomando palabras en lugar de cantidades."
		<< "\nElige 7 para ver el septimo ejercicio el cual determina si la cantidad ingresada por el usuario es un numero par o impar."
		<< "\nElige 8 para ver el octavo ejercicio el cual toma numeros escritos y regresa su digito."
		<< "\nElige 9 para ver el noveno ejercicio el cual toma un operador matematico y dos numeros dados por el usuario y hace la operacion correspondiente. "
		<< "\nElige 10 para ver el decimo ejercicio el cual determina la cantidad de dolares que el usuario posee. "
		<< '\n';
	int eleccion;
	cin >> eleccion;

	if (eleccion == 0)
	{
		std::cout << "Escribe un nombre: \n";
		string Nombre;
		cin >> Nombre;
		std::cout << "Escribe una edad: \n";
		int Edad;
		cin >> Edad;
		std::cout << "Escribe el nombre de un amigo: \n";
		string amigo;
		cin >> amigo;
		std::cout << "Escribe h si el amigo es hombre o m si es mujer: \n";
		char GeneroAmigo;
		cin >> GeneroAmigo;


		std::cout << "Querid@ " << Nombre << ","
			<< "¿Como estas el dia de hoy?"
			<< "\nYo, bien. Con mucho sueño."
			<< "\nLlegue a casa y no habia internet, así que tuve que esperar a que volviera y poder hacer tarea."
			<< "\nUna vez volvio, me puse a hacer varias cosas, entre ellas, hacer tarea y otras cosas que me han encargado."
			<< "\nPor cierto, has visto a " << amigo << " ultimamente?";
		if (GeneroAmigo == 'h') std::cout << "\nSi lo ves a el, a " << amigo << ", dile que me llame, por favor. ";


		if (GeneroAmigo == 'm') std::cout << "\nSi la ves a ella, a  " << amigo << ", dile que me llame, por favor";

		std::cout << "\nEscuche que recien fue tu cumpleaños y que cumpliste " << Edad << "años, felicidades!";
		if (Edad < 12)std::cout << "\nEl proximo año tendras " << Edad + 1;
		if (Edad == 17)std::cout << "\nEl proximo año ya podras votar";
		if (Edad > 70)std::cout << "\nEspero y estes disfrutando tu retiro";


		std::cout << "\nEn fin, Espero te encuentres bien, " << Nombre << "."
			<< "\nNos vemos luego, adios!"
			<< '\n'
			<< '\n'
			<< "\nAtentamente, Sebastian."
			<< '\n';
	}

	if (eleccion == 1)
	{
		std::cout << "Escribe la cantidad en millas que quieras saber en kilometros: \n";
		double millas;
		cin >> millas;
		double kilometros = millas * 1.609;
		std::cout << millas << " millas son: " << kilometros << " Kilometros. \n";
	}
	if (eleccion == 2)
	{
		char letra = 'j';
		std::cout << "una variable de tipo char, solo acepta un caracter y este debe estar dentro de comillas.\n";
		string palabra = "32";
		string p1 = "Perro";
		std::cout << "Una variable String no puede ser declarado con lo que sea, mientras este este dentro de comillas dobles.\n";
		int numero = 3;
		std::cout << "Una variable de tipo entero solo admite numeros enteros, y no aceptara decimales ni letras.\n";
		double numero1 = 1;
		double numero2 = 5.32;
		std::cout << "Las variables de tipo double, admiten numeros decimales y numeros enteros, los que posteriormente convertira en decimales.\n";
	}

	if (eleccion == 3)
	{
		std::cout << "Ingresa dos numeros enteros, plox: ";
		int val1;
		int val2;
		cin >> val1 >> val2;
		if (val1 > val2) std::cout << "El valor mayor es: " << val1 << ".\n";
		if (val1 < val2) std::cout << "El valor menor es: " << val1 << ".\n";
		if (val2 < val1) std::cout << "El valor menor es: " << val2 << ".\n";
		if (val1 < val2) std::cout << "El valor mayor es: " << val2 << ".\n";
		std::cout << "\nLa suma de los enteros dados es: " << val1 + val2
			<< "\nLa resta de los enteros dados es: " << val1 - val2
			<< "\nEl producto de la multiplicacion de los enteros es: " << val1 * val2
			<< '\n';
	}
	if (eleccion == 4)
	{
		std::cout << "Ingresa dos numeros Double, plox: ";
		double valu1;
		double valu2;
		cin >> valu1 >> valu2;
		if (valu1 > valu2) std::cout << "El valor mayor es: " << valu1 << ".\n";
		if (valu1 < valu2) std::cout << "El valor menor es: " << valu1 << ".\n";
		if (valu2 < valu1) std::cout << "El valor menor es: " << valu2 << ".\n";
		if (valu1 < valu2) std::cout << "El valor mayor es: " << valu2 << ".\n";
		std::cout << "\nLa suma de las cantidades dadas es: " << valu1 + valu2
			<< "\nLa resta de las cantidades dadas es: " << valu1 - valu2
			<< "\nEl producto de la multiplicacion de las cantidades es: " << valu1 * valu2
			<< '\n';
	}

	if (eleccion == 5)
	{
		std::cout << "ingresa 3 numeros enteros, seguido cada uno por un enter: \n";
		int num1;
		cin >> num1;
		int num2;
		cin >> num2;
		int num3;
		cin >> num3;
		if (num1 < num2 and num1 < num3 and num2 < num3) std::cout << "\nEl ordenamiento es: " << num1 << ", " << num2 << ", " << num3 << ".\n";
		if (num1 < num2 and num1 < num3 and num3 < num2) std::cout << "\nEl ordenamiento es: " << num1 << ", " << num3 << ", " << num2 << ".\n";
		if (num2 < num1 and num2 < num3 and num1 < num3) std::cout << "\nEl ordenamiento es: " << num2 << ", " << num1 << ", " << num3 << ".\n";
		if (num2 < num1 and num2 < num1 and num3 < num3) std::cout << "\nEl ordenamiento es: " << num2 << ", " << num3 << ", " << num1 << ".\n";
		if (num3 < num2 and num3 < num1 and num2 < num1) std::cout << "\nEl ordenamiento es: " << num3 << ", " << num2 << ", " << num1 << ".\n";
		if (num3 < num2 and num3 < num1 and num1 < num2) std::cout << "\nEl ordenamiento es: " << num3 << ", " << num1 << ", " << num2 << ".\n";
	}

	if (eleccion == 6)
	{
		std::cout << "Ingresa 3 nombres, dando enter despues de cada uno, plox: \n";
		string n1;
		cin >> n1;
		string n2;
		cin >> n2;
		string n3;
		cin >> n3;
		if (n1 < n2 and n1 < n3 and n2 < n3) std::cout << "\nEl ordenamiento es: " << n1 << ", " << n2 << ", " << n3 << ".\n";
		if (n1 < n2 and n1 < n3 and n3 < n2) std::cout << "\nEl ordenamiento es: " << n1 << ", " << n3 << ", " << n2 << ".\n";
		if (n2 < n1 and n2 < n3 and n1 < n3) std::cout << "\nEl ordenamiento es: " << n2 << ", " << n1 << ", " << n3 << ".\n";
		if (n2 < n1 and n2 < n1 and n3 < n3) std::cout << "\nEl ordenamiento es: " << n2 << ", " << n3 << ", " << n1 << ".\n";
		if (n3 < n2 and n3 < n1 and n2 < n1) std::cout << "\nEl ordenamiento es: " << n3 << ", " << n2 << ", " << n1 << ".\n";
		if (n3 < n2 and n3 < n1 and n1 < n2) std::cout << "\nEl ordenamiento es: " << n3 << ", " << n1 << ", " << n2 << ".\n";
	}

	if (eleccion == 7)
	{
		std::cout << "Ingresa un numero para saber si es un numero par o impar: \n";
		int number;
		cin >> number;
		if (number % 2 == 1) std::cout << "El numero " << number << " es impar. \n";
		if (number % 2 == 0) std::cout << "El numer o" << number << " es par. \n";
	}
	if (eleccion == 8)
	{
		std::cout << "Ingresa un numero con letras en minusculas en lugar de digitos, cualquier numero del 0 al 4: \n";
		string digito;
		cin >> digito;
		if (digito == "cero") {
			std::cout << "El digito para " << digito << " es: 0\n";
		}
		else if (digito == "uno") {
			std::cout << "El digito para " << digito << " es: 1\n";
		}
		else if (digito == "dos") {
			std::cout << "El digito para " << digito << " es: 2\n";
		}
		else if (digito == "tres") {
			std::cout << "El digito para " << digito << " es: 3\n";
		}
		else if (digito == "cuatro") {
			std::cout << "El digito para " << digito << " es: 4\n";
		}
		else
		{
			std::cout << "Ese numero no lo conozco, gomen. \n";
		}
	}
	if (eleccion == 9)
	{
		std::cout << "ingresa un operador matematico de la operacion que quieras hacer: \n"
			<< "\nElige entre: +,-,*,/ ";
		string operador;
		cin >> operador;
		std::cout << "Ingresa dos numeros, presiona enter despues de cada uno: \n";
		int cantidad1;
		cin >> cantidad1;
		int cantidad2;
		cin >> cantidad2;

		if (operador == "+") {
			std::cout << "La suma de los numeros que ingresaste es: " <<cantidad1 + cantidad2 << ".\n";
		}
		else if (operador == "-") {
			std::cout << "La resta de los numeros que ingresaste es: " << cantidad1 - cantidad2 << ".\n";
		}
		else if (operador == "-") {
			std::cout << "La resta de los numeros que ingresaste es: " << cantidad1 - cantidad2 << ".\n";
		}
		else if (operador == "*") {
			std::cout << "La multiplicacion de los numeros que ingresaste es: " << cantidad1 * cantidad2 << ".\n";
		}
		else if (operador == "/") {
			std::cout << "La division de los numeros que ingresaste es: " << cantidad1 / cantidad2 << ".\n";
		}
	}
	if (eleccion == 10)
	{
		std::cout << "Cuantos pennies tienes?\n";
		double penny;
		cin >> penny;
		double nickel;
		std::cout << "Cuantos nickels tienes?\n";
		cin >> nickel;
		double dimes;
		std::cout << "Cuantos dimes tienes?\n";
		cin >> dimes;
		double cuartos;
		std::cout << "Cuantos quarters tienes?\n";
		cin >> cuartos;
		double medio;
		std::cout << "Cuantos medios dolar tienes?\n";
		cin >> medio;
		std::cout << "Tienes " << penny << " pennies."
			<< "\nTienes " << nickel << " nickels."
			<< "\nTienes " << dimes << " dimes."
			<< "\nTienes " << cuartos << " cuartos."
			<< "\nTienes " << medio << " medios dolar.\n";

		medio = medio * 50;
		nickel = nickel * 5;
		dimes = dimes * 10;
		cuartos = cuartos * 25;
		std::cout << "Lo que nos da un total de: " << (penny + medio + dimes + cuartos) / 100 << " dolares.\n";
	}


	keep_window_open();
	return 0;
}