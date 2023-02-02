#include <iostream>
#include <vector>

int main()
{
	setlocale(LC_ALL, "");

	int n, k;
	std::vector<unsigned> n_array;

	std::cout << "Введиде последовательность. 0 - последний элемент." << std::endl;
	while (true)
	{
		std::cin >> n;
		n_array.emplace_back(n);
		if (n == 0) break;
	}

	std::cout << "K: ";
	std::cin >> k;

	int max_count = 0;
	for (auto const& nn : n_array)
		if (nn == k) max_count++;

	std::cout << std::endl << "Количество чисел в последовательности, равных K: " << max_count;
}