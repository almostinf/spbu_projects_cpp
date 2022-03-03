//Задача 3. Вывести ромб из зведочек. Высоту половины ромба задает пользователь.
//
//   *
//  ***
// *****
//*******
// *****
//  ***
//   *

#include <iostream>


int main() {
    int n;
    std::cout << "enter n: ";
    std::cin >> n;
    int tabs = 1;
    for (int i = 1; i <= 2 * n - 1; i += 2) {
        int temp_tabs = 0;
        while (temp_tabs != n - tabs)
        {
            std::cout << ' ';
            temp_tabs++;
        }
        int zvezdi = i;
        while (zvezdi) {
            std::cout << '*';
            zvezdi--;
        }
        std::cout << '\n';
        tabs++;
    }

    tabs = n - 1;
    for (int i = 2 * (n - 1) - 1; i >= 1; i -= 2) {
        int temp_tabs = n - tabs;
        int zvezdi = i;
        while (temp_tabs != 0)
        {
            std::cout << ' ';
            temp_tabs--;
        }
        while (zvezdi) {
            std::cout << '*';
            zvezdi--;
        }
        std::cout << '\n';
        tabs--;
    }
}
