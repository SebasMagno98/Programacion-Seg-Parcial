#include <iostream>
#include <conio.h>
#include "Includes.h"


using namespace std;
struct Reading
{
public:
	int hora;
	double temperatura;
	Reading(){}
};
/*ostream &operator<<(ostream &os, Reading const &r)
{
	return os << r.hora << ", " << r.temperatura << '\n';
}
*/
istream& operator>>(istream&is, Reading& r)
{
	is >> r.hora >> r.temperatura;
	return is;
}
ostream& operator<<(ostream&os, Reading r)
{
	return os << r.hora << "," << r.temperatura << " ";
}

void lectura();

int main()
{
	cout << "Ingresa un total de 50 lecturas de temperatura, las cuales se agregaran a un archivo.\n\n"
		<< "Las temperaturas ingresadas seran tomadas como celsius, posterioremente seran transformadas a Farenheit.\n";
	vector<Reading>lecturas;
	int hora;
	double temperatura;
	Reading r;
	int contador = 0;
	while (cin >> hora >> temperatura)
	{
		if (contador == 50)
			break;
		if (hora < 0 or 23 < hora)
		{
			cout << "Hora fuera de rango";
			exit(1);
		}
		r.hora = hora;
		r.temperatura = (temperatura/1.8) + 32;
		lecturas.push_back(r);
		contador = contador + 1;
	}
	ofstream file;
	file.open("raw_temps.txt", ios::out);

	if (file.fail())
	{
		cout << "No se pudo abrir el archivo.\n";
		exit(1);
	}
	for (auto x : lecturas)
	{
		file << x;
	}
	file.close();
	double temp = 0;
	for (int i = 0; i < lecturas.size(); i++)
	{
		temp = temp + r.temperatura;
	}
	temp = temp / 50;
	cout << "La media de las temperaturas ingresadas es: " << temp << '\n';
	
	keep_window_open();
	return 0;
}
void lectura()
{

}