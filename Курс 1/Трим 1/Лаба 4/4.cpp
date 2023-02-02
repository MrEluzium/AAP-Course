#include <iostream>

void fill_array_f(float* arr);

void print_array(float* arr, int n);

void remove(float* arr, int n, int rem_n);

void remove_el_above_avg(float* arr, int& n);

void insert(float* arr, int& n, float x, int pos);

void insert_after_min(float* arr, int& n, float x);

int main()
{
	setlocale(LC_ALL, "Russian");

	int n, k;
	std::cout << "N = ";
	std::cin >> n;
	std::cout << "K = ";
	std::cin >> k;

	float* arr = new float[n];

	fill_array_f(arr);

	std::cout << "\nИсходный массив:\n";
	print_array(arr, n);

	remove_el_above_avg(arr, n);

	std::cout << "\nМассив после удаления элементов, меньше среднего:\n";
	print_array(arr, n);

	insert_after_min(arr, n, k);

	std::cout << "\nМассив после добавления K после минимального:\n";
	print_array(arr, n);
}

void fill_array_f(float* arr)
{
	FILE* f;
	float x;
	int i = 0;
	fopen_s(&f, "input.txt", "r");
	if (f == 0) return;

	while ((fscanf_s(f, "%f", &x)) != EOF)
	{
		arr[i] = x;
		i++;
	}
	fclose(f);
}

void print_array(float* arr, int n)
{
	for (int i = 0; i < n; i++)
		std::cout << "Элемент " << i + 1 << " : " << arr[i] << std::endl;
}

void remove(float* arr, int n, int rem_n)
{
	for (int i = rem_n; i < n; i++)
		arr[i] = arr[i + 1];

}

void remove_el_above_avg(float* arr, int& n)
{
	float avg = .0f, s = .0f;
	int count = 0;

	for (int i = 0; i < n; i++)
		s += (arr[i]);
	avg = s / (n);

	std::cout << "\nСреднее арифметическое: " << avg << std::endl;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] < avg)
		{
			remove(arr, n, i);
			n -= 1; i -= 1; // Обновляем количество элементов и корректирем проверяемый элемент с учетом того, что правая часть сдвинулась
		}
	}
}

void insert(float* arr, int& n, float x, int pos)
{
	n++;
	for (int i = n; i > pos; i--)
		arr[i] = arr[i - 1];
	arr[pos+1] = x;
}

void insert_after_min(float* arr, int& n, float x)
{
	float min = arr[0];
	int min_pos = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			min_pos = i;
		}
	}

	std::cout << "\nМинимальное значение: " << min << "\nПозиция минимального: " << min_pos << std::endl;

	insert(arr, n, x, min_pos);
}
