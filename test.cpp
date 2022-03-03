#include <iostream>
//#include "gtest/gtest.h"


int main() {
    char num[4]{0};
    num[0] = '1';
    num[1] = '0';
    for (int i = 0; i < 4; ++i)
        std::cout << num[i] << ' ';
    //std::cin.getline(num, sizeof(num));
    std::cout << atoi(num) << '\n';
}

