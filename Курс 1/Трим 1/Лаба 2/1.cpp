#include <iostream>

int main()
{
	setlocale(LC_ALL, "");
	int n, t, i;

	std::cout << "N: ";
	std::cin >> n;

	i = 1;
	t = 1;
	while (i < n)
	{
		std::cout << i << std::endl;
		t++;
		i = t * t;
	}
}