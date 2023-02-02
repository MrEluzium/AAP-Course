#include <iostream>

void fill_array_f(float* arr);

void print_array(float* arr, int n);

float get_sum_above_avg(float* arr, int n);

int main()
{
	setlocale(LC_ALL, "Russian");

	int n;
	std::cout << "N = ";
	std::cin >> n;

	float* arr = new float[n];

	fill_array_f(arr);
	print_array(arr, n);

	std::cout << "Ñóììà ýëåìåíòîâ, áîëüøèõ ñðåäíåãî àðèôìåòè÷åñêîãî çíà÷åíèÿ = " << get_sum_above_avg(arr, n);

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
		std::cout << "Ýëåìåíò " << i + 1 << " : " << arr[i] << std::endl;
}

float get_sum_above_avg(float* arr, int n)
{
	float avg = .0f, s = .0f;

	for (int i = 0; i < n; i++)
		s += (arr[i]);
	avg = s / (n);

	s = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] > avg) s += arr[i];
	return s;
}