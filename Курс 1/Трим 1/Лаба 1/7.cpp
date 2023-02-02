#include <stdio.h>

int main(void)
{
    int A;
    printf("A:");
    scanf("%i", &A);

    printf("%i\n", A / 100 * 10 + (A % 100) / 10 * 100 + A % 10);

    return 0;
}
