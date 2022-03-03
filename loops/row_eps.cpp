//Написать программу, которая вычисляет число pi с заданной пользователем точностью.
//Под точностью понимается абсолютная величина очередного слагаемого.
//Для вычисления значения числа pi воспользоваться формулой: pi = 4 * (1 - 1/3 + 1/5 - 1/7 + 1/9 - ...)
//Определить какое количество дробей необходимо было добавить к сумме, чтобы обеспечить заданную точность.
//Запомнить кол-во, например в переменной N.

#include <iostream>

int main() {
    double eps;
    std::cout << "enter eps: ";
    std::cin >> eps;
    int count_iteration = 1;
    double s = 1;
    int count = 1;
    double sign = 1.0;
    int i = 3;
    double mult = 1.0;
    double sign_2 = 1.0;
    while (mult * sign >= eps) {
        sign_2 *= -1.0;
        mult = sign_2 * (1. / i);
        s += mult;
        i += 2;
        count_iteration++;
        if (mult < 0.0)
            sign = -1.0;
        else
            sign = 1.0;
    }
    std::cout << s * 4 << ' ' << count_iteration - 1 << '\n';
}
