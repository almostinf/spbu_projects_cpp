//Схема Горнера.
//Коэффициенты многочлена находятся в массиве A размерности (N+1), где N -- степень многочлена.
//Вычислить значение этого многочлена в точке x, то есть A[N]x^N + ... + A[1]x + A[0], используя схему Горнера.

#include <iostream>

int main() {
    int n;
    std::cout << "enter n: ";
    std::cin >> n;
    auto* factor = new double[n];
    std::cout << "enter factors: ";
    for (int i = 0; i < n; ++i)
        std::cin >> factor[i];
    double sum = factor[0];
    int x;
    std::cout << "enter x: ";
    std::cin >> x;
    //first method
    int temp_x = x;
    for (int i = 1; i <= n - 1; ++i) {
        sum += factor[i] * temp_x;
        temp_x *= temp_x;
    }
    //second method
    double s = factor[n - 1];
    s = factor[n - 2] + s * x;
    for (int i = 3; i <= n; ++i)
        s = factor[n - i] + s * x;
    std::cout << sum << ' ' << s << '\n';
    delete[] factor;
}

