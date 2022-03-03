#include <iostream>
#include <cmath>

int main() {
    int n;
    double x;
    std::cout << "enter n, x: ";
    std::cin >> n >> x;
    double s = 0. ;
    double t = sin(x);
    for (int i = 1; i <= n; ++i) {
        s += t;
        t = sin(t);
    }
    std::cout << sin(s) << '\n';
}

