//Заполнить массив nxm (размеры вводит пользователь) числами от 1 до nm зигзагом.

#include <iostream>

int main() {
    int n, m;
    std::cout << "enter n, m: ";
    std::cin >> n >> m;
    int **arr = new int*[n + 2];
    for (int i = 0; i < n + 2; ++i)
        arr[i] = new int[m + 2];
    for (int i = 0; i < n + 2; ++i) {
        for (int j = 0; j < m + 2; ++j) {
            if (i == 0 or j == 0 or i == n + 1 or j == m + 1)
                arr[i][j] = -2;
            else
                arr[i][j] = -1;
        }
    }
    int num = 1;
    int k = 1;
    int z = 1;
    int direction = 1;
    arr[k][z] = num;
    num++;
    z++;
    while (true) {
        if (direction == 1 and arr[k + 1][z - 1] == -1) {
            arr[k][z] = num;
            num++;
            k++;
            z--;
        } else if (direction == 1) {
            arr[k][z] = num;
            num++;
            (arr[k + 1][z] == -1) ? k++ : z++;
            direction++;
        } else if (direction == 2 and arr[k - 1][z + 1] == -1) {
            arr[k][z] = num;
            num++;
            k--;
            z++;
        } else if (direction == 2) {
            arr[k][z] = num;
            num++;
            (arr[k][z + 1] == -1) ? z++ : k++;
            direction = 1;
        }
        if (n * m == num) {
            arr[k][z] = num;
            break;
        }
    }
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < m + 1; ++j)
            std::cout << arr[i][j] << ' ';
        std::cout << '\n';
    }
    for (int i = 0; i < n + 2; ++i)
        delete[] arr[i];
    delete[] arr;
}