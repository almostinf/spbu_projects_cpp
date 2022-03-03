//Перевести заданное пользователем число (целое, положительнео) в 2-ю систему счисления и вывести на экран.

#include <iostream>

//first method
int main() {
    int num;
    std::cout << "enter num: ";
    std::cin >> num;
    int temp_num = num;
    int deg = 1;
    while ((temp_num /= 2) != 0)
        deg <<= 1;
    std::cout << deg << '\n';
    while (deg) {
        std::cout << num / deg;
        num %= deg;
        deg >>= 1;
    }
}

//second method
//int main() {
//    int num;
//    std::cout << "enter num: ";
//    std::cin >> num;
//    int deg = 1;
//    int temp_num = num;
//    while ((temp_num /= 2) != 0)
//        deg *= 2;
//    int remainder = num;
//    while (deg) {
//        if (remainder - deg >= 0)
//            std::cout << '1';
//        else
//            std::cout << '0';
//        if (remainder - deg >= 0)
//            remainder -= deg;
//        deg /= 2;
//    }
//}

