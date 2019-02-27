#include "my.h"
#include <iostream>

int swap_v(int a, int b)
{
	int temp; temp = a, a = b; b = temp;
	return b, a;
}
int swap_r(int&a, int&b)
{
	int temp; temp = a, a = b; b = temp;
	return b, a;
}
/*
Esta no, se podra realizar ya que esta tomando dos valors que son constantes, por lo tanto no pueden cambiar.
int swap_cr(const int & a, const int & b)
{
	int temp; temp = a; a = b; b = temp;
	return b, a;
}
*/
int Drill2()
{
	int x = 7;
	int y = 9;
	swap_v(x, y);
	std::cout << y << x;
	std::cin.get();
	return x;
}
namespace X
{
	int var;

	void print()
	{
		std::cout << var;
	}
}
namespace Y
{
	int var;

	void print()
	{
		std::cout << var;
	}
}
namespace Z
{
	int var;

	void print()
	{
		std::cout << var;
	}
}
int Drill3()
{
	X::var = 7;
	X::print();
	using namespace Y;
	var = 9;
	print();
	{
		using Z::var;
		using Z::print;
		var = 11;
		print();
	}
	print();
	X::print();
	return 0;
}

int main()
{
	int foo = 7;
	print_foo();
	int i = 99;
	print(i);
	return 0;
}

