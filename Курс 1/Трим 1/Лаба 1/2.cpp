#include <iostream>
#include <math.h>

int main()
{
	setlocale(LC_ALL, ""); // Задает языковой стандарт по умолчанию. Для вывода кириллицы в консоль.

	const float pi = 3.1416;
	double r1, r2;

	std::cout << "Радиус R1: ";
	std::cin >> r1;

	std::cout << "Радиус R2: ";
	std::cin >> r2;

	if (r1 >= r2) return 1;

	double s = (pi * pow(r2, 2)) - (pi * pow(r1, 2));

	std::cout << "Площадь S = ";
	std::cout << s << std::endl;
}