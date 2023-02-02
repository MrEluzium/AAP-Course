#include <iostream>
#include <algorithm>
#include <string>

bool is_pol(int n)
{
    std::string str = std::to_string(n);
    return std::equal(str.cbegin(), str.cbegin() + str.size() / 2, str.crbegin());
}

int main()
{
    FILE* f;
    int a, b, x;
    std::cout << "A = ";
    std::cin >> a;
    std::cout << "B = ";
    std::cin >> b;


    fopen_s(&f, "output.txt", "w+");
    for (size_t i = a; i <= b; i++)
    {
        if (is_pol(i))
            fprintf(f, "%d \n", i);
    }

    fclose(f);
}