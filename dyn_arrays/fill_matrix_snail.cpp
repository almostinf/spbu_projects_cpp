//Заполнить массив nxm (размеры вводит пользователь) числами от 1 до nm по спирали (улитке).

#include <iostream>

// first solution with the borders
int main() {
    int n, m;
    std::cout << "enter n, m: ";
    std::cin >> n >> m;
    int **arr = new int*[n];
    for (int i = 0; i < n; ++i)
        arr[i] = new int[m];
    int directions = 1;
    int num = 1;
    int right = m - 1;
    int low = n - 1;
    int left = 0;
    int up = 1;
    int i = 0;
    int j = 0;
    while (true) {
        if (directions == 1 and j < right) {
            arr[i][j] = num;
            num++;
            j++;
        } else if (directions == 1 and j == right) {
            arr[i][j] = num;
            num++;
            i++;
            right--;
            directions++;
        } else if (directions == 2 and i < low) {
            arr[i][j] = num;
            num++;
            i++;
        } else if (directions == 2 and i == low) {
            arr[i][j] = num;
            num++;
            j--;
            low--;
            directions++;
        } else if (directions == 3 and j > left) {
            arr[i][j] = num;
            num++;
            j--;
        } else if (directions == 3 and j == left) {
            arr[i][j] = num;
            num++;
            i--;
            directions++;
            left++;
        } else if (directions == 4 and i > up) {
            arr[i][j] = num;
            num++;
            i--;
        } else if (directions == 4 and i == up) {
            arr[i][j] = num;
            num++;
            j++;
            up++;
            directions = 1;
        }
        if (num == n * m) {
            arr[i][j]= num;
            break;
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int l = 0; l < m; ++l)
            std::cout << arr[k][l] << ' ';
        std::cout << '\n';
    }
    for (int z = 0; z < n; ++z)
        delete[] arr[z];
    delete[] arr;
}
// second solution with checking next number
//int main() {
//    int n, m;
//    std::cout << "enter n, m: ";
//    std::cin >> n >> m;
//    int **arr = new int*[n + 2];
//    for (int i = 0; i < n + 2; ++i)
//        arr[i] = new int[m + 2];
//    int directions = 1;
//    int num = 1;
//    for (int i = 0; i < n + 2; ++i) {
//        for (int j = 0; j < m + 2; ++j) {
//            if (i == 0 or i == n + 1 or j == 0 or j == m + 1)
//                arr[i][j] = -2;
//            else
//                arr[i][j] = -1;
//        }
//    }
//    int i = 1;
//    int j = 1;
//    while (true) {
//        if (directions == 1 and arr[i][j + 1] == -1) {
//            arr[i][j] = num;
//            num++;
//            j++;
//        } else if (directions == 1) {
//            arr[i][j] = num;
//            num++;
//            i++;
//            directions++;
//        } else if (directions == 2 and arr[i + 1][j] == -1) {
//            arr[i][j] = num;
//            num++;
//            i++;
//        } else if (directions == 2) {
//            arr[i][j] = num;
//            num++;
//            j--;
//            directions++;
//        } else if (directions == 3 and arr[i][j - 1] == -1) {
//            arr[i][j] = num;
//            num++;
//            j--;
//        } else if (directions == 3) {
//            arr[i][j] = num;
//            num++;
//            i--;
//            directions++;
//        } else if (directions == 4 and arr[i - 1][j] == -1) {
//            arr[i][j] = num;
//            num++;
//            i--;
//        } else if (directions == 4) {
//            arr[i][j] = num;
//            num++;
//            j++;
//            directions = 1;
//        }
//        if (num == n * m) {
//            arr[i][j]= num;
//            break;
//        }
//    }
//    for (int k = 1; k < n + 1; ++k) {
//        for (int l = 1; l < m + 1; ++l)
//            std::cout << arr[k][l] << ' ';
//        std::cout << '\n';
//    }
//    for (int z = 0; z < n + 2; ++z)
//        delete[] arr[z];
//    delete[] arr;
//}