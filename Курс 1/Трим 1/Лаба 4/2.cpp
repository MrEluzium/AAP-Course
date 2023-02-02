#include <iostream>

void fill_array_f(int* arr);

void write_array_backward_f(int* arr, int n);

int array_sum(int* arr, int n);

int array_prod(int* arr, int n);

int main()
{
	setlocale(LC_ALL, "Russian");

	int n;
	std::cout << "N = ";
	std::cin >> n;

	int* arr = new int[n];

	fill_array_f(arr);

	std::cout << "����� = " << array_sum(arr, n) << std::endl;
	std::cout << "������������ = " << array_prod(arr, n) << std::endl;

	write_array_backward_f(arr, n);
}

void fill_array_f(int* arr)
{
	FILE* f;
	int x, i = 0;
	fopen_s(&f, "input.txt", "r");
	if (f == 0) return;

	while ((fscanf_s(f, "%d", &x)) != EOF)
	{
		arr[i] = x;
		i++;
	}
	fclose(f);
}

void write_array_backward_f(int* arr, int n)
{
	FILE* f;

	fopen_s(&f, "output.txt", "w+");
	if (f == 0) return;

	for (size_t i = 1; i <= n; i++)
		fprintf(f, "%d \n", arr[n-i]);

	fclose(f);
}

int array_sum(int* arr, int n)
{
	int s = 0;
	for (size_t i = 0; i < n; i++)
		s += arr[i];
	return s;
}

int array_prod(int* arr, int n)
{
	int p = 1;
	for (size_t i = 0; i < n; i++)
		p *= arr[i];
	return p;
}
