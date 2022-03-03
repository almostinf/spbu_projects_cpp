//Задача 5. Вывести клетчатый ромб из зведочек.
//Высоту половины ромба задает пользователь.
//
//   *
//  * *
// * * *
//* * * *
// * * *
//  * *
//   *

#include <iostream>


 int main() {
     int n;
     std::cout << "enter n: ";
     std::cin >> n;
     int tabs = n - 1;
     for (int i = 1; i <= n; ++i) {
         int zvezdi = i;
         int temp_tabs = tabs;
         while (temp_tabs)
         {
             std::cout << ' ';
             temp_tabs--;
         }
         while (zvezdi)
         {
             std::cout << '*' << ' ';
             zvezdi--;
         }
         tabs--;
         std::cout << '\n';
     }
     tabs = 1;
     for (int i = n - 1; i >= 1; --i) {
         int zvezdi = i;
         int temp_tabs = tabs;
         while (temp_tabs)
         {
             std::cout << ' ';
             temp_tabs--;
         }
         while (zvezdi)
         {
             std::cout << '*' << ' ';
             zvezdi--;
         }
         tabs++;
         std::cout << '\n';
     }
 }

