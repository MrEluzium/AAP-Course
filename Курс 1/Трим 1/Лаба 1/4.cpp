#include <iostream>
#include <string>

std::string IntToHex(int decimal_n)
{
	int n;
	std::string hexadecimal_n;

	while (decimal_n > 0) {
		n = decimal_n % 16;
		switch (n)
		{
		case 10:
			hexadecimal_n += 'A'; break;
		case 11:
			hexadecimal_n += 'B'; break;
		case 12:
			hexadecimal_n += 'C'; break;
		case 13:
			hexadecimal_n += 'D'; break;
		case 14:
			hexadecimal_n += 'E'; break;
		case 15:
			hexadecimal_n += 'F'; break;
		default:
			hexadecimal_n += std::to_string(n); break;
		}
		decimal_n /= 16;
	}
	std::reverse(hexadecimal_n.begin(), hexadecimal_n.end());
	return hexadecimal_n;
}

int main()
{
    setlocale(LC_ALL, ""); // Задает языковой стандарт по умолчанию. Для вывода кириллицы в консоль.
    int decimal_n;

    std::cout << "Целое двузначное число: ";
    std::cin >> decimal_n;

    std::cout << IntToHex(decimal_n);
}
