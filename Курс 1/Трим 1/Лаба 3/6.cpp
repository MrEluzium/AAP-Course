#include <iostream>
#include <stdio.h>

void RectPS(int x1, int y1, int x2, int y2, int& P, int& S)
{
	P = 2 * (abs(x1 - x2) + abs(y1 - y2));
	S = abs(x1 - x2) * abs(y1 - y2);
}

int main() {
	setlocale(LC_ALL, "Ru");
	int x1, x2, y1, y2;
	int P = 0, S = 0;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "Треугольниик " << i+1 << std::endl << "x1 = ";
		std::cin >> x1;
		std::cout << "y1 = ";
		std::cin >> y1;
		std::cout << "x2 = ";
		std::cin >> x2;
		std::cout << "y2 = ";
		std::cin >> y2;
		RectPS(x1, y1, x2, y2, P, S);
		std::cout << "P = " << P << " S = " << S << "\n\n";
	}
}
