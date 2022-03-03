//Задача 4. Вывести несколько ромбов из звездочек.
//Высоту половины ромба и количество ромбов задает пользователь.
//
//   *      *      *      *
//  ***    ***    ***    ***
// *****  *****  *****  *****
//****************************
// *****  *****  *****  *****
//  ***    ***    ***    ***
//   *      *      *      *

#include <iostream>

int main() {
    int n_rhombus;
    std::cout << "enter count of rhombus: ";
    std::cin >> n_rhombus;
    int n;
    std::cout << "enter count of blocks top side: ";
    std::cin >> n;
    int tabs = n - 1;
    int temp_tabs = tabs;
    for (int i = 1; i <= 2 * n - 1; i += 2) {
        int temp_n_rhombus = n_rhombus;
        int zvezdi = i;
        int temp_zvezdi = zvezdi;
        bool flag = (temp_n_rhombus == 1);
        while (temp_tabs) {
            std::cout << ' ';
            temp_tabs--;
        }
        while (temp_zvezdi) {
            std::cout << '*';
            temp_zvezdi--;
        }
        temp_tabs = 2 * tabs;
        temp_zvezdi = zvezdi;
        if (!flag)
            while (temp_n_rhombus) {
                while (temp_tabs) {
                    std::cout << ' ';
                    temp_tabs--;
                }
                while (temp_zvezdi) {
                    std::cout << '*';
                    temp_zvezdi--;
                }
                temp_tabs = 2 * tabs;
                temp_zvezdi = zvezdi;
                temp_n_rhombus--;
            }
        tabs--;
            temp_tabs = tabs;
            std::cout << '\n';
    }
    tabs = 1;
    temp_tabs = tabs;
    for (int i = 2 * n - 3; i >= 1; i -= 2) {
        int temp_n_rhombus = n_rhombus;
        int zvezdi = i;
        int temp_zvezdi = zvezdi;
        bool flag = (temp_n_rhombus == 1);
        while (temp_tabs) {
            std::cout << ' ';
            temp_tabs--;
        }
        while (temp_zvezdi) {
            std::cout << '*';
            temp_zvezdi--;
        }
        temp_tabs = 2 * tabs;
        temp_zvezdi = zvezdi;
        if (!flag) {
            while (temp_n_rhombus) {
                while (temp_tabs) {
                    std::cout << ' ';
                    temp_tabs--;
                }
                while (temp_zvezdi) {
                    std::cout << '*';
                    temp_zvezdi--;
                }
                temp_tabs = 2 * tabs;
                temp_zvezdi = zvezdi;
                temp_n_rhombus--;
            }
        }
        tabs++;
        temp_tabs = tabs;
        std::cout << '\n';
    }
}