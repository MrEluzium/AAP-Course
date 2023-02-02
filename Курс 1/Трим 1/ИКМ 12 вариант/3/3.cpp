#include <iostream>
#include <climits>
#include <string>

void fill_array_f(int* arr);
void insert(int n, int* arr, int pos, int x);

// задание 3
int main()
{
	setlocale(LC_ALL, "");
	int n;
	std::cout << "N = ";
	std::cin >> n;

	int* arr = new int[n];

	fill_array_f(arr);

	int middle_n = (n + 1) / 2;
	insert(n, arr, middle_n, 0);
	insert(n, arr, middle_n + 1, 0);

	std::cout << "Массив с двумя нулями: ";
	for (int i = 0; i < (n + 2); i++)
		std::cout << arr[i] << " ";
}

void fill_array_f(int* arr)
{
	FILE* f;
	int x;
	int i = 0;
	fopen_s(&f, "input.txt", "r");
	if (f == 0) return;

	std::cout << "Исходный массив: ";
	while ((fscanf_s(f, "%d", &x)) != EOF)
	{
		std::cout << x << " ";
		arr[i] = x;
		i++;
	}
	fclose(f);
}

void insert(int n, int* arr, int pos, int x){
	for (int i = n + 1; i >= pos; i--)
		arr[i] = arr[i - 1];
	arr[pos] = x;
}
