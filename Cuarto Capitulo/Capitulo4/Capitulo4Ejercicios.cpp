#include "Includes.h"
#include <iostream>

int main()
{
	int opcion;
	std::cout << "Elige un numero del 1 al 12 para ir entre los ejercicios, siendo el numero uno el Drill del capitulo. \n";
	cin >> opcion;
	
	
		if (opcion == 1) 
		{
			vector <double>Medidas;
			std::cout << "Escoge dos de las siguientes cuatro unidades, escribe los caracteres correspondientes seguido de un Enter por cada una : m , in , ft , cm.\n";

			string medida1;
			string medida2;
			cin >> medida1;
			cin >> medida2;
			std::cout << "Escribe dos numeros, seguido de un Enter por cada uno. \n";
			double num1 = 0;
			double num2 = 0;
			cin >> num1;
			cin >> num2;
			Medidas.push_back(num1);
			Medidas.push_back(num2);
			sort(Medidas.begin(), Medidas.end());




			if (medida1 == "m")
			{

			}
			else if (medida1 == "in")
			{
				num1 = num1 * 39.37;

			}
			else if (medida1 == "ft")
			{
				num1 = num1 * 3.28;

			}
			else if (medida1 == "cm")
			{
				num1 = num1 * 100;

			}
			else
			{
				std::cout << "La medida ingresada no es valida. \n";
				

			}


			if (medida2 == "m" or "M")
			{

			}
			else if (medida2 == "in" or "IN")
			{
				num2 = num2 * 39.37;
			}
			else if (medida2 == "ft" or "FT")
			{
				num2 = num2 * 3.28;

			}
			else if (medida2 == "cm" or "CM")
			{
				num2 = num2 * 100;

			}
			else
			{
				std::cout << "La medida ingresada no es valida. \n";
				

			}
			
			if (num1 < num2) {
				std::cout << "El numero menor es: " << num1 << " " << medida1 << " y el numero mayor es: " << num2 << " " << medida2 << '\n'
					<< num1 << " Es el valor mas bajo."
					<< "\nLos valores del vector son: \n";
				for (auto x : Medidas)
					std::cout << x << ". \n";
			}
			else if (num1 == num2) {
				std::cout << "Ambos numeros son iguales. \n";
				for (auto x : Medidas)
					std::cout<< "Los numeros dentro del vector son: " << x << ". \n";
			}

			else
			{
				std::cout << "El numero menor es: " << num2 << " " << medida2 << " y el numero mayor es: " << num1 << " " << medida1 << '\n'
					<< num2 << " Es el valor mas bajo. \n";
				for (auto x : Medidas)
					std::cout << "Los numeros dentro del vector son: " << x << ". \n";
			}
			if (num1 - num2 <= 1.0) {
				std::cout << "Los numeros son casi iguales. \n";
				for (auto x : Medidas)
					std::cout << "Los numeros dentro del vector son: " << x << ". \n";
			}


		}

		if (opcion == 2)
		{
			std::cout << "Escribe una serie de numeros, y finaliza con un │, al final, el programa te dará la media de los numeros ingresados. \n ";
			vector <double> media;
			for (double a; cin >> a;)
				media.push_back(a);

			sort(media);
			cout << "La media de los numeros es: " << media[media.size() / 2] << '\n';
			keep_window_open();

		}
		if (opcion == 3)
		{
			std::cout << " Escribe una serie de numeros y finaliza con un │, los valores dados seran sumados al final, ademas de regresar la mediana y el mayor valor y el menor valor dado. \n";
			vector <double> distancia;
			for (double lejania; cin >> lejania;)
				distancia.push_back(lejania);
			double dis_total = 0;
			for (double x : distancia) dis_total += x;
			std::cout << "La distancia total es de : " << dis_total << '\n';
			sort(distancia);
			std::cout << "La distancia menor es: " << distancia[0] << " ,y la distancia mayor es: " << distancia[-1] << '\n';
			cin.get();


		}
		if (opcion == 5)
		{
			std::cout << "Este programa consta en una calculadora simple que realizara operaciones con dos numeros dados."
				<< "\nEscoge el operador, puedes elegir entre: +, -, *, /. \n";
			char oper;
			cin >> oper;
			std::cout << "Escoge dos numeros, pueden ser doubles, presiona espacio despues de cada numero. \n";
			double num1;
			double num2;
			cin >> num1 >> num2;
			if (oper == '+') std::cout << "La suma de los numeros dados es: " << num1 + num2 << '\n';
			else if (oper == '*') std::cout << "La multiplicacion de los numeros dados es: " << num1 * num2 << '\n';
			else if (oper == '-') std::cout << "La resta de los numeros dados es: " << num1 - num2 << '\n';
			else if (oper == '/') std::cout << "La division de los numeros dados es: " << num1 / num2 << '\n';
			else
			{
				std::cout << "El operador no es valido. \n";

			}

		
		}
		if (opcion == 6)
		{
			vector<string>listaNum = { "cero","uno","dos","tres","cuatro","cinco","seis","siete","ocho","nueve" };
			int num;
			std::cout << "Escribe un digito de entre 0 y 9. \n";
			cin >> num;
			switch (num)
			{
			case 0: std::cout << "La palabra para el digito escrito es: " << listaNum[0] << '\n';
				break;
			case 1: std::cout << "La palabra para el digito escrito es: " << listaNum[1] << '\n';
				break;
			case 2: std::cout << "La palabra para el digito escrito es: " << listaNum[2] << '\n';
				break;
			case 3: std::cout << "La palabra para el digito escrito es: " << listaNum[3] << '\n';
				break;
			case 4: std::cout << "La palabra para el digito escrito es: " << listaNum[4] << '\n';
				break;
			case 5: std::cout << "La palabra para el digito escrito es: " << listaNum[5] << '\n';
				break;
			case 6: std::cout << "La palabra para el digito escrito es: " << listaNum[6] << '\n';
				break;
			case 7: std::cout << "La palabra para el digito escrito es: " << listaNum[7] << '\n';
				break;
			case 8: std::cout << "La palabra para el digito escrito es: " << listaNum[8] << '\n';
				break;
			case 9: std::cout << "La palabra para el digito escrito es: " << listaNum[9] << '\n';
				break;
			}
		}
		if (opcion == 7) 
		{
			std::cout << "Este programa consta en una calculadora simple que realizara operaciones con dos numeros dados."
				<< "\nEscoge el operador, puedes elegir entre: +, -, *, /. \n";
			char oper;
			cin >> oper;
			std::cout << "Escoge dos numeros, los numeros deben ser de un solo digito. \n";
			int num1;
			int num2;
			cin >> num1 >> num2;
			if (num1 > 10) std::cout << "Ese numero contiene mas de un digito. \n";

			if (oper == '+') std::cout << "La suma de los numeros dados es: " << num1 + num2 << '\n';
			else if (oper == '*') std::cout << "La multiplicacion de los numeros dados es: " << num1 * num2 << '\n';
			else if (oper == '-') std::cout << "La resta de los numeros dados es: " << num1 - num2 << '\n';
			else if (oper == '/') std::cout << "La division de los numeros dados es: " << num1 / num2 << '\n';
			else
			{
				std::cout << "El operador no es valido. \n";

			}
		}
		if (opcion == 8)
		{
			std::cout << "En este programa veremos cuantos cuadrados se requieren para conseguir 1,000, 1,000,000 y 1,000,000,000 granos de arroz. \n";
			int cuadrados = 1;
			int granos = 1;
			while (granos <= 1000)
			{
				granos = granos * 2;
				cuadrados += 1;
				if (granos == 1000) std::cout << "La cantidad necesaria de cuadrados para conseguir 1000 granos es: " << cuadrados << '\n';
			}

			while ( granos <= 1000000)
			{
				granos = granos * 2;
				cuadrados += 1;
				if (granos == 1000000) std::cout << "La cantidad necesaria de cuadrados para conseguir 1000000 granos es: " << cuadrados << '\n';
			}

			while (granos <= 1000000000)
			{
				granos = granos * 2;
				cuadrados += 1;
				if (granos == 1000000000) std::cout << "La cantidad necesaria de cuadrados para conseguir 1000000000 granos es: " << cuadrados << '\n';

			}
		}
		if (opcion == 9)
		{
			int granos = 1;
			int cuadrados = 1;
			while (cuadrados <= 64)
			{
				granos = granos * 2;
				cuadrados += 1;
				cout << cuadrados << '\n';
			}
		}
		if (opcion == 10)
		{
			std::cout << "En este programa probaremos un juego de Piedra, Papel o Tijera contra la maquina. \n";
			vector<int>maquina;
			int jugador;
			std::cout << "ingresa un numero del 1 al 3."
				<< "\nSiendo 1 Piedra."
				<< "\nSiendo 2 Papel."
				<< "\nSiendo 3 Tijeras.\n";
			cin >> jugador;

			vector<int>PC;
			PC.push_back(2);
			PC.push_back(1);
			PC.push_back(3);

			switch (jugador)
			{
			case 1:
				if (PC[0] == 1) std::cout << "Gana PC. \n";
			case 2:
				if (PC[0] == 2) std::cout << "Empate. \n";
				
			case 3:
				if (PC[0] == 3) std::cout << "Gana Jugador.\n";
			}
			
			switch (jugador)
			{
			case 1:
				if (PC[1] == 1) std::cout << "Empate. \n";
			case 2:
				if (PC[1] == 2) std::cout << " Gana Jugador. \n";
			case 3:
				if (PC[1] == 3) std::cout << "Gana PC. \n";
			}
			
			switch (jugador)
			{
			case 1:
				if (PC[2] == 1) std::cout << " Gana Jugador. \n";
			case 2:
				if (PC[2] == 2) std::cout << "Gana PC. \n ";
			case 3:
				if (PC[2] == 3)std::cout << "Empate. \n";

			}
		}
		if (opcion == 11)
		{

			vector<int>Primos;
			Primos.push_back(2);
			for (int i = 2; i < 100; ++i)
				for (int j = 2; i < j; ++j)
				{
					if (i%j == 0)
						break;
					else if (i == j + 1)
						Primos.push_back(i);
					std::cout << "Los numeros primos son: " << i << '\n';
				}
			
				
		
		}
		if (opcion == 12)
		{
			vector<int>Primos;
			Primos.push_back(2);
			std::cout << "Ingresa un numero, el cual sera el numero maximo para que el programa encuentre los numeros primos. \n";
			int max;
			cin >> max;
			for (int i = 2; i < max; ++i)
				for (int j = 2; i < j; ++j)
				{
					if (i%j == 0)
						break;
					else if (i == j + 1)
						Primos.push_back(i);
					std::cout << "Los numeros primos son: " << i << '\n';
				}
		}

	keep_window_open();
	return 0;

}
