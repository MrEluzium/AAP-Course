#include <iostream>
#include <stdio.h>

double F(int n)
{
	return pow(-1, n) / pow(4, n) * (2 * n + 1);
}

int main()
{
	double eps, cur, prev = .0, s = .0;
	int n = 0;

	std::cout << "Eps = ";
	std::cin >> eps;

	cur = F(n);
	while (abs(cur - prev) >= eps)
	{
		std::cout << cur << " " << abs(cur - prev) << std::endl;
		s += cur;
		n++;
		prev = cur;
		cur = F(n);
	}

	std::cout << s;
}