//Перевести заданное пользователем число (целое, положительнео) в 16-ю систему счисления и вывести на экран.

#include <iostream>

int main() {
    int num;
    std::cout << "enter num: ";
    std::cin >> num;
    int temp_num = num;
    int deg = 1;
    while ((temp_num /= 16) != 0)
        deg *= 16;
    while (deg) {
        if (num / deg > 9)
            std::cout << static_cast<char>(55 + num / deg);
        else
            std::cout << num / deg;
        num %= deg;
        deg /= 16;
    }
}
