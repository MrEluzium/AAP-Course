#include <iostream>
#include <stdio.h>

int faktorial(int n);

int main()
{
	setlocale(LC_ALL, "Ru");
	FILE* f;
	fopen_s(&f, "1.txt", "w+");
	int b, n = 0;
	std::cin >> n;
	for (int k = 1; k <= n - 1; k++)
	{
		b = faktorial(k);
		fprintf(f, "%d \n", b);
	}
	std::cout << n * b;
}

int faktorial(int n)
{
	if (n == 1)
		return 1;
	return faktorial(n - 1) * n;
}
