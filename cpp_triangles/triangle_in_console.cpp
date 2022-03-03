//Задача 2. Вывести равнобедренный треугольник из звездочек. Высоту задает пользователь.
//
//*
//***
//*****
//*******

#include <iostream>


int main() {
    size_t n;
    std::cout << "enter n: ";
    std::cin >> n;
    int tabs = 1;
    for (size_t i = 1; i <= 2 * n - 1; i += 2) {
        int temp_tabs = 0;
        while (temp_tabs != n - tabs)
        {
            std::cout << ' ';
            temp_tabs++;
        }
        size_t zvezdi = i;
        while (zvezdi)
        {
            std::cout << '*';
            zvezdi--;
        }
        std::cout << '\n';
        tabs++;
    }
}

