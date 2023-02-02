#include <iostream>
#include <vector>

int main()
{
	setlocale(LC_ALL, "");

	int n;
	int max = -1;
	std::vector<unsigned> n_array;

	std::cout << "Введиде последовательность. 0 - последний элемент." << std::endl;
	while (true)
	{
		std::cin >> n;
		n_array.emplace_back(n);
		max = (n > max) ? n : max;
		if (n < 1) break;
	}

	int max_count = 0;
	for (auto const& nn : n_array)
		if (nn == max) max_count++;

	std::cout << std::endl << "Количество повторений максимального элемента: " << max_count;
}