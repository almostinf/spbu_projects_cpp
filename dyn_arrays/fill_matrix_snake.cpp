//Заполнить массив nxm (размеры вводит пользователь) числами от 1 до nm по змейке.
//Нечетные строки слева направо, чётные -- в обратном порядке.

#include <iostream>

int main() {
    int n, m;
    std::cout << "enter n, m: ";
    std::cin >> n >> m;
    int **arr = new int*[n];
    for (int i = 1; i <= n; ++i)
        arr[i] = new int[m];
    int num = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i % 2 != 0 and j == m) {
                arr[i][j] = num;
                num += m;
            } else if (i % 2 != 0) {
                arr[i][j] = num;
                num++;
            } else if (i % 2 == 0 and j == m) {
                arr[i][j] = num;
                num += m;
            } else if (i % 2 == 0) {
                arr[i][j] = num;
                num--;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            std::cout << arr[i][j] << ' ';
        std::cout << '\n';
    }
    for (int i = 1; i <= n; ++i)
        delete[] arr[i];
    delete[] arr;
}

