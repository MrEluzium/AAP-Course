#include <iostream>
#include <stdio.h>

void is_negative(int n, int* k)
{
	if (n < 0) { (*k)++; }
}


int main() {
	setlocale(LC_ALL, "Ru");
	FILE* f;
	int n = 1, count = 0;

	std::cout << "Введите набор чисел. 0 - конец\n" ;
	while (n != 0) {
		std::cin >> n;
		is_negative(n, &count);
	}

	std::cout << "Кол-во отрицательных = " << count << std::endl;
}
