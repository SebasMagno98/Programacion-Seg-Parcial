#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
using namespace std;



/*struct Date {                                                                Version 9.4.1
	int y;
	int m;
	int d;
};

void init_Date(Date&dd, int y,int m, int d) //Checar si la fecha es válida.
{
	for (int i = 0; 0 <= 12; ++i)
	{
		for (int j = 0; j <= 3000; ++i)
		{
			for (int k = 0; k <= 31; ++i)
			{
				if (m == i && y == j && d == k)
				{
					dd.d = k;
					dd.m = i;
					dd.y = j;
				}
				else
				{
					cout << "Error, Fecha invalida. \n";
				}
			}
		}
	}
}
void add_day(Date&dd, int n) //Incrementar los dias de dd en n dias.
{
	dd.d = dd.d + n;
}
void f()
{
	Date today;
	init_Date(today, 12, 24, 2005);
	add_day(today, 1);
}
int main()
{
	Date today;
	today.y = 2012;
	today.m = 12;
	today.d = 24;
}

*/													

/*-------------------------------------------------------------------------------
									Version 9.4.2
struct Date {                                                                
	int y, m, d;
	Date(int y, int, int d);
	void add_day(int n);
};

void init_Date(Date&dd, int y,int m, int d) //Checar si la fecha es válida.
{
	for (int i = 0; 0 <= 12; ++i)
	{
		for (int j = 0; j <= 3000; ++i)
		{
			for (int k = 0; k <= 31; ++i)
			{
				if (m == i && y == j && d == k)
				{
					dd.d = k;
					dd.m = i;
					dd.y = j;
				}
				else
				{
					cout << "Error, Fecha invalida. \n";
				}
			}
		}
	}
}
void add_day(Date&dd, int n) //Incrementar los dias de dd en n dias.
{
	dd.d = dd.d + n;
}
void f()
{
	Date today;
	cout << today << '\n';
	init_Date(today, 2008, 3, 30);
	Date tomorrow;
	tomorrow.y = today.y;
	tomorrow.m = today.m;
	tomorrow.d = today.d + 1;
	cout << tomorrow << '\n';


}

int main()
{
	Date my_birthday;
	Date today {12,24,2007};
	Date last {2000, 12, 31}
	Date next {2014,2,14};

}
*/
//--------------------------------------------------------------------------------------------------------------------------------

enum class Month {													//Version 9.7.1
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Year
{
	static const int min = 1800;
	static const int max = 2200;
public:
	class invalid{};
	Year(int x) : y{ x } { if (x < min or max <= x) throw invalid{}; }
	int year() { return y; }
private:
	int y;
};
class Date {
public:
	Date(Year y, Month m, int d);

private:
	Year y;
	Month m;
	int d;
};
vector<string> month_tbl;
ostream& operator<<(ostream& os, Date const &x)
{
	return os;
}

int main()
{
	cout << "El Drill de este capítulo trata de utilizar el manejo de clases que se mostraron a traves de todo el capitulo.";
	Date dx{ Year{2019},Month::sep,10 };
	Date holiday{ 2051, Month::oct, 19 };
	Date d2 = holiday;
	Date d3 = Date{ 1978,Month::jul,4 };
	holiday = Date{ 1978, Month::dec,24 };
	d3 = holiday;
	cout << Date{ 1978,Month::dec,24 } << '\n';

	return 0;
	cin.get();
}


