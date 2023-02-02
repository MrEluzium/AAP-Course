#include <iostream>

#include "long_operations.h"

int main()
{
    setlocale(LC_ALL, "");
    std::string s_longBinary;

    std::cout << "Введите двоичное число: ";
    std::cin >> s_longBinary;

    for (int i = 0; i < s_longBinary.size(); i++)
    {
        if (s_longBinary[i] != '1' && s_longBinary[i] != '0') {
            std::cout << "Введенные данные не являются двоичным числом";
            return -1;
        }
    }

    std::cout << "Результат в виде десятичного числа: " << long_bin_to_dec(s_longBinary) << std::endl;
    return 0;

}
