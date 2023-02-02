#include <iostream>
#include <utility>

void fill_array(int* arr, int n, int a, int b);

void print_array(int* arr, int n);

void write_array_f(int* arr, int n, const char* filename);

void selection_sort_from_min(int* arr, int n);

int main()
{
	setlocale(LC_ALL, "Russian");

	int n, a, b;
	std::cout << "N = ";
	std::cin >> n;
	std::cout << "A = ";
	std::cin >> a;
	std::cout << "B = ";
	std::cin >> b;


	int* arr = new int[n];

	fill_array(arr, n, a, b);

	std::cout << "\nМассив в неупорядоченном виде (записан в non_sorted.txt):\n";
	print_array(arr, n);
	write_array_f(arr, n, "non_sorted.txt");

	selection_sort_from_min(arr, n);

	std::cout << "\nМассив в упорядоченном виде (записан в sorted.txt):\n";
	print_array(arr, n);
	write_array_f(arr, n, "sorted.txt");
}

void fill_array(int* arr, int n, int a, int b)
{
	for (int i = 0; i < n; i++)
		arr[i] = (a + rand() % b); // случайно число в промежутке от a до b включительно
}

void print_array(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		std::cout << "Элемент " << i + 1 << " : " << arr[i] << std::endl;
}

void write_array_f(int* arr, int n, const char* filename)
{
	FILE* f;

	fopen_s(&f, filename, "w+");
	if (f == 0) return;

	for (int i = 0; i < n; i++)
		fprintf(f, "%d \n", arr[i]);

	fclose(f);
}

void selection_sort_from_min(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min_i = i;

		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[min_i])
				min_i = j;

		if (min_i != i)
			std::swap(arr[i], arr[min_i]);
	}
}
