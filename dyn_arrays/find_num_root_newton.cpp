//Написать функцию нахождения корня из числа с помощью метода Ньютона: double mysqrt(double x, double eps=1e-6)

#include <iostream>
#include <cmath>


double mysqrt(double x, double eps = 1e-6) {
    double approximation = 1;
    double quotient = x;
    double average1 = (x + approximation) / 2;
    approximation = average1;
    quotient = x / approximation;
    double average2 = (approximation + quotient) / 2;
    bool check = true;
    while (fabs(average1 - average2) > eps) {
        if (check) {
            approximation = average2;
            quotient = x / approximation;
            average1 = (approximation + quotient) / 2;
            check = false;
        } else {
            approximation = average1;
            quotient = x / approximation;
            average2 = (approximation + quotient) / 2;
            check = true;
        }
    }
    return average1;
}

int main() {
    std::cout << mysqrt(2) << '\n';
}

