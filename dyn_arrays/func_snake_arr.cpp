//Написать функцию void snakeArray(int** A, int n), которая заполняет массив числами от 1 до n^2 по змейке

#include <iostream>

void snakeArray(int** arr, int n) {
    int num = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i % 2 != 0 and j == n) {
                arr[i][j] = num;
                num += n;
            } else if (i % 2 != 0) {
                arr[i][j] = num;
                num++;
            } else if (i % 2 == 0 and j == n) {
                arr[i][j] = num;
                num += n;
            } else if (i % 2 == 0) {
                arr[i][j] = num;
                num--;
            }
        }
    }
}
int main() {
    int n;
    std::cout << "enter n: ";
    std::cin >> n;
    int** arr = new int*[n];
    for (int i = 1; i <= n; ++i)
        arr[i] = new int[n];
    snakeArray(arr, n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            std::cout << arr[i][j] << ' ';
        std::cout << '\n';
    }
    for (int i = 1; i <= n; ++i)
        delete[] arr[i];
    delete[] arr;
}

