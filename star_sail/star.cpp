#include <iostream>
#include <cmath>

int main() {
    const double pi = 3.14;
    double x, y, f, p;
    std::cout << "enter coordinates: ";
    std::cin >> x >> y;
    f = sqrt(pow(x, 2) + pow(y, 2));
    p = 5 * (cos((2 * pow(sin(1), -1) + 3 * pi) / 10) / cos((2 * pow(sin(cos(pi * asin(y / f))), -1) + 3 * pi) / 10));
    if (f <= p || ((x == 0) && (y == 0)))
        std::cout << "dot at home";
    else
        std::cout << "missed";
}

