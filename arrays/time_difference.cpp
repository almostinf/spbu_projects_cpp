//Заданы моменты начала и конца некоторого промежутка времени в часах, минутах и секундах (в пределах одних суток).
//Найти продолжительность этого промежутка в тех же единицах.

#include <iostream>

int main() {
    int s1, m1, h1, time1;
    int s2, m2, h2, time2;
    std::cout << "enter s1, m1, h1: ";
    std::cin >> s1 >> m1 >> h1;
    std::cout << "enter s2, m2, h2: ";
    std::cin >> s2 >> m2 >> h2;
    time1 = h1 * 60 * 60 + m1 * 60 + s1;
    time2 = h2 * 60 * 60 + m2 * 60 + s2;
    int dif_time = time2 - time1;
    int dif_time_h = dif_time / 3600;
    dif_time %= 3600;
    int dif_time_m = dif_time / 60;
    dif_time %= 60;
    std::cout << dif_time_h << ':' << dif_time_m << ':' << dif_time<< '\n';
}

