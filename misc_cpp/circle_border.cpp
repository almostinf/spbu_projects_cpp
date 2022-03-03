//Задача 7. Дана окружность с целочисленным радиусом R<10^6.
//Посчитать число точек с целочисленными координатами, лежащих внутри окружности,
//в том числе и находящихся на границе окружности.

#include <iostream>
#include <cmath>
#include <set>


int main() {
    int r;
    std::cout << "enter r: ";
    try {
        std::cin >> r;
        if (r > pow(10, 6))
            throw std::out_of_range("out of range\n");
    } catch (const std::exception& ex) {
        std::cerr << ex.what();
        exit(1);
    }
    long long int count = 0;
    for (int x = 0; x <= 2 * r; ++x) {
        for (int y = 0; y <= 2 * r; ++y) {
            if (((x - r) * (x - r) + (y - r) * (y - r)) <= r * r)
                count++;
        }
    }
    std::cout << "number of dots: " << count << '\n';
}


