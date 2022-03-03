//Задача 1. Вывести в консоль строку с одной звездочкой, строку с двумя звездочками, с тремя и т.д.
//Количество строк спрашивать у пользователя (не более 25 строк).
//
//*
//**
//***
//****

#include <iostream>
#include <exception>

int main() {
     size_t n;
     std::cout << "enter n: ";
     try {
         std::cin >> n;
         if (n > 25)
             throw std::out_of_range("too much n");
     } catch (const std::out_of_range ex) {
        std::cerr << ex.what() << '\n';
         exit(1);
     }
     for (size_t i = 1; i <= n; ++i) {
         int count = 0;
         while (count != i) {
             std::cout << '*';
             count++;
         }
         std::cout << '\n';
     }
}

