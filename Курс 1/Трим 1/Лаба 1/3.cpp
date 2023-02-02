#include <iostream>

int main()
{
    setlocale(LC_ALL, ""); // Задает языковой стандарт по умолчанию. Для вывода кириллицы в консоль.

    int h1, m1, s1, h2, m2, s2, start_sec, diff_sec, full_sec;
    std::cout << "Начальное время в формате HH:MM:SS" << std::endl;
    scanf_s("%d:%d:%d", &h1, &m1, &s1);
    std::cout << "Промежуток в формате HH:MM:SS" << std::endl;
    scanf_s("%d:%d:%d", &h2, &m2, &s2);

    h1 = (h1 + h2) % 24 + ((m1 + m2) / 60);
    m1 = (m1 + m2) % 60 + ((s1 + s2) / 60);
    s1 = (s1 + s2) % 60;

    printf("Время: %d:%d:%d\n", h1, m1, s1);
}

