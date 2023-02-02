#include <iostream>
#include <vector>
#include <climits>

#include "long_operations.h"

std::string long_bin_to_dec(std::string s_longBinary)
{
    std::string result = "";
    std::string power = "1";

    for (int i = s_longBinary.length() - 1; i > -1; i--)
    {
        if (s_longBinary[i] == '1')
            result = long_sum(result, power);
        power = long_multiply(power, "2");
    }

    return result;
}

std::string long_sum(std::string s_bigNum1, std::string s_bigNum2)
{
    if (!s_bigNum1.length())
        return s_bigNum2;

    if (!s_bigNum2.length())
        return s_bigNum1;

    if (s_bigNum1.length() > s_bigNum2.length())
        swap(s_bigNum1, s_bigNum2);

    std::string result = "";

    reverse(s_bigNum1.begin(), s_bigNum1.end());
    reverse(s_bigNum2.begin(), s_bigNum2.end());

    int carry = 0; // результат итерации с учетом сдвига разряда при сложении в обратном порядке
    for (int i = 0; i < s_bigNum1.length(); i++)
    {
        int sum = ((s_bigNum1[i] - '0') + (s_bigNum2[i] - '0') + carry);
        result.push_back(sum % 10 + '0');

        carry = sum / 10;
    }

    for (int i = s_bigNum1.length(); i < s_bigNum2.length(); i++)
    {
        int sum = ((s_bigNum2[i] - '0') + carry);
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    if (carry)
        result.push_back(carry + '0');

    reverse(result.begin(), result.end());

    return result;
}

std::string long_multiply(std::string num1, std::string num2)
{
    std::vector<int> result(num1.size() + num2.size(), 0);

    int index_one = 0;
    int index_two;

    for (int i = num1.size() - 1; i >= 0; i--)
    {
        int carry = 0; // результат итерации с учетом сдвига разряда при умножении в обратном порядке
        int n1 = num1[i] - '0';

        index_two = 0;

        for (int j = num2.size() - 1; j >= 0; j--)
        {
            int n2 = num2[j] - '0';

            // умножаем на текущую цифру первого числа и добавляем результат к ранее сохраненному результату итерации
            int sum = n1 * n2 + result[index_one + index_two] + carry;

            carry = sum / 10;

            result[index_one + index_two] = sum % 10;

            index_two++;
        }

        if (carry > 0)
            result[index_one + index_two] += carry;

        index_one++;
    }

    // убираем лишние нули справа
    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0)
        i--;

    std::string s = "";

    while (i >= 0)
        s += std::to_string(result[i--]);

    return s;
}
