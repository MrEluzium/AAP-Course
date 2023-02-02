#include <iostream>

int main()
{
	setlocale(LC_ALL, "");
	int n;
	float x;
	std::cout << "n: ";
	std::cin >> n;
	std::cout << "x: ";
	std::cin >> x;

	float s = 0;
	for (size_t i = 1; i <= n; i++)
	{
		int aspect = i % 2 ? 1 : -1;
		s += aspect * ((pow(x, i)) / i);
		//std::cout << aspect << ' ' << i << ' ' << s << std::endl;
	}

	float f = log1p(x);

	std::cout << "Сумма n первых членов ряда = " << s << std::endl << "ln(x + 1) = " << f;
}