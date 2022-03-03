//Вычислить сумму и произведение цифр целого числа, введенного пользователем.

#include <iostream>

int main() {
    int num;
    std::cout << "enter num: ";
    std::cin >> num;
    int sum = 0;
    int mult = 1;
    while (num > 0) {
        sum += (num % 10);
        mult *= (num % 10);
        num /= 10;
    }
    std::cout << "sum, mult: " << sum << ' ' << mult << '\n';
}

