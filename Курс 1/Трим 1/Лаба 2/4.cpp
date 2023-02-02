#include <iostream>


int main()
{
	setlocale(LC_ALL, "");

	float start_x, end_x, dx, i, a ,c;

	std::cout << "Start X = ";
	std::cin >> start_x;
	std::cout << "End X = ";
	std::cin >> end_x;
	std::cout << "dX = ";
	std::cin >> dx;
	std::cout << "a = ";
	std::cin >> a;
	std::cout << "c = ";
	std::cin >> c;

	std::cout << "Таблица значения функции F на интервале от " << start_x << " до  " << end_x << " с шагом  " << dx << std::endl;
	std::cout << "  X  |  F  " << std::endl;

	float n;
	for (float x = start_x; x <= end_x; x+=dx)
	{
		if (c < 0 && a != 0)
			n = -1 * a * (x * x);
		else
		{
			if (c > 0 && a == 0)
				n = (a - x) / (c * x);
			else
				n = x / c;
		}
		std::cout << "  " << x << "  |  " << n << "  " << std::endl;
	}
}