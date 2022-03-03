//Задача 2. Посчитать вещественные корни квадратного уравнения ax^2+bx+c=0.
//На вход подаются коэффициенты a, b, c. Постараться учесть все возможные варианты значений коэффициентов.

#include <iostream>
#include <cmath>

int main() {
    double a, b, c;
    std::cout << "enter a, b, c: ";
    std::cin >> a >> b >> c;
    if (a != 0) {
        double D = sqrt(pow(b, 2) - 4 * a * c);
        if (D == 0) {
            std::cout << "solution: " << -b / 2 * a << '\n';
        } else if (D > 0) {
            std::cout << "solution: " << (-b + D) / 2 * a << ',' << (-b - D) / 2 * a << '\n';
        } else
            std::cout << "no solution in the set of real numbers\n";
    } else {
        std::cout << -c / b << '\n';
    }
}