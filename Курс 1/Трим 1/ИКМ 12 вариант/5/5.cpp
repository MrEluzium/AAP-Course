#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>

double** read(int col, int row);

// задание 5
int main() {
    setlocale(LC_ALL, "");
    int row, col;
    std::cout << "row: ";
    std::cin >> row;
    std::cout << "col: ";
    std::cin >> col;

    double** arr = read(row, col);

    for (int count_row = 0; count_row < row; count_row++)
    {
        int zero_count = 0;
        for (int count_column = 0; count_column < col; count_column++) {
            if (arr[count_row][count_column] == 0.0)
                zero_count++;
        }

        std::cout << "Строка " << count_row + 1 << ": " << zero_count << std::endl;
    }
}

double** read(int col, int row)
{
    std::ifstream f("input.txt");

    double** arr = new double* [col];
    for (int i = 0; i < col; i++) {
        arr[i] = new double[row];
        for (int j = 0; j < row; j++)
            f >> arr[i][j];
    }
    f.close();

    return arr;
}
