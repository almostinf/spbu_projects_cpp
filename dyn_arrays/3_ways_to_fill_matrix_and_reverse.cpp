//Добавить к функциям из задач 3, 5 и 8 дополнительный аргумент -- направление заполнения

#include <iostream>

void fill_matrix(int* arr[], int n, int m, bool reverse) {
    if (reverse) {
        int num = 1;
        for (int j = 1; j <= m; ++j) {
            for (int i = 1; i <= n; ++i) {
                if (j % 2 != 0 and i == n) {
                    arr[i][j] = num;
                    num += n;
                } else if (j % 2 != 0) {
                    arr[i][j] = num;
                    num++;
                } else if (j % 2 == 0 and i == n) {
                    arr[i][j] = num;
                    num += n;
                } else if (j % 2 == 0) {
                    arr[i][j] = num;
                    num--;
                }
            }
        }
        std::cout << "snake filled: \n";
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j)
                std::cout << arr[i][j] << ' ';
            std::cout << '\n';
        }
        for (int i = 0; i < n + 2; ++i) {
            for (int j = 0; j < m + 2; ++j) {
                if (i == 0 or j == 0 or i == n + 1 or j == m + 1)
                    arr[i][j] = -2;
                else
                    arr[i][j] = -1;
            }
        }
        int directions = 1;
        num = 1;
        int i = 1;
        int j = 1;
        while (true) {
            if (directions == 1 and arr[i + 1][j] == -1) {
                arr[i][j] = num;
                num++;
                i++;
            } else if (directions == 1) {
                arr[i][j] = num;
                num++;
                j++;
                directions++;
            } else if (directions == 2 and arr[i][j + 1] == -1) {
                arr[i][j] = num;
                num++;
                j++;
            } else if (directions == 2) {
                arr[i][j] = num;
                num++;
                i--;
                directions++;
            } else if (directions == 3 and arr[i - 1][j] == -1) {
                arr[i][j] = num;
                num++;
                i--;
            } else if (directions == 3) {
                arr[i][j] = num;
                num++;
                j--;
                directions++;
            } else if (directions == 4 and arr[i][j - 1] == -1) {
                arr[i][j] = num;
                num++;
                j--;
            } else if (directions == 4) {
                arr[i][j] = num;
                num++;
                i++;
                directions = 1;
            }
            if (num == n * m) {
                arr[i][j]= num;
                break;
            }
        }
        std::cout << "snail filled: \n";
        for (int k = 1; k < n + 1; ++k) {
            for (int l = 1; l < m + 1; ++l)
                std::cout << arr[k][l] << ' ';
            std::cout << '\n';
        }
        for (int l = 0; l < n + 2; ++l) {
            for (int h = 0; h < m + 2; ++h) {
                if (l == 0 or h == 0 or l == n + 1 or h == m + 1)
                    arr[l][h] = -2;
                else
                    arr[l][h] = -1;
            }
        }
        num = 1;
        int k = 1;
        int z = 1;
        int direction = 2;
        arr[k][z] = num;
        num++;
        k++;
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
        std::cout << "zig zag filled: \n";
        for (int s = 1; s < n + 1; ++s) {
            for (int p = 1; p < m + 1; ++p)
                std::cout << arr[s][p] << ' ';
            std::cout << '\n';
        }
    } else {
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
        std::cout << "snake filled: \n";
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j)
                std::cout << arr[i][j] << ' ';
            std::cout << '\n';
        }
        for (int i = 0; i < n + 2; ++i) {
            for (int j = 0; j < m + 2; ++j) {
                if (i == 0 or j == 0 or i == n + 1 or j == m + 1)
                    arr[i][j] = -2;
                else
                    arr[i][j] = -1;
            }
        }
        int directions = 1;
        num = 1;
        int i = 1;
        int j = 1;
        while (true) {
            if (directions == 1 and arr[i][j + 1] == -1) {
                arr[i][j] = num;
                num++;
                j++;
            } else if (directions == 1) {
                arr[i][j] = num;
                num++;
                i++;
                directions++;
            } else if (directions == 2 and arr[i + 1][j] == -1) {
                arr[i][j] = num;
                num++;
                i++;
            } else if (directions == 2) {
                arr[i][j] = num;
                num++;
                j--;
                directions++;
            } else if (directions == 3 and arr[i][j - 1] == -1) {
                arr[i][j] = num;
                num++;
                j--;
            } else if (directions == 3) {
                arr[i][j] = num;
                num++;
                i--;
                directions++;
            } else if (directions == 4 and arr[i - 1][j] == -1) {
                arr[i][j] = num;
                num++;
                i--;
            } else if (directions == 4) {
                arr[i][j] = num;
                num++;
                j++;
                directions = 1;
            }
            if (num == n * m) {
                arr[i][j]= num;
                break;
            }
        }
        std::cout << "snail filled: \n";
        for (int k = 1; k < n + 1; ++k) {
            for (int l = 1; l < m + 1; ++l)
                std::cout << arr[k][l] << ' ';
            std::cout << '\n';
        }
        for (int l = 0; l < n + 2; ++l) {
            for (int h = 0; h < m + 2; ++h) {
                if (l == 0 or h == 0 or l == n + 1 or h == m + 1)
                    arr[l][h] = -2;
                else
                    arr[l][h] = -1;
            }
        }
        num = 1;
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
        std::cout << "zig zag filled: \n";
        for (int s = 1; s < n + 1; ++s) {
            for (int p = 1; p < m + 1; ++p)
                std::cout << arr[s][p] << ' ';
            std::cout << '\n';
        }
    }

}
void fill_matrix_advanced(int* arr[], int n, int m, bool reverse) {
    int num = 1;
    if (!reverse) std::swap(m,n);
    for (int j = 1; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (reverse and j % 2 != 0 and i == n) {
                arr[i][j] = num;
                num += n;
            } else if (!reverse and j % 2 != 0 and i == n) {
                arr[j][i] = num;
                num += n;
            } else if (reverse and j % 2 != 0) {
                arr[i][j] = num;
                num++;
            } else if (!reverse and j % 2 != 0) {
                arr[j][i] = num;
                num++;
            } else if (reverse and j % 2 == 0 and i == n) {
                arr[i][j] = num;
                num += n;
            } else if (!reverse and j % 2 == 0 and i == n) {
                arr[j][i] = num;
                num += n;
            } else if (reverse and j % 2 == 0) {
                arr[i][j] = num;
                num--;
            } else if (!reverse and j % 2 == 0) {
                arr[j][i] = num;
                num--;
            }
        }
    }
    if (!reverse) std::swap(m,n);
    reverse = !reverse;
    //if (reverse) std::swap(m,n);
    std::cout << "snake filled: \n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            std::cout << arr[i][j] << ' ';
        std::cout << '\n';
    }
    for (int i = 0; i < n + 2; ++i) {
        for (int j = 0; j < m + 2; ++j) {
            if (i == 0 or j == 0 or i == n + 1 or j == m + 1)
                arr[i][j] = -2;
            else
                arr[i][j] = -1;
        }
    }
    int directions = 1;
    num = 1;
    int i = 1;
    int j = 1;
    while (true) {
        if (!reverse and directions == 1 and arr[i + 1][j] == -1) {
            arr[i][j] = num;
            num++;
            i++;
        } else if (reverse and directions == 1 and arr[i][j + 1] == -1) {
            arr[i][j] = num;
            num++;
            j++;
        } else if (!reverse and directions == 1) {
            arr[i][j] = num;
            num++;
            j++;
            directions++;
        } else if (reverse and directions == 1) {
            arr[i][j] = num;
            num++;
            i++;
            directions++;
        } else if (!reverse and directions == 2 and arr[i][j + 1] == -1) {
            arr[i][j] = num;
            num++;
            j++;
        } else if (reverse and directions == 2 and arr[i + 1][j] == -1) {
            arr[i][j] = num;
            num++;
            i++;
        } else if (!reverse and directions == 2) {
            arr[i][j] = num;
            num++;
            i--;
            directions++;
        } else if (reverse and directions == 2) {
            arr[i][j] = num;
            num++;
            j--;
            directions++;
        } else if (!reverse and directions == 3 and arr[i - 1][j] == -1) {
            arr[i][j] = num;
            num++;
            i--;
        } else if (reverse and directions == 3 and arr[i][j - 1] == -1) {
            arr[i][j] = num;
            num++;
            j--;
        } else if (!reverse and directions == 3) {
            arr[i][j] = num;
            num++;
            j--;
            directions++;
        } else if (reverse and directions == 3) {
            arr[i][j] = num;
            num++;
            i--;
            directions++;
        } else if (!reverse and directions == 4 and arr[i][j - 1] == -1) {
            arr[i][j] = num;
            num++;
            j--;
        } else if (reverse and directions == 4 and arr[i - 1][j] == -1) {
            arr[i][j] = num;
            num++;
            i--;
        } else if (!reverse and directions == 4) {
            arr[i][j] = num;
            num++;
            i++;
            directions = 1;
        } else if (reverse and directions == 4) {
            arr[i][j] = num;
            num++;
            j++;
            directions = 1;
        }
        if (num == n * m) {
            arr[i][j]= num;
            break;
        }
    }
    std::cout << "snail filled: \n";
    for (int k = 1; k < n + 1; ++k) {
        for (int l = 1; l < m + 1; ++l)
            std::cout << arr[k][l] << ' ';
        std::cout << '\n';
    }
    for (int l = 0; l < n + 2; ++l) {
        for (int h = 0; h < m + 2; ++h) {
            if (l == 0 or h == 0 or l == n + 1 or h == m + 1)
                arr[l][h] = -2;
            else
                arr[l][h] = -1;
        }
    }
    num = 1;
    int k = 1;
    int z = 1;
    int direction;
    if (!reverse)
        direction = 2;
    else
        direction = 1;
    arr[k][z] = num;
    num++;
    if (!reverse)
        k++;
    else
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
    std::cout << "zig zag filled: \n";
    for (int s = 1; s < n + 1; ++s) {
        for (int p = 1; p < m + 1; ++p)
            std::cout << arr[s][p] << ' ';
        std::cout << '\n';
    }
}
int main() {
    int n, m;
    std::cout << "enter n, m: ";
    std::cin >> n >> m;
    int** arr = new int*[n + 2];
    for (int i = 0; i < n + 2; ++i)
        arr[i] = new int[m + 2];
    //fill_matrix(arr, n, m, true);
    fill_matrix_advanced(arr, n, m, true);
    for (int i = 0; i < n + 2; ++i)
        delete[] arr[i];
    delete[] arr;
}