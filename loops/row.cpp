//Для заданного значения n вычислить выражение: S = 1 + 1/2 + 1/3 + ... +

#include <iostream>

int main() {
    int n;
    std::cout << "enter n: ";
    std::cin >> n;
    double sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += (static_cast<double>(1) / i);
    std::cout << "sum: " << sum << '\n';
}