// Вариант 5
#include <iostream>

int main()
{
    setlocale(LC_ALL, ""); // Задает языковой стандарт по умолчанию. Для вывода кириллицы в консоль.
    int n, x, sided_num;

    std::cout << "N = ";
    std::cin >> n;

    sided_num = n / 100;
    n = n - (n / 100 * 100);
    n = ((n - (n / 10 * 10)) * 10) + (n / 10);
    x = n * 10 + sided_num;
    std::cout << "X = " << x;
}
