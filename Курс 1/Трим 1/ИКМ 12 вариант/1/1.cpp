#include <iostream>


// задание 1
int main() {
    int n;
    std::cout << "N: ";
    std::cin >> n;

    double s = 0.0;
    for (int i = 1; i <= n; i++)
    {
        s += 1.0 / i;
    }

    std::cout << s;
}
