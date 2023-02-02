#include <iostream>

int number_of_odd(int n, int count = 0);

// задание 2
int main() {
    int n;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "N: ";
        std::cin >> n;
        std::cout << "Number of odd: " << number_of_odd(n) << std::endl;
    }
}

int number_of_odd(int n, int count = 0) {
    if (n != 0) {
        if ((n % 10) % 2 != 0)
            return number_of_odd(n / 10, count += 1);

        return number_of_odd(n / 10, count);
    }
    return count;
}
