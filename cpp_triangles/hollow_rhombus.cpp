//Задача 6. Вывести полый ромб из зведочек.
//Высоту половины ромба задает пользователь.
//
//  *
// * *
//*   *
// * *
//  *

#include <iostream>


int main() {
    int n;
    std::cout << "enter n: ";
    std::cin >> n;
    int tabs = n - 1;
    for (int i = 1; i <= n; ++i) {
        int outside_tabs = tabs;
        int inside_tabs = (i > 2) ? (2 * i - 3) : (i - 1);
        int zvezdi = i;
        while (outside_tabs) {
            std::cout << ' ';
            outside_tabs--;
        }
        std::cout << '*';
        zvezdi--;
        while (inside_tabs) {
            std::cout << ' ';
            inside_tabs--;
        }
        if (zvezdi)
            std::cout << '*';

        tabs--;
        std::cout << '\n';
    }
    tabs = 1;
    for (int i = n - 1; i >= 1; --i) {
        int outside_tabs = tabs;
        int inside_tabs = (i > 2) ? (2 * i - 3) : (i - 1);
        int zvezdi = i;
        while (outside_tabs) {
            std::cout << ' ';
            outside_tabs--;
        }
        std::cout << '*';
        zvezdi--;
        while (inside_tabs) {
            std::cout << ' ';
            inside_tabs--;
        }
        if (zvezdi)
            std::cout << '*';
        tabs++;
        std::cout << '\n';
    }
}

