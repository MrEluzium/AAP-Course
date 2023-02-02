// вариант 5
#include <iostream>

float calculate_trip_cost(float dacha_distance, float fuel_consumption, float fuel_price)
{
    float trip_cost = (dacha_distance / 100) * fuel_consumption * fuel_price * 2;
    return trip_cost;
}

int main()
{
    setlocale(LC_ALL, ""); // Задает языковой стандарт по умолчанию. Для вывода кириллицы в консоль.
    float dacha_distance, fuel_consumption, fuel_price;

    std::cout << "Расстояние до дачи (в километрах): ";
    std::cin >> dacha_distance;

    std::cout << "Расход топлива на 100 км (в литрах): ";
    std::cin >> fuel_consumption;

    std::cout << "Цена одного литра бензина (в рублях): ";
    std::cin >> fuel_price;

    std::cout << "Стоимость проезда в рублях = " << calculate_trip_cost(dacha_distance, fuel_consumption, fuel_price) << std::endl;
}
