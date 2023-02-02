#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

int main()
{
    FILE* f;
    int x = 1, pos = 0, neg = 0;

    fopen_s(&f, "input.txt", "r");

    while ((fscanf_s(f, "%d", &x)) != EOF)
    {
        if (sgn(x) == 1)
            pos++;
        else if (sgn(x) == -1)
            neg++;
    }
    fclose(f);

    std::cout << "Positive: " << pos << "\nNegative: " << neg;

    return 0;
}