#include <iostream>

int is_s1mple(int k)
{
	int i;
	if (k > 1)
		for (i = 2; i < k; i++)
			if (k % i == 0) return 0;
	return 1;
}

int main()
{
	setlocale(LC_ALL, "");

	int a, b, i;

	std::cout << "A = ";
	std::cin >> a;
	std::cout << "B = ";
	std::cin >> b;

	for (i = a; i <= b; i++)
		if (is_s1mple(i)) std::cout << i << ' ';
}