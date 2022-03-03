#include <iostream>
#include <cmath>


bool first_quarter(double x, double y) {
    return (x >= 0 and y >= 0 and y <= -2 * (x - 1));
}

bool second_quarter(double x, double y) {
    return (x <= 0 and y >= 0 and y <= 2 * (x + 1));
}

bool third_quarter(double x, double y) {
    return (x <= 0 and y <= 0 and y >= -sqrt(1 - pow((x + 1),2)));
}

bool fourth_quarter(double x, double y) {
    return (x >= 0 and y <= 0 and y >= -sqrt(1 - pow((x - 1),2)));
}

int main() {
    double x, y;
    std::cout << "enter x, y: ";
    std::cin >> x >> y;
    if (first_quarter(x, y) or second_quarter(x, y) or third_quarter(x, y) or fourth_quarter(x, y))
        std::cout << "est' probitie!!!\n";
    else
        std::cout << "nope\n";
}

