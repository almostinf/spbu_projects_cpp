//Преобразовать десятичное число, введенное пользователем, в 16-ю систему счисления, записав результат в виде строки.
//
//Преобразовать строку с 16-ым числом, введенным пользователем, в 10-ю систему счисления и вывести на экран результат.

#include <iostream>


int main() {
    int num;
    int n = 10;
    auto* nums = new char[n];
    for (int i = 0; i < n; ++i)
        nums[i] = 0;
    std::cout << "enter num: ";
    std::cin >> num;
    int deg = 1;
    int temp_num = num;
    while ((temp_num /= 16) != 0)
        deg *= 16;
    int count = 0;
    while (deg) {
        if (num / deg <= 9) {
            nums[count] = static_cast<char>(48 + num / deg);
            count++;
        }
        else {
            nums[count] = static_cast<char>(55 + num / deg);
            count++;
        }
        num %= deg;
        deg /= 16;
    }
    nums[count] = 0;
    std::cout << nums << '\n';
    delete[] nums;
}

