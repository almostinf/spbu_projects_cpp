//Дырка в массиве.
//Массив длины N в случайном порядке заполнен целыми числами из диапазона от 0 до N.
//Каждое число встречается в массиве не более одного раза. Найти отсутствующее число (дырку).
//Сложность алгоритма O(N).
//Использование дополнительной памяти, пропорциональной длине массива, не допускается.

#include <iostream>
#include <random>
#include <algorithm>

int main() {
    int n;
    std::cout << "enter n: ";
    std::cin >> n;
    std::random_device rd;
    std::uniform_int_distribution dist(0, n + 1);
    int* rand_arr = new int[n + 1];
    for (int i = 0; i <= n; ++i)
        rand_arr[i] = i;
    std::shuffle(rand_arr, rand_arr + n + 1, std::mt19937(std::random_device()()));
    int* arr = new int[n];
    for (int i = 0; i < n; ++i)
        arr[i] = rand_arr[i];
    double sum = 1. * n / 2 * (n + 1);
    double sum_arr = 0;
    for (int i = 0; i < n; ++i)
        sum_arr += arr[i];
    std::cout << "numbers: ";
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
    std::cout << "sum and sum array: " << sum << ' ' << sum_arr << '\n';
    std::cout << "lost number: " << sum - sum_arr << '\n';
    delete[] rand_arr;
    delete[] arr;
}