
#include <iostream>
#include <conio.h>
#include "Includes.h"
using namespace std;

class Point
{
public:
	int x, y;
	friend istream& operator>>(istream&in, Point& p);
	Point(int a, int b)
	{
		a = x;
		b = y;
	}
	Point()
	{
	}
}; 

vector<Point>points; 

istream& operator>>(istream& is, Point& p)
{
	is >> p.x >> p.y;
	return is;
}
ostream& operator<<(ostream&os, Point& s)
{
	return os << s.x << "," << s.y << " ";
}
/* fill_from_file(vector<Point>&points, string& name)
{
	ifstream ist{ name };
	if (!ist) error("Can't open input file ", name);
}
*/
void lectura();
int main()
{
	
	/*cout << "Ingresa el nombre del archivo: \n";
	string iname;
	std::cin >> iname;
	ifstream ist{ iname };
	if (!ist) error("No se pudo abrir el archivo ", iname);
	for (points; ist >> p;)
		points.push_back(p);
	cout << "Please enter name of output file:\n ";
	string oname;
	std::cin >> oname;
	ofstream ost{ oname };
	if (!ost) error("can't open output file ", oname);
	for (Point p : points)
		ost << '(' << p.x << ',' << p.y << ")\n";
	*/
	cout << "Ingresa valores para las varianles de tipo Points, solo aceptara dos enteros: \n";
	vector<Point>original_points;
	Point p;
	int valores, valores2;
	int contador = 0;
	while (cin>>valores and cin>>valores2)
	{
		if (contador == 7)
			break;
		p.x = valores;
		p.y = valores2;
		original_points.push_back(p);
		contador= contador+1;
	}
	ofstream archivo;
	archivo.open("mydata.txt", ios::out);

	if (archivo.fail())
	{
		cout << "Error";
		exit(1);
	}
	cout << "Los valores que se ingresaron son: ";
	for (auto z : original_points)
	{
		cout << z;
		archivo << z;
	}
	archivo.close();
	lectura();

	
	keep_window_open();
	return 0;
} 
void lectura()
{
	ifstream file;
	string valores;

	file.open("mydata.txt", ios::in);

	if (file.fail())
	{
		cout << "Error.";
		exit(1);
	}
	while (!file.eof())
	{
		getline(file, valores);
		cout <<"\nLos valores dentro del archivo son:  " << valores << '\n';
	}
	file.close();
	
}