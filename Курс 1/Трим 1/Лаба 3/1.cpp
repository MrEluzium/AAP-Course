#include <stdio.h>

int main()
{
    FILE* f;
    int x;

    fopen_s(&f, "output.txt", "w+");
    puts("input number, end - 0");
    scanf_s("%d", &x);
    while (x != 0)
    {
        fprintf(f, "%d ", x);
        scanf_s("%d", &x);
    }
    fclose(f);

    fopen_s(&f, "output.txt", "r");

    while ((fscanf_s(f, "%d", &x)) != EOF)
        if (x > 0)
            printf("\n %d ", x);
    fclose(f);

    return 0;
}