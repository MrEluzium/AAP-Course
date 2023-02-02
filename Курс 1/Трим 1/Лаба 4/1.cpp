#include <iostream>

void fill_array(float* arr, int n);

void print_array(float* arr, int n);

float get_avg(float* arr, int n);

int main()
{
	setlocale(LC_ALL, "Russian");

	int n;
	std::cout << "N = ";
	std::cin >> n;

	float* arr = new float[n];

	fill_array(arr, n);
	print_array(arr, n);
	std::cout << "Среднее значение = " << get_avg(arr, n);


}

void fill_array(float* arr, int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = static_cast<float>(rand() % 1000) / 10;
}

void print_array(float* arr, int n)
{
	for (int i = 0; i < n; i++)
		std::cout << "Элемент " << i + 1 << " : " << arr[i] << std::endl;
}

float get_avg(float* arr, int n)
{
	float s = 0;
	for (int i = 0; i < n; i++)
		s += arr[i];
	return s / n;
}